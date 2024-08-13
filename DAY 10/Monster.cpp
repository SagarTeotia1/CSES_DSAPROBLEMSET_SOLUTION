#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>  // Include this for std::tie

using namespace std;

const int INF = 1e9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'D', 'U', 'R', 'L'};

int n, m;
vector<string> grid;
vector<vector<int>> monsterTime, playerTime;
pair<int, int> start;

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void bfsMonsters() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                monsterTime[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny) && monsterTime[nx][ny] > monsterTime[x][y] + 1) {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfsPlayer() {
    queue<pair<int, int>> q;
    q.push(start);
    playerTime[start.first][start.second] = 0;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            string path;
            while (parent[x][y] != make_pair(-1, -1)) {
                int px = parent[x][y].first, py = parent[x][y].second;
                for (int i = 0; i < 4; ++i) {
                    if (px + dx[i] == x && py + dy[i] == y) {
                        path += dir[i];
                        break;
                    }
                }
                tie(x, y) = parent[x][y];
            }
            reverse(path.begin(), path.end());
            cout << "YES" << endl;
            cout << path.size() << endl;
            cout << path << endl;
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny) && playerTime[nx][ny] > playerTime[x][y] + 1) {
                if (playerTime[x][y] + 1 < monsterTime[nx][ny]) {
                    playerTime[nx][ny] = playerTime[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monsterTime.assign(n, vector<int>(m, INF));
    playerTime.assign(n, vector<int>(m, INF));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    bfsMonsters();

    if (!bfsPlayer()) {
        cout << "NO" << endl;
    }

    return 0;
}
