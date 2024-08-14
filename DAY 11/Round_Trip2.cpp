#include <iostream>
#include <vector>
#include <algorithm>  // For std::reverse

using namespace std;

vector<int> adj[100001];
vector<int> visited(100001, 0);
vector<int> parent(100001, -1);
int cycleStart = -1, cycleEnd = -1;  // Renamed from `start` and `end`

bool dfs(int v) {
    visited[v] = 1;  // Mark the node as currently visiting

    for (int u : adj[v]) {
        if (visited[u] == 0) {  // Node u is unvisited
            parent[u] = v;
            if (dfs(u)) {
                return true;
            }
        } else if (visited[u] == 1) {  // Node u is in the current recursion stack (cycle detected)
            cycleStart = u;
            cycleEnd = v;
            return true;
        }
    }

    visited[v] = 2;  // Mark the node as fully visited
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 && dfs(i)) {
            break;
        }
    }

    if (cycleStart == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycleStart);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
