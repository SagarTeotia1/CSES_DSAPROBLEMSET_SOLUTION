#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj_rev, condensed_adj;
vector<int> coins, scc_coins, scc;
vector<bool> visited;
stack<int> order;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push(u);
}

void dfs2(int u, int scc_id) {
    visited[u] = true;
    scc[u] = scc_id;
    scc_coins[scc_id] += coins[u];
    for (int v : adj_rev[u]) {
        if (!visited[v]) dfs2(v, scc_id);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    adj_rev.resize(n + 1);
    condensed_adj.resize(n + 1);
    coins.resize(n + 1);
    scc_coins.resize(n + 1, 0);
    scc.resize(n + 1, -1);
    visited.resize(n + 1, false);
    
    for (int i = 1; i <= n; ++i) {
        cin >> coins[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    
    // Step 1: Find the finishing order (DFS on the original graph)
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs1(i);
    }
    
    // Step 2: Find SCCs (DFS on the reversed graph)
    fill(visited.begin(), visited.end(), false);
    int scc_id = 0;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!visited[u]) {
            dfs2(u, scc_id++);
        }
    }
    
    // Step 3: Build the condensed graph
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) {
                condensed_adj[scc[u]].push_back(scc[v]);
            }
        }
    }
    
    // Step 4: Dynamic Programming on the condensed graph
    vector<long long> dp(scc_id, 0);
    long long max_coins = 0;
    
    for (int u = 0; u < scc_id; ++u) {
        dp[u] += scc_coins[u];
        max_coins = max(max_coins, dp[u]);
        for (int v : condensed_adj[u]) {
            dp[v] = max(dp[v], dp[u]);
        }
    }
    
    cout << max_coins << endl;
    
    return 0;
}
