#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        
        // Check if sum is divisible by 3 and neither pile is more than twice the other
        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
