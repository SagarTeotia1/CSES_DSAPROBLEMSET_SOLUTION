#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

vector<int> getDigits(ll x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

ll dp[20][10][2];
vector<int> digits;

ll countNumbers(int pos, int prevDigit, bool tight) {
    if (pos == digits.size()) return 1;
    if (dp[pos][prevDigit][tight] != -1) return dp[pos][prevDigit][tight];
    
    int limit = tight ? digits[pos] : 9;
    ll result = 0;
    
    for (int d = 0; d <= limit; d++) {
        if (d != prevDigit) {
            result += countNumbers(pos + 1, d, tight && (d == limit));
        }
    }
    
    return dp[pos][prevDigit][tight] = result;
}

ll solve(ll x) {
    if (x < 0) return 0;
    digits = getDigits(x);
    memset(dp, -1, sizeof(dp));
    return countNumbers(0, -1, 1);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
