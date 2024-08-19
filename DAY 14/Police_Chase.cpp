#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 500;

int capacity[MAXN][MAXN];
int flowPassed[MAXN][MAXN];
int parent[MAXN];
vector<int> adj[MAXN];

// BFS to find an augmenting path
bool bfs(int source, int sink, int n) {
    fill(parent, parent + n, -1);
    parent[source] = source;
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] - flowPassed[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next] - flowPassed[cur][next]);
                if (next == sink) return true;
                q.push({next, new_flow});
            }
        }
    }
    return false;
}

// Function to calculate the maximum flow
int maxFlow(int source, int sink, int n) {
    int total_flow = 0;

    while (bfs(source, sink, n)) {
        int cur_flow = INF;
        int cur = sink;

        while (cur != source) {
            int prev = parent[cur];
            cur_flow = min(cur_flow, capacity[prev][cur] - flowPassed[prev][cur]);
            cur = prev;
        }

        cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            flowPassed[prev][cur] += cur_flow;
            flowPassed[cur][prev] -= cur_flow;
            cur = prev;
        }

        total_flow += cur_flow;
    }

    return total_flow;
}

// Function to find the minimum cut
void minCut(int source, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : adj[node]) {
            if (!visited[next] && capacity[node][next] - flowPassed[node][next] > 0) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    // Print all edges that are part of the minimum cut
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            for (int next : adj[i]) {
                if (!visited[next] && capacity[i][next] > 0) {
                    cout << i + 1 << " " << next + 1 << endl;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        capacity[a][b] += 1;
        capacity[b][a] += 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int source = 0;
    int sink = n - 1;

    maxFlow(source, sink, n);
    minCut(source, n);

    return 0;
}
