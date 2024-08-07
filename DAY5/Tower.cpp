#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum_number_of_towers(int n, vector<int>& cubes) {
    vector<int> towers;
    for (int cube : cubes) {
        // Find the first tower with a top larger than or equal to the current cube
        auto pos = upper_bound(towers.begin(), towers.end(), cube);
        if (pos != towers.end()) {
            // Replace the top of the found tower with the current cube
            *pos = cube;
        } else {
            // Create a new tower with the current cube
            towers.push_back(cube);
        }
    }
    return towers.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; ++i) {
        cin >> cubes[i];
    }
    cout << minimum_number_of_towers(n, cubes) << endl;
    return 0;
}
