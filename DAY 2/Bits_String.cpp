#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int MOD = 1000000007;
    int n;
    cin >> n;
    
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result = (result * 2) % MOD;
    }
    
    cout << result << endl;
    return 0;
}
