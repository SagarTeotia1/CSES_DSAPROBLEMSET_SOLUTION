#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    unordered_map<long long, int> prefixSumCount;
    long long prefixSum = 0;
    int count = 0;

    // Initialize the map with prefix sum 0 having one occurrence
    prefixSumCount[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];

        // Check if there is a prefix sum that makes the current prefix sum equal to x
        if (prefixSumCount.find(prefixSum - x) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - x];
        }

        // Update the prefix sum frequency
        prefixSumCount[prefixSum]++;
    }

    cout << count << endl;

    return 0;
}
