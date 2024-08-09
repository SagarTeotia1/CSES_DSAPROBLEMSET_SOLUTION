#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>  // Include this header for LLONG_MIN

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + x[i - 1];
    }

    multiset<long long> validSums;
    long long maxSum = LLONG_MIN;  // Now LLONG_MIN is defined

    for (int i = a; i <= n; i++) {
        if (i > b) {
            // Remove the prefix sum that is now out of the valid range
            validSums.erase(validSums.find(prefixSum[i - b - 1]));
        }
        // Add the current prefix sum that starts a new subarray in the valid range
        validSums.insert(prefixSum[i - a]);

        // The maximum sum is found by subtracting the smallest valid prefix sum
        maxSum = max(maxSum, prefixSum[i] - *validSums.begin());
    }

    cout << maxSum << endl;

    return 0;
}
