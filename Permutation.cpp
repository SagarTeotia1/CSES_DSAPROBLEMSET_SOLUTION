#include <iostream>
#include <vector>
using namespace std;

void printBeautifulPermutation(long long n) {
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    vector<long long> result;

    if (n % 2 == 0) {

        for (long long i = 2; i <= n; i += 2) result.push_back(i);

        for (long long i = 1; i <= n; i += 2) result.push_back(i);
    } else {

        for (long long i = 1; i <= n; i += 2) result.push_back(i);

        for (long long i = 2; i <= n; i += 2) result.push_back(i);
    }

    for (long long i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    long long n;
    cin >> n;
    printBeautifulPermutation(n);
    return 0;
}
