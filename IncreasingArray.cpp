#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    
    std::vector<long long> arr(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    long long moves = 0;
    for (long long i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    
    std::cout << moves << std::endl;
    
    return 0;
}
