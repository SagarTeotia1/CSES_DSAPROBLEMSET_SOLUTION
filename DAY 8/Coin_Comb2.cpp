#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }
    
    std::vector<int> dp(x + 1, 0);
    dp[0] = 1; // There's one way to make sum 0: using no coins
    
    // Process each coin individually
    for (int j = 0; j < n; ++j) {
        for (int i = coins[j]; i <= x; ++i) {
            dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }
    
    std::cout << dp[x] << std::endl;
    
    return 0;
}
