#include <iostream>
#include <vector>
using namespace std;

// Function to find the number in the spiral matrix
long long findNumber(long long y, long long x) {
    long long layer = max(y, x);
    long long base = (layer - 1) * (layer - 1) + 1;

    if (layer % 2 == 0) { // Even layer
        if (x == layer) return base + (y - 1);
        if (y == layer) return base + (2 * (layer - 1)) - (x - 1);
        if (x == 1) return base + (3 * (layer - 1)) - (y - 1);
        return base + (4 * (layer - 1)) - (x - 1);
    } else { // Odd layer
        if (y == layer) return base + (x - 1);
        if (x == layer) return base + (2 * (layer - 1)) - (y - 1);
        if (y == 1) return base + (3 * (layer - 1)) - (x - 1);
        return base + (4 * (layer - 1)) - (y - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;
    vector<long long> results(t);

    for (long long i = 0; i < t; ++i) {
        long long y, x;
        cin >> y >> x;
        results[i] = findNumber(y, x);
    }

    for (long long result : results) {
        cout << result << '\n';
    }

    return 0;
}
