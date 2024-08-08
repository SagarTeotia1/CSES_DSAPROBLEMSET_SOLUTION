#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> arr(n);

    // Read input and store with original indices
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1;  // 1-based index
    }

    // Sort the array based on the values
    sort(arr.begin(), arr.end());

    // Iterate through each element and apply two-pointer technique
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long sum = arr[i].first + arr[left].first + arr[right].first;
            if (sum == x) {
                // Found the triplet
                cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << endl;
                return 0;
            } else if (sum < x) {
                ++left;
            } else {
                --right;
            }
        }
    }

    // If no triplet found
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
