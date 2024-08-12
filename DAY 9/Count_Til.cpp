#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int dp[1024][1001]; // dp[mask][column]

int main() {
    int n, m;
    cin >> n >> m;
    
    dp[(1 << n) - 1][0] = 1;  // Initially, we have an empty column
    
    for (int j = 0; j < m; ++j) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask][j] == 0) continue;  // Skip if there's no valid tiling for this state
            
            for (int next_mask = 0; next_mask < (1 << n); ++next_mask) {
                int state = 0;
                
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) continue;
                    
                    if (i + 1 < n && !(mask & (1 << (i + 1))) && !(next_mask & (1 << i)) && !(next_mask & (1 << (i + 1)))) {
                        state |= (1 << i) | (1 << (i + 1));
                        i++;
                    } else if (!(next_mask & (1 << i))) {
                        state |= (1 << i);
                    } else {
                        state = -1;
                        break;
                    }
                }
                
                if (state != -1 && state == next_mask) {
                    dp[next_mask][j + 1] = (dp[next_mask][j + 1] + dp[mask][j]) % MOD;
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][m] << endl;
    
    return 0;
}
