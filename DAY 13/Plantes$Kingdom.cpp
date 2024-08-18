#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN], adj_rev[MAXN];
bool visited[MAXN];
stack<int> order;
vector<int> scc[MAXN];
int component[MAXN];
int n, m;

void dfs1(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next])
            dfs1(next);
    }
    order.push(node);
}

void dfs2(int node, int comp) {
    component[node] = comp;
    scc[comp].push_back(node);
    for (int next : adj_rev[node]) {
        if (component[next] == -1)
            dfs2(next, comp);
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    
    // First pass: Order vertices by finish time
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs1(i);
    }
    
    // Second pass: Reverse the graph and find SCCs
    memset(component, -1, sizeof(component));
    int k = 0;  // Count of SCCs
    while (!order.empty()) {
        int node = order.top();
        order.pop();
        if (component[node] == -1) {
            dfs2(node, k++);
        }
    }
    
    // Output the results
    cout << k << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << component[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
