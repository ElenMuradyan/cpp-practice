#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSafe (vector<vector<string>> &board, int n, int row, int column){
    if(board[row][column] == "K") return false;
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for(int i = 0; i < 8; i++){
        int x = row + dx[i];
        int y = column + dy[i];

        if(x < n && y < n && x >= 0 && y >= 0 && board[x][y] == "K"){
            return false;
        }
    }

    return true;
}

void nKnights (vector<vector<string>> &board, int n, vector<vector<vector<string>>> &solutions, int knightsPlaced = 0, int start = 0) {
    if(knightsPlaced == n){
        solutions.push_back(board);
        return;
    }

    for(int pos = start; pos < n * n; pos++) {
        int row = pos / n;
        int column = pos % n;

        if(isSafe(board, n, row, column)){
            board[row][column] = "K";
            nKnights(board, n, solutions, knightsPlaced + 1, pos + 1);
            board[row][column] = ".";
        }
    }
}
