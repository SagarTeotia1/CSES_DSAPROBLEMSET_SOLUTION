#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // Store 1-based index
    }

    // Sort the array based on the values
    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        long long sum = a[left].first + a[right].first;
        if (sum == x) {
            cout << a[left].second << " " << a[right].second << endl;
            return 0;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
