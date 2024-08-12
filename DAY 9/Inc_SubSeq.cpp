#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> dp;
    
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        
        if (it != dp.end()) {
            *it = arr[i];
        } else {
            dp.push_back(arr[i]);
        }
    }
    
    cout << dp.size() << endl;
    
    return 0;
}
