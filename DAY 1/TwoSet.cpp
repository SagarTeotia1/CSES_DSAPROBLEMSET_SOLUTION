#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    // Calculate the sum of numbers from 1 to n
    long long totalSum = (n * (n + 1)) / 2;
    
    // Check if the total sum is even
    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    
    // Target sum for each subset
    long long target = totalSum / 2;
    
    vector<int> set1, set2;
    
    // Greedily form the first subset
    for (long long i = n; i > 0; --i) {
        if (target >= i) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }
    
    // Print result
    cout << "YES" << endl;
    cout << set1.size() << endl;
    for (int num : set1) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << set2.size() << endl;
    for (int num : set2) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
