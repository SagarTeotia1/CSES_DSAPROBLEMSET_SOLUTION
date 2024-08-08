#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> times(n);

    long long total_time = 0;
    int max_time = 0;

    for (int i = 0; i < n; ++i) {
        cin >> times[i];
        total_time += times[i];
        if (times[i] > max_time) {
            max_time = times[i];
        }
    }

    long long result = max(total_time, 2LL * max_time);
    cout << result << endl;

    return 0;
}
