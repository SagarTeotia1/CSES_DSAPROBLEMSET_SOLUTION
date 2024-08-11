#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<std::string> grid(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }
    
    if (grid[0][0] == '*') {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }
    
    // Fill the dp table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    
    std::cout << dp[n-1][n-1] << std::endl;
    
    return 0;
}
