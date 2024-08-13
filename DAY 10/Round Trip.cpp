#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];  // Adjacency list for the graph
vector<int> parent(MAXN + 1, -1);  // To store the parent of each node in DFS
vector<bool> visited(MAXN + 1, false);  // To track visited nodes
int start = -1, cycle_end = -1;  // Renamed end to cycle_end

bool dfs(int v, int p) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (u == p) continue;  // Skip the edge back to the parent
        if (visited[u]) {
            start = u;
            cycle_end = v;  // Updated to use cycle_end
            return true;
        }
        parent[u] = v;
        if (dfs(u, v)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = cycle_end; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
