#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1,  0,  1, 1, 1, 0, -1, -1};

bool isValidCell(const vector<string> &dictionary, vector<vector<string>> &board, string current, int n, int x, int y) {
    int size = current.length();

    if(x < 0 || y < 0 || x >= n || y >= n || board[x][y] == "_"){
        return false;
    }
    string next = current + board[x][y];

    for(int i = 0; i < dictionary.size(); i++){
        if(dictionary[i].substr(0, next.size()) == next){
            return true;
        }
    }

    return false;
}

bool isValidWord (const vector<string> dictionary, string word, vector<string> &sols){
        for(int i = 0; i < sols.size(); i++){
        if(sols[i] == word){
            return false;
        }
    }

    if(word.size() >= 3){
        for(int i = 0; i < dictionary.size(); i++){
            if(dictionary[i] == word){
                return true;
            }
        }
    }
    return false;
}

void BoggleSolver (vector<vector<string>> &board, const vector<string> &dictionary, int n, int row, int column, string current, vector<string> &sols) {
    if(isValidWord(dictionary, current, sols)){
        sols.push_back(current);
    }

    for(int i = 0; i < 8; i++) {
        int x = row + dx[i];
        int y = column + dy[i];

        if(isValidCell(dictionary, board, current, n, x, y)){
            string temp = board[x][y];
            string next = current + temp;
            board[x][y] = "_";
            BoggleSolver(board, dictionary, n, x, y, next, sols);
            board[x][y] = temp;
        }
    }
}

void BoggleSolverSolve(vector<vector<string>> &board, const vector<string> &dictionary, int n, vector<string> &sols) {
    for(int i = 0; i < n * n; i++) {
        int row = i / n;
        int column = i % n;
        string temp = board[row][column];
        board[row][column] = "_";
        BoggleSolver(board, dictionary, n, row, column, temp, sols);
        board[row][column] = temp;
    }
}