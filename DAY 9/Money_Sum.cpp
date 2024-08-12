#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    // Maximum possible sum with given constraints
    const int MAX_SUM = 100000;
    
    // DP table to keep track of possible sums
    vector<bool> dp(MAX_SUM + 1, false);
    dp[0] = true; // Base case: sum of 0 is always achievable
    
    // Process each coin
    for (int i = 0; i < n; ++i) {
        for (int s = MAX_SUM; s >= coins[i]; --s) {
            if (dp[s - coins[i]]) {
                dp[s] = true;
            }
        }
    }
    
    // Collect all possible sums
    set<int> possible_sums;
    for (int s = 1; s <= MAX_SUM; ++s) {
        if (dp[s]) {
            possible_sums.insert(s);
        }
    }
    
    // Output the number of distinct sums and the sums themselves
    cout << possible_sums.size() << endl;
    for (int sum : possible_sums) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}
