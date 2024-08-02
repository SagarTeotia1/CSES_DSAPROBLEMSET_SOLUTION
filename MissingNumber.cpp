#include <iostream>

int main() {
    int n;
    std::cin >> n;  
    long long expected_sum = static_cast<long long>(n) * (n + 1) / 2;
    long long actual_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int num;
        std::cin >> num;
        actual_sum += num;
    }   
    int missing_number = expected_sum - actual_sum;
    std::cout << missing_number << std::endl;
    return 0;
}
