#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];  // Adjacency list
bool visited[MAXN + 1];
vector<int> component;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
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

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            component.push_back(i);
            dfs(i);
        }
    }

    int roads_needed = component.size() - 1;
    cout << roads_needed << endl;

    for (int i = 1; i < component.size(); i++) {
        cout << component[i-1] << " " << component[i] << endl;
    }

    return 0;
}
