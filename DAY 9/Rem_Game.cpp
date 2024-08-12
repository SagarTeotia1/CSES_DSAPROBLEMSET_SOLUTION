#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    // DP table to store the maximum score the current player can achieve
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Fill the DP table
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            long long a = (i + 2 <= j) ? dp[i+2][j] : 0;
            long long b = (i + 1 <= j - 1) ? dp[i+1][j-1] : 0;
            long long c = (i <= j - 2) ? dp[i][j-2] : 0;
            
            dp[i][j] = max(x[i] + min(a, b), x[j] + min(b, c));
        }
    }
    
    // The answer is the maximum score the first player can achieve for the full array
    cout << dp[0][n-1] << endl;
    
    return 0;
}
