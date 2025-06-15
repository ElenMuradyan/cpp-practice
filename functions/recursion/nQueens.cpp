#include <iostream>
#include <vector>

using namespace std;

bool isSafe (int row, int col, int n, vector<vector<string>> &board) {
    for(int i = 0; i < row; i++){
        if(board[i][col] == "Q"){
            return false;
        }
    }

    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == "Q"){
            return false;
        }
    }

    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == "Q"){
            return false;
        }
    }
    return true;
}

void solve(int row, int n, vector<vector<string>> &board, vector<vector<vector<string>>> &solutions){
    if(row == n){
        solutions.push_back(board);
        return;
    }

    for(int i = 0; i < n; i++){
        if(isSafe(row, i, n, board)){
            board[row][i] = "Q";
            solve(row + 1, n, board, solutions);
            board[row][i] = ".";
        }
    }
}

vector<vector<vector<string>>> nQueens (int n){
    vector<vector<vector<string>>> solutions;
    vector<vector<string>> board(n, vector<string>(n, "."));

    solve(0, n, board, solutions);

    return solutions;
}