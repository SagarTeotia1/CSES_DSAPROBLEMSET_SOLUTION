#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 500;

int capacity[MAXN][MAXN]; // capacity of edges
int parent[MAXN]; // parent array to store augmenting path

// BFS to find the augmenting path in the residual graph
bool bfs(int source, int sink, int n) {
    fill(parent, parent + n, -1);
    parent[source] = source;
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 0; next < n; ++next) {
            if (parent[next] == -1 && capacity[cur][next] > 0) { // valid path
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == sink)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

// Function to compute the maximum flow using Edmonds-Karp
int maxFlow(int source, int sink, int n) {
    int flow = 0, new_flow;

    while (new_flow = bfs(source, sink, n)) {
        flow += new_flow;
        int cur = sink;

        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(capacity, 0, sizeof(capacity));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        capacity[a-1][b-1] += c; // add capacity to the graph
    }

    int source = 0; // computer 1 (index 0)
    int sink = n - 1; // computer n (index n-1)

    cout << maxFlow(source, sink, n) << endl;

    return 0;
}
