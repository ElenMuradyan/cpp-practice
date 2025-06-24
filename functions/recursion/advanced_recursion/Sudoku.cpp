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