#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<long long, pair<int, int>> pairSums;

    // Iterate through all pairs to populate the map
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long currentSum = arr[i].first + arr[j].first;
            if (pairSums.find(x - currentSum) != pairSums.end()) {
                pair<int, int> p = pairSums[x - currentSum];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << arr[i].second << " " << arr[j].second << " " 
                         << arr[p.first].second << " " << arr[p.second].second << endl;
                    return 0;
                }
            }
            pairSums[currentSum] = {i, j};
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
