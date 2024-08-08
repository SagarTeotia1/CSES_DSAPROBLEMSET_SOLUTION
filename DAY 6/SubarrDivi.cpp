#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // HashMap to store the frequency of remainders
    unordered_map<int, long long> remainderCount;
    long long prefixSum = 0;
    long long count = 0;

    // Initialize the map with remainder 0 having one occurrence
    remainderCount[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];
        int remainder = ((prefixSum % n) + n) % n; // Handle negative remainders

        // Count the number of subarrays with a sum divisible by n
        if (remainderCount.find(remainder) != remainderCount.end()) {
            count += remainderCount[remainder];
        }

        // Update the remainder frequency
        remainderCount[remainder]++;
    }

    cout << count << endl;

    return 0;
}
