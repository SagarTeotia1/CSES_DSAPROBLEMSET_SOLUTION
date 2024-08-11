#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    vector<int> heights(t);
    int max_n = 0;
    for (int i = 0; i < t; ++i) {
        cin >> heights[i];
        max_n = max(max_n, heights[i]);
    }

    vector<long long> dp0(max_n + 1, 0), dp1(max_n + 1, 0);

    // Base case
    dp0[1] = 1;  // 2x1 block (both cells filled)
    dp1[1] = 1;  // 1x2 block (single cell filled)

    // Fill dp arrays for all heights up to max_n
    for (int n = 2; n <= max_n; ++n) {
        dp0[n] = (2 * dp0[n-1] + dp1[n-1]) % MOD;
        dp1[n] = dp0[n-1] % MOD;
    }

    // Output results for all test cases
    for (int i = 0; i < t; ++i) {
        int n = heights[i];
        cout << (dp0[n] + dp1[n]) % MOD << endl;
    }

    return 0;
}
