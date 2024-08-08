#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> result(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = 0;
        } else {
            result[i] = s.top() + 1;  // 1-based index
        }

        s.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
