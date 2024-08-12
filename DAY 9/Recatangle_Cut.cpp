#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    // DP table initialized with a large value
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    
    // Base case: square rectangle requires 0 cuts
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                // Horizontal cuts
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                // Vertical cuts
                for (int l = 1; l < j; ++l) {
                    dp[i][j] = min(dp[i][j], dp[i][l] + dp[i][j - l] + 1);
                }
            }
        }
    }
    
    // Output the minimum number of moves
    cout << dp[a][b] << endl;
    
    return 0;
}
