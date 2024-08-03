#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string input;
    cin >> input;

    unordered_map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }

    int oddCount = 0;
    char oddChar;
    for (auto &entry : freq) {
        if (entry.second % 2 != 0) {
            oddCount++;
            oddChar = entry.first;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string firstHalf = "", secondHalf = "", middle = "";
    for (auto &entry : freq) {
        string temp(entry.second / 2, entry.first);
        firstHalf += temp;
        secondHalf = temp + secondHalf;
    }

    if (oddCount == 1) {
        middle = oddChar;
    }

    cout << firstHalf + middle + secondHalf << endl;
    return 0;
}
