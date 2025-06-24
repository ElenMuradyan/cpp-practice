#include <iostream>
#include <vector>

using namespace std;

bool isSafe (vector<vector<int>> &board, int n, int x, int y){
    if(x >= n || y >= n || x < 0 || y < 0 || board[y][x] > -1){
        return false;
    }
    return true;
}

bool KnightsTour (vector<vector<int>> &board, int n, int x, int y, int moveCount){
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    if(moveCount == n * n) return true;

    for (int i = 0; i < 8; i++) {
        int moveX = x + dx[i];
        int moveY = y + dy[i];

        if(isSafe(board, n, moveX, moveY)){
            board[moveY][moveX] = moveCount;
            if(KnightsTour(board, n, moveX, moveY, moveCount + 1)) return true;
            board[moveY][moveX] = -1;
        }
    }
    return false;
}