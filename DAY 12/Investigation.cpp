#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    
    vector<long long> dist(n + 1, INF);
    vector<int> count(n + 1, 0), minFlights(n + 1, 0), maxFlights(n + 1, 0);
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    count[1] = 1;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            long long newDist = d + w;
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                count[v] = count[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({newDist, v});
            } else if (newDist == dist[v]) {
                count[v] = (count[v] + count[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << count[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
    
    return 0;
}
