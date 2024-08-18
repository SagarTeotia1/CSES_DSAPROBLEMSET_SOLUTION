#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN], adj_rev[MAXN];
bool visited[MAXN];
int n, m;

void dfs(int node, vector<int> adj[]) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next])
            dfs(next, adj);
    }
}

bool check_strongly_connected() {
    // Step 1: DFS on the original graph
    memset(visited, false, sizeof(visited));
    dfs(1, adj);
    
    // Check if all nodes are visited
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            return false;
    }
    
    // Step 2: DFS on the reversed graph
    memset(visited, false, sizeof(visited));
    dfs(1, adj_rev);
    
    // Check if all nodes are visited
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            return false;
    }
    
    return true;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    
    if (check_strongly_connected()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        
        // Find and print any pair of unreachable nodes
        memset(visited, false, sizeof(visited));
        dfs(1, adj);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                cout << 1 << " " << i << "\n";
                return 0;
            }
        }
        
        memset(visited, false, sizeof(visited));
        dfs(1, adj_rev);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                cout << i << " " << 1 << "\n";
                return 0;
            }
        }
    }
    
    return 0;
}
