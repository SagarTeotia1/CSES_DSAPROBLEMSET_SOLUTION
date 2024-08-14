#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
int n, m;

void dijkstra(int start, vector<long long>& dist, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1), rev_adj(n + 1);
    vector<long long> dist_from_start(n + 1, INF), dist_from_end(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        rev_adj[b].emplace_back(a, c);  // Reverse graph for backward dijkstra
    }

    // First, run Dijkstra from Syrjälä (city 1)
    dijkstra(1, dist_from_start, adj);

    // Then, run Dijkstra from Metsälä (city n) on the reverse graph
    dijkstra(n, dist_from_end, rev_adj);

    long long result = INF;
    
    // Evaluate the minimum cost considering using the discount on each edge
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : adj[u]) {
            if (dist_from_start[u] != INF && dist_from_end[v] != INF) {
                result = min(result, dist_from_start[u] + (w / 2) + dist_from_end[v]);
            }
        }
    }

    cout << result << "\n";

    return 0;
}
