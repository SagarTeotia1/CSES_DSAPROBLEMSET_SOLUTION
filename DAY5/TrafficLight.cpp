#include <iostream>
#include <set>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    set<int> positions = {0, x}; // initially, the ends of the street
    multiset<int> lengths = {x}; // initially, the whole length

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        // Find the positions where the new light will split the segment
        auto it = positions.lower_bound(p);
        int right = *it;
        int left = *(--it);

        // Remove the current segment length
        lengths.erase(lengths.find(right - left));
        
        // Insert the new segments created by the new light
        lengths.insert(p - left);
        lengths.insert(right - p);

        // Add the new light position
        positions.insert(p);

        // The longest segment is the maximum element in lengths
        cout << *lengths.rbegin() << " ";
    }
    cout << endl;

    return 0;
}
