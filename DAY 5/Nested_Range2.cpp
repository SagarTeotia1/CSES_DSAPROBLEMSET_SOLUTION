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

    vector<long long> containsCount(n, 0), containedByCount(n, 0);

    // To count how many other ranges a range contains
    multiset<long long> activeEnds;
    for (const auto& range : ranges) {
        // Check how many ranges are contained by this range
        auto it = activeEnds.lower_bound(range.y);
        containsCount[range.index] = distance(it, activeEnds.end());
        activeEnds.insert(range.y);
    }

    // To count how many other ranges contain this range
    activeEnds.clear();
    for (auto it = ranges.rbegin(); it != ranges.rend(); ++it) {
        const auto& range = *it;
        // Check how many ranges contain this range
        auto iter = activeEnds.upper_bound(range.y);
        containedByCount[range.index] = distance(activeEnds.begin(), iter);
        activeEnds.insert(range.y);
    }

    // Print the results
    for (long long i = 0; i < n; ++i) {
        cout << containsCount[i] << " ";
    }
    cout << "\n";
    for (long long i = 0; i < n; ++i) {
        cout << containedByCount[i] << " ";
    }
    cout << "\n";

    return 0;
}
