#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canProduceInTime(const vector<long long>& times, long long totalProducts, long long maxTime) {
    long long produced = 0;
    for (long long time : times) {
        produced += maxTime / time;
        if (produced >= totalProducts) return true;
    }
    return produced >= totalProducts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t;
    cin >> n >> t;
    vector<long long> times(n);
    for (long long i = 0; i < n; ++i) {
        cin >> times[i];
    }

    long long left = 1, right = 1e18; // Arbitrarily large upper bound
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canProduceInTime(times, t, mid)) {
            right = mid; // Try for a smaller time
        } else {
            left = mid + 1; // Increase the time
        }
    }

    cout << left << "\n";

    return 0;
}
