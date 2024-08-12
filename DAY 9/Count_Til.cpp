#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<int> valid_masks;
int dp[1001][1024];

bool is_valid(int mask) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            if (count % 2 != 0) return false;
            count = 0;
        } else {
            count++;
        }
    }
    return count % 2 == 0;
}

void find_valid_masks(int col_mask, int curr_row) {
    if (curr_row == n) {
        valid_masks.push_back(col_mask);
        return;
    }

    // Place a vertical tile or leave the cell empty
    find_valid_masks(col_mask, curr_row + 1);

    // Place a horizontal tile if possible
    if (curr_row + 1 < n && !(col_mask & (1 << curr_row)) && !(col_mask & (1 << (curr_row + 1)))) {
        find_valid_masks(col_mask | (1 << curr_row) | (1 << (curr_row + 1)), curr_row + 2);
    }
}

int main() {
    cin >> n >> m;

    if (n > m) swap(n, m);

    find_valid_masks(0, 0);

    dp[0][0] = 1;  // Base case: zero columns, one way to fill (the empty grid)

    for (int col = 1; col <= m; ++col) {
        for (int mask : valid_masks) {
            dp[col][mask] = 0;  // Initialize dp[col][mask]
            for (int prev_mask : valid_masks) {
                if ((mask & prev_mask) == 0) {  // Check if masks are compatible
                    dp[col][mask] = (dp[col][mask] + dp[col - 1][prev_mask]) % MOD;
                }
            }
        }
    }

    cout << dp[m][0] << endl;
    return 0;
}
