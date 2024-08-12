#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    vector<pair<int, int>> dp(1 << n, {INT_MAX, 0});
    dp[0] = {1, 0};  // No people need one ride with zero weight
    
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) continue;  // If person i is already in the subset, skip
            
            int new_mask = mask | (1 << i);
            if (dp[mask].second + w[i] <= x) {
                dp[new_mask] = min(dp[new_mask], {dp[mask].first, dp[mask].second + w[i]});
            } else {
                dp[new_mask] = min(dp[new_mask], {dp[mask].first + 1, w[i]});
            }
        }
    }
    
    cout << dp[(1 << n) - 1].first << endl;
    
    return 0;
}
