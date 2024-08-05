#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(vector<string>& board, vector<int>& queens_positions, int row, int col) {
    for (int r = 0; r < row; ++r) {
        // Check column conflict
        if (queens_positions[r] == col) {
            return false;
        }
        // Check diagonal conflicts
        if (abs(queens_positions[r] - col) == abs(r - row)) {
            return false;
        }
    }
    return true;
}

int place_queen(vector<string>& board, vector<int>& queens_positions, int row) {
    if (row == 8) {
        return 1;
    }

    int count = 0;
    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '.' && is_valid(board, queens_positions, row, col)) {
            queens_positions[row] = col;
            count += place_queen(board, queens_positions, row + 1);
            queens_positions[row] = -1; // backtrack
        }
    }
    return count;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    vector<int> queens_positions(8, -1);
    int result = place_queen(board, queens_positions, 0);

    cout << result << endl;

    return 0;
}
