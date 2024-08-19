#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Board size
const int N = 8;

// Move vectors for the knight
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to check if the move is within the board and unvisited
bool isValid(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Recursive function to perform the knight's tour
bool knightTour(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N) return true;

    // Try all next moves
    for (int k = 0; k < 8; ++k) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];

        if (isValid(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (knightTour(next_x, next_y, movei + 1, board)) {
                return true;
            } else {
                board[next_x][next_y] = -1; // Backtrack
            }
        }
    }

    return false;
}

// Function to solve the Knight's Tour problem
void solveKnightTour(int startX, int startY) {
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Starting position
    board[startX][startY] = 0;

    if (knightTour(startX, startY, 1, board)) {
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    // Adjusting input to 0-indexed
    solveKnightTour(x - 1, y - 1);

    return 0;
}
