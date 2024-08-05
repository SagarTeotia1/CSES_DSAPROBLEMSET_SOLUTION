#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    sort(weights.begin(), weights.end());
    
    int i = 0;  // Pointer for lightest child
    int j = n - 1;  // Pointer for heaviest child
    int gondolas = 0;
    
    while (i <= j) {
        if (weights[i] + weights[j] <= x) {
            // Pair the lightest and heaviest child
            ++i;
        }
        // Always move the heaviest child pointer
        --j;
        // Increment gondola count
        ++gondolas;
    }
    
    cout << gondolas << endl;
    return 0;
}
