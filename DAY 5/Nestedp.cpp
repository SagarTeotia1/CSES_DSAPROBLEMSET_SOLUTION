#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Range {
    long long x, y;
    int index;
    bool operator<(const Range& other) const {
        if (x == other.x) return y > other.y;
        return x < other.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<Range> ranges(n);

    for (long long i = 0; i < n; ++i) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].index = i;
    }

    // Sort ranges by starting point and by ending point descending if start points are the same
    sort(ranges.begin(), ranges.end());

    vector<int> contains(n, 0), contained(n, 0);

    // To check if a range contains another
    multiset<long long> activeEnds;
    for (const auto& range : ranges) {
        // Check if the current range contains any of the previously seen ranges
        auto it = activeEnds.lower_bound(range.y);
        if (it != activeEnds.end()) contains[range.index] = 1;
        activeEnds.insert(range.y);
    }

    // To check if a range is contained by another
    activeEnds.clear();
    for (auto it = ranges.rbegin(); it != ranges.rend(); ++it) {
        const auto& range = *it;
        // Check if the current range is contained by any of the previously seen ranges
        auto iter = activeEnds.upper_bound(range.y);
        if (iter != activeEnds.begin()) contained[range.index] = 1;
        activeEnds.insert(range.y);
    }

    // Print the results
    for (long long i = 0; i < n; ++i) {
        cout << contains[i] << " ";
    }
    cout << "\n";
    for (long long i = 0; i < n; ++i) {
        cout << contained[i] << " ";
    }
    cout << "\n";

    return 0;
}
