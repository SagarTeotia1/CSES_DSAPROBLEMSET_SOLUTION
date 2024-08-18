#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int MAXM = 200000;

vector<int> adj[MAXN + 1], path;
vector<int> in_degree(MAXN + 1), out_degree(MAXN + 1);
stack<int> curr_path;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        out_degree[a]++;
        in_degree[b]++;
    }

    int start = 1, end = n;
    bool possible = (out_degree[start] - in_degree[start] == 1) &&
                    (in_degree[end] - out_degree[end] == 1);

    for (int i = 2; i < n; ++i) {
        if (out_degree[i] != in_degree[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dfs(start);

    if (path.size() == m + 1 && path.back() == n) {
        reverse(path.begin(), path.end());
        for (int u : path) cout << u << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
