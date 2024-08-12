#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    int total_sum = n * (n + 1) / 2;
    
    // If total_sum is odd, it's impossible to partition it equally
    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int target = total_sum / 2;
    
    // DP array to store the number of ways to achieve a particular sum
    vector<int> dp(target + 1, 0);
    dp[0] = 1;  // There's one way to get a sum of 0 (empty set)
    
    // Fill the DP array
    for (int i = 1; i <= n; ++i) {
        for (int j = target; j >= i; --j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    
    // We divide by 2 because each subset pair is counted twice
    cout << (dp[target] * 500000004LL) % MOD << endl;  // 500000004 is the modular inverse of 2 under MOD 1e9+7
    
    return 0;
}
