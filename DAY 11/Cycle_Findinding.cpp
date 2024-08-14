#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int x = -1;  // Used to store a node involved in a cycle
    dist[1] = 0;

    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto [a, b, c] : edges) {
            if (dist[a] < INF && dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            x = parent[x];
        }

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());

        for (int v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
