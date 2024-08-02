#include <iostream>
#include <string>

int main() {
    std::string dna;
    std::cin >> dna;
    long long max_length = 1;
    long long current_length = 1;
    char current_char = dna[0];
    for (std::size_t i = 1; i < dna.length(); ++i) {
        if (dna[i] == current_char) {
            ++current_length;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
            }
            current_char = dna[i];
            current_length = 1;
        }
    }

    if (current_length > max_length) {
        max_length = current_length;
    }

    std::cout << max_length << std::endl;

    return 0;
}