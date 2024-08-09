#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    unordered_map<int, int> freq;
    int left = 0;
    long long result = 0;
    
    for (int right = 0; right < n; right++) {
        freq[x[right]]++;
        
        // If there are more than k distinct values, move the left pointer
        while (freq.size() > k) {
            freq[x[left]]--;
            if (freq[x[left]] == 0) {
                freq.erase(x[left]);
            }
            left++;
        }
        
        // The number of subarrays ending at 'right' with at most k distinct elements
        result += (right - left + 1);
    }
    
    cout << result << endl;
    return 0;
}
