#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long find_digit(long long k) {
    long long length = 1; // Start with 1-digit numbers
    long long count = 9;  // There are 9 numbers with 1 digit

    while (k > length * count) {
        k -= length * count; // Move past all numbers of this length
        length++;
        count *= 10; // Increase count for the next length
    }

    // Now k is within the current length segment
    long long start = pow(10, length - 1); // Starting number of current length
    long long number = start + (k - 1) / length; // Exact number containing the k-th digit
    string s = to_string(number); // Convert number to string to access the k-th digit
    return s[(k - 1) % length] - '0'; // Return the specific digit
}

int main() {
    int q;
    cin >> q;
    vector<long long> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < q; ++i) {
        cout << find_digit(queries[i]) << endl;
    }

    return 0;
}
