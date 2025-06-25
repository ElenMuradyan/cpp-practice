#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <string>

using namespace std;

bool KnightsTour(vector<vector<int>> &board, int n, int x, int y, int moveCount);
vector<vector<string>> nQueens(int n);
void RatInAMaze(int n, int x, int y, string path, vector<string> &paths);
bool solveSudoku(vector<vector<int>> &board, int n);
void nKnights (vector<vector<string>> &board, int n, vector<vector<vector<string>>> &solutions, int knightsPlaced = 0, int start = 0);

#endif 