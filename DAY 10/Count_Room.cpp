#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;
int n, m;
vector<string> grid;
bool visited[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0}; // Directions for up, down, left, right
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int countRooms() {
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }
    return rooms;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    cout << countRooms() << endl;
    return 0;
}
