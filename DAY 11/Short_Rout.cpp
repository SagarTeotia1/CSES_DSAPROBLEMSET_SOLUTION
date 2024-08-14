#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int n, m;
    cin >> n >> m;

    // Adjacency list to store the graph
    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    // Distance vector initialized to infinity
    vector<long long> dist(n + 1, INF);
    dist[1] = 0; // Distance to the source (Syrjälä) is 0

    // Priority queue to process the nodes (min-heap)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 1); // Start with the source node

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u])
            continue;

        // Explore neighbors
        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output the shortest distances from the source to all cities
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
