#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Sort the coins
    sort(coins.begin(), coins.end());

    // Initialize the smallest sum that cannot be created
    long long smallest_missing_sum = 1;

    for (int i = 0; i < n; i++) {
        if (coins[i] > smallest_missing_sum) {
            break;
        }
        smallest_missing_sum += coins[i];
    }

    cout << smallest_missing_sum << endl;

    return 0;
}
