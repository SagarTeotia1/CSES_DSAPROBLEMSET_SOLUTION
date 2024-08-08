#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1;  // 1-based index
    }

    // Hash map to store pairs of sums and their indices
    unordered_map<long long, vector<pair<int, int>>> pairSums;

    // Iterate through all pairs to populate the map
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long currentSum = arr[i].first + arr[j].first;
            pairSums[currentSum].emplace_back(i, j);
        }
    }

    // Iterate again to find the quadruplets
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long currentSum = arr[i].first + arr[j].first;
            long long requiredSum = x - currentSum;
            if (pairSums.find(requiredSum) != pairSums.end()) {
                for (const auto& p : pairSums[requiredSum]) {
                    int k = p.first;
                    int l = p.second;
                    if (i != k && i != l && j != k && j != l) {
                        cout << arr[i].second << " " << arr[j].second << " "
                             << arr[k].second << " " << arr[l].second << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
