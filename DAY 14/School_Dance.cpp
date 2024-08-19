#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1001;

vector<int> adj[MAXN];
int match[MAXN], dist[MAXN];
int n, m, k;

bool bfs() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = -1;
        }
    }

    bool found = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            int w = match[v];
            if (w == 0) {
                found = true;
            } else if (dist[w] == -1) {
                dist[w] = dist[u] + 1;
                q.push(w);
            }
        }
    }

    return found;
}

bool dfs(int u) {
    for (int v : adj[u]) {
        int w = match[v];
        if (w == 0 || (dist[w] == dist[u] + 1 && dfs(w))) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int hopcroftKarp() {
    memset(match, 0, sizeof(match));
    int matching = 0;
    while (bfs()) {
        for (int i = 1; i <= n; ++i) {
            if (match[i] == 0 && dfs(i)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b + n); // Girls are offset by n to keep nodes separate
        adj[b + n].push_back(a);
    }

    int maxPairs = hopcroftKarp();
    cout << maxPairs << endl;

    for (int i = 1; i <= n; ++i) {
        if (match[i] != 0) {
            cout << i << " " << match[i] - n << endl;
        }
    }

    return 0;
}
