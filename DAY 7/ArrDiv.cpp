#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canDivide(const vector<int>& x, int n, int k, long long maxSum) {
    int subarrayCount = 1;
    long long currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentSum + x[i] > maxSum) {
            subarrayCount++;
            currentSum = x[i];
            if (subarrayCount > k) {
                return false;
            }
        } else {
            currentSum += x[i];
        }
    }
    
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    long long left = *max_element(x.begin(), x.end());
    long long right = accumulate(x.begin(), x.end(), 0LL);
    
    long long result = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canDivide(x, n, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    return 0;
}
