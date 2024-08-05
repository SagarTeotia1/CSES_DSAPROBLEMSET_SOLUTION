#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // Sort the values
    sort(values.begin(), values.end());

    // Count unique values
    int unique_count = 0;
    for (int i = 0; i < n; ++i) {
        // If it's the first element or different from the previous element
        if (i == 0 || values[i] != values[i - 1]) {
            unique_count++;
        }
    }

    cout << unique_count << endl;

    return 0;
}
