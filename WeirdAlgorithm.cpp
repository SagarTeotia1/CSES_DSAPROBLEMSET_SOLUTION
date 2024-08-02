#include <iostream>

void collatzSequence(long long* n) {
    
    std::cout << *n << " ";
    
    while (*n != 1) {
        
        if (*n % 2 == 0) {
            
            *n = *n / 2;
        } else {
            
            *n = 3 * (*n) + 1;
        }
        
      
        std::cout << *n << " ";
    }
    
    std::cout << std::endl;
}

int main() {
    long long n;
    std::cout << "";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Please enter a positive integer." << std::endl;
        return 1; 
    }

    long long* ptr = &n;

    collatzSequence(ptr);
    
    return 0;
}
