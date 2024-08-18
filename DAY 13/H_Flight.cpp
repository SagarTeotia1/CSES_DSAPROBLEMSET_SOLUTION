#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // DP array
    vector<vector<int>> dp(1 << n, vector<int>(n + 1, 0));

    // Base case: start at city 1 with only city 1 visited
    dp[1][1] = 1;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 1; i <= n; ++i) {
            if (!(mask & (1 << (i - 1)))) continue;
            for (int u : adj[i]) {
                if (mask & (1 << (u - 1))) continue;
                dp[mask | (1 << (u - 1))][u] = (dp[mask | (1 << (u - 1))][u] + dp[mask][i]) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n] << endl;

    return 0;
}
