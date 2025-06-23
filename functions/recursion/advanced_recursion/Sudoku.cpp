#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isValidValue (vector<vector<int>> & board, int row, int column, int val, int n) {
    for(int i = 0; i < n; i++) {
        if(board[i][column] == val) return false;
        if(board[row][i] == val) return false;

        int k = static_cast<int>(sqrt(n));
        int boxRow = (row/k) * k + i/k;
        int boxCol = (column/k) * k + i%k;
        if(board[boxRow][boxCol] == val) return false;
    }
    return true;
}

bool solveSudoku (vector<vector<int>> & board, int n){
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            if(board[row][column] == 0){
                for(int val = 1; val <= n; val++){
                    if(isValidValue(board, row, column, val, n)){
                        board[row][column] = val;
                        if(solveSudoku(board, n)) return true;
                        board[row][column] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printBoard(vector<vector<int>> &board) {
    for (auto &row : board) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {
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

    if (solveSudoku(board, 9)) {
        printBoard(board);
    } else {
        cout << "No solution found." << endl;
    }
}
