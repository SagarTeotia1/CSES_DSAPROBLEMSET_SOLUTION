#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF = 1e18;
int n, m;

struct Edge {
    int u, v;
    long long weight;
};

int main() {
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].weight *= -1;  // Convert to negative to find the max score
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // Bellman-Ford algorithm to find max path
    for (int i = 1; i <= n - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] < INF && dist[edge.v] > dist[edge.u] + edge.weight) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative cycles (which implies max score is infinite)
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] < INF && dist[edge.v] > dist[edge.u] + edge.weight) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                visited[edge.v] = true;
            }
        }
    }

    // Propagate the influence of the cycle
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (const auto& edge : edges) {
            if (edge.u == node && !visited[edge.v]) {
                visited[edge.v] = true;
                q.push(edge.v);
            }
        }
    }

    // If room n is affected by a negative cycle, print -1
    if (visited[n]) {
        cout << "-1\n";
    } else {
        cout << -dist[n] << "\n";  // Convert back to positive score
    }

    return 0;
}
