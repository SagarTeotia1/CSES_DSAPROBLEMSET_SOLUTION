#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<vector<long long>> dist(n + 1);
    
    pq.push({0, 1});  // {cost, node}
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u].size() >= k) continue;
        dist[u].push_back(d);

        for (auto [v, w] : adj[u]) {
            pq.push({d + w, v});
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
    cout << "\n";

    return 0;
}
