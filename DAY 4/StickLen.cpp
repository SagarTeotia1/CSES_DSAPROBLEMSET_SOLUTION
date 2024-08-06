#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Sort the array to find the median
    sort(p.begin(), p.end());

    // Find the median
    long long median = p[n / 2];

    // Calculate the total cost to make all sticks equal to the median length
    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += abs(p[i] - median);
    }

    // Output the result
    cout << total_cost << endl;

    return 0;
}
