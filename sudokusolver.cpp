#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int value) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == value) {
            return false;
        }
        // Check column
        if (board[i][col] == value) {
            return false;
        }
        // Check 3x3 subgrid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // If cell is empty
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        // Recursive call
                        if (solve(board)) {
                            return true;
                        } else {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false; // If no number can be placed
            }
        }
    }
    return true; // Sudoku is solved
}

void solveSudoku(vector<vector<int>> &sudoku) {
    if (!solve(sudoku)) {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }
}

int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(sudoku);

    cout << "Solved Sudoku:" << endl;
    for (const auto& row : sudoku) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
