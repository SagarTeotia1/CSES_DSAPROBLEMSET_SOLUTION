#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = -1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    vector<int> dp(n + 1, INF);
    vector<int> parent(n + 1, -1);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    
    // Topological sort using Kahn's algorithm
    queue<int> q;
    dp[1] = 1;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (dp[n] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dp[n] << endl;
        stack<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push(v);
        }
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
    
    return 0;
}
