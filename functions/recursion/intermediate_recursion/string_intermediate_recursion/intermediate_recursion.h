#ifndef INTERMEDIATE_RECURSION_H
#define INTERMEDIATE_RECURSION_H

#include <vector>
#include <string>

using namespace std;

void BoggleSolverSolve(vector<vector<string>> &board, const vector<string> &dictionary, int n, vector<string> &sols);

bool WordSearchInAGrid(string &word, vector<vector<char>> &board);

#endif