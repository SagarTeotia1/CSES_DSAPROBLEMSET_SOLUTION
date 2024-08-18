#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> circuit;
vector<int> edge_count;
stack<int> curr_path;

void findEulerianCircuit(int u) {
    while (edge_count[u] > 0) {
        int v = adj[u].back();
        adj[u].pop_back();
        edge_count[u]--;
        edge_count[v]--;
        findEulerianCircuit(v);
    }
    circuit.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    edge_count.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge_count[a]++;
        edge_count[b]++;
    }

    // Check if all vertices have an even degree
    for (int i = 1; i <= n; ++i) {
        if (edge_count[i] % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // Start Hierholzer's algorithm from vertex 1
    findEulerianCircuit(1);

    // Check if all edges are visited
    if (circuit.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(circuit.begin(), circuit.end());
        for (int v : circuit) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
