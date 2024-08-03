#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> generateGrayCode(int n) {
    if (n == 0) return { "" }; 

    vector<string> previous = generateGrayCode(n - 1);
    vector<string> result;

    
    for (const string& code : previous) {
        result.push_back("0" + code);
    }

    
    for (auto it = previous.rbegin(); it != previous.rend(); ++it) {
        result.push_back("1" + *it);
    }

    return result;
}

int main() {
    int n;
    cin >> n; vector<string> grayCode = generateGrayCode(n);
    for (const string& code : grayCode) {
        cout << code << endl;
    }

    return 0;
}
