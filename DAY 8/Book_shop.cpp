#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> h(n);  // Prices of the books
    std::vector<int> s(n);  // Number of pages in the books
    
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    
    std::vector<int> dp(x + 1, 0);  // DP array to store max pages for each budget
    
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= h[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    
    std::cout << dp[x] << std::endl;
    
    return 0;
}
