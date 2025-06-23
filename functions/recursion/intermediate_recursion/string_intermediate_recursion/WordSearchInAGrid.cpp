#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool search (string &word, vector<vector<char>> &board, int y = 0, int x = 0, int index = 0) {
    if(index == word.size() - 1){
        return true;
    }

    int maxX = board[0].size();
    int maxY = board.size();

    if (y < 0 || y >= maxY || x < 0 || x >= maxX || board[y][x] != word[index]) {
        return false;
    }

    char temp = board[y][x];
    board[y][x] = '#';

    bool found = search(word, board, y, x + 1, index + 1) ||
    search(word, board, y + 1, x, index + 1) ||
    search(word, board, y - 1, x, index + 1) ||
    search(word, board, y, x - 1, index + 1);

    board[y][x] = temp;

    return found;
}


bool WordSearchInAGrid (string &word, vector<vector<char>> &board) {
    int maxX = board[0].size();
    int maxY = board.size();

    for(int i = 0; i < maxY; i++) {
        for(int j = 0; j < maxX; j++){
            if(search(word, board, i, j)){
                return true;
            }
        }
    }
    return false;
}