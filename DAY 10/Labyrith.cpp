#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAXN = 1000;
int n, m;
vector<string> grid;
pair<int, int> start, end;
int dist[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0}; // Directions for up, down, left, right
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && dist[x][y] == -1;
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (make_pair(x, y) == end) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    return false;
}

string reconstructPath() {
    string path;
    pair<int, int> cur = end;

    while (cur != start) {
        pair<int, int> prev = parent[cur.first][cur.second];
        for (int i = 0; i < 4; i++) {
            if (cur.first == prev.first + dx[i] && cur.second == prev.second + dy[i]) {
                path += dir[i];
                break;
            }
        }
        cur = prev;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    memset(dist, -1, sizeof(dist));

    if (bfs()) {
        cout << "YES" << endl;
        cout << dist[end.first][end.second] << endl;
        cout << reconstructPath() << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
