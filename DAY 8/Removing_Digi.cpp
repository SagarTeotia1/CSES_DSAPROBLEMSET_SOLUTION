#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> dp(n + 1, 1e9);
    dp[0] = 0; // 0 steps needed to reduce 0 to 0
    
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (digit > 0) {
                dp[i] = std::min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    
    std::cout << dp[n] << std::endl;
    
    return 0;
}
