#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 505;

int n, m;
vector<int> adj[MAXN], parent;
int capacity[MAXN][MAXN];

int bfs(int s, int t) {
    parent.assign(n + 1, -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) { 
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int edmondsKarp(int s, int t) {
    int flow = 0, new_flow;
    
    while (new_flow = bfs(s, t)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void findPaths(int s, int t) {
    vector<vector<int>> paths;
    
    while (true) {
        vector<int> path;
        int cur = s;
        while (cur != t) {
            path.push_back(cur);
            for (int next : adj[cur]) {
                if (capacity[cur][next] < capacity[next][cur]) {
                    capacity[cur][next]++;
                    cur = next;
                    break;
                }
            }
            if (cur == path.back()) break;
        }
        if (cur == t) {
            path.push_back(t);
            paths.push_back(path);
        } else break;
    }
    
    cout << paths.size() << endl;
    for (auto &p : paths) {
        cout << p.size() << endl;
        for (int v : p) cout << v << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
        capacity[a][b] = 1;
    }
    
    int maxFlow = edmondsKarp(1, n);
    findPaths(1, n);
    
    return 0;
}
