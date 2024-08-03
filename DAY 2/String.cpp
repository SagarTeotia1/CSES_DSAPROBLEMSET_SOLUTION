#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    // Generate all permutations
    sort(input.begin(), input.end());  // Sort to start with the smallest lexicographic permutation
    set<string> permutations;
    
    do {
        permutations.insert(input);  // Insert permutation into a set to avoid duplicates
    } while (next_permutation(input.begin(), input.end()));
    
    // Output the results
    cout << permutations.size() << endl;  // Print the number of unique permutations
    for (const string& perm : permutations) {
        cout << perm << endl;  // Print each unique permutation
    }
    
    return 0;
}
