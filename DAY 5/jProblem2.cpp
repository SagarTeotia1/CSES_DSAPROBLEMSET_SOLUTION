#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<long long> children(n);
    for (long long i = 0; i < n; ++i) {
        children[i] = i + 1;
    }

    vector<bool> removed(n, false); // keep track of removed children
    long long index = 0; // start from the first child
    long long remaining = n; // number of children remaining

    for (long long i = 0; i < n; ++i) {
        // Skip k children that are not removed
        long long count = 0;
        while (count < k) {
            if (!removed[index]) {
                count++;
            }
            index = (index + 1) % n;
        }

        // Move back one step to point to the actual child to remove
        while (removed[index]) {
            index = (index - 1 + n) % n;
        }

        // Remove the child
        cout << children[index] << " ";
        removed[index] = true;
        remaining--;

        // Move to the next child that is not removed
        while (removed[index]) {
            index = (index + 1) % n;
        }
    }

    cout << endl;
    return 0;
}
