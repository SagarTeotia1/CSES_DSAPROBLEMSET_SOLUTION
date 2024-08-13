#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];  // Adjacency list for the graph
int parent[MAXN + 1];       // To store the parent of each node
bool visited[MAXN + 1];     // To check if a node has been visited

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1; // Mark the start node's parent as -1 (no parent)

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }
    }
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

    bfs(1);  // Start BFS from computer 1

    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
