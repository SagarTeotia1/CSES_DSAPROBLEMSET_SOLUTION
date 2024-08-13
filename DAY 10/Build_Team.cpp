#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];  // Adjacency list for the graph
int team[MAXN + 1];         // Team assignment for each pupil

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;  // Assign the first team

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (team[u] == 0) {  // If u is not yet assigned to a team
                team[u] = 3 - team[v];  // Assign u to the opposite team
                q.push(u);
            } else if (team[u] == team[v]) {
                // If a neighboring pupil is in the same team, it's not possible to divide them into two teams
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {  // If pupil i is not yet assigned to any team
            if (!bfs(i)) {
                possible = false;
                break;
            }
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
