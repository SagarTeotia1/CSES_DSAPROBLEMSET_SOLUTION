#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200001;
const int LOG = 30;

int n, q;
int t[MAXN];
int jump[MAXN][LOG];
int dist[MAXN][LOG];

void preprocess() {
    for (int i = 1; i <= n; ++i) {
        jump[i][0] = t[i];
        dist[i][0] = 1;
    }

    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n; ++i) {
            jump[i][k] = jump[jump[i][k - 1]][k - 1];
            dist[i][k] = dist[i][k - 1] + dist[jump[i][k - 1]][k - 1];
        }
    }
}

int query(int a, int b) {
    if (a == b) return 0;

    int steps = 0;
    for (int k = LOG - 1; k >= 0; --k) {
        if (jump[a][k] != 0 && jump[a][k] != b) {
            a = jump[a][k];
            steps += dist[a][k];
        }
    }

    a = jump[a][0];
    steps += 1;

    if (a == b) return steps;
    return -1;
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    preprocess();

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }

    return 0;
}
