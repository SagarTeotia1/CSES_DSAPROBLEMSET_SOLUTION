#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200001;
const int LOG = 30; // log2(10^9) is slightly less than 30

int n, q;
int t[MAXN];
int jump[MAXN][LOG];

void preprocess() {
    for (int i = 1; i <= n; ++i) {
        jump[i][0] = t[i];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
}

int query(int x, int k) {
    for (int j = 0; j < LOG; ++j) {
        if (k & (1 << j)) {
            x = jump[x][j];
        }
    }
    return x;
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    preprocess();

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << endl;
    }

    return 0;
}
