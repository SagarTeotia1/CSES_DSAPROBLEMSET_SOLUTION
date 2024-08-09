#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;  // A large value representing infinity

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<int> dp(x + 1, INF);
    dp[0] = 0;  // Base case: No coins are needed to make a sum of 0
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    if (dp[x] == INF) {
        cout << -1 << endl;  // If dp[x] is still INF, the sum x cannot be made with given coins
    } else {
        cout << dp[x] << endl;  // The minimum number of coins needed to make sum x
    }
    
    return 0;
}
