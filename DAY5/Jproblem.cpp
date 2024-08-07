#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long n;
    cin >> n;
    
    list<long> children;
    for (long i = 1; i <= n; ++i) {
        children.push_back(i);
    }
    
    auto it = children.begin();
    while (!children.empty()) {
        // Move to the next child
        it++;
        if (it == children.end()) it = children.begin();

        // Print and remove the child
        cout << *it << " ";
        it = children.erase(it);
        if (it == children.end()) it = children.begin();
    }
    cout << endl;

    return 0;
}
