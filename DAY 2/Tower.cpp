#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve Tower of Hanoi problem and store moves
void towerOfHanoi(int n, int source, int auxiliary, int destination, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({source, destination});
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary, moves);
    
    // Move the nth disk from source to destination
    moves.push_back({source, destination});
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination, moves);
}

int main() {
    int n;
    cin >> n; // Read number of disks
    
    vector<pair<int, int>> moves; // Vector to store the moves
    
    // Solve the Tower of Hanoi problem and store the moves
    towerOfHanoi(n, 1, 2, 3, moves);
    
    // Sort the moves in ascending order
    sort(moves.begin(), moves.end());
    
    // Print the number of moves
    cout << moves.size() << endl;
    
    // Print the moves
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }
    
    return 0;
}
