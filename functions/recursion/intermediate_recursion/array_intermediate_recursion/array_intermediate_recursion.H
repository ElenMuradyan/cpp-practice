#ifndef ARRAY_INTERMEDIATE_RECURSION_H
#define ARRAY_INTERMEDIATE_RECURSION_H

#include <vector>
#include <string>

using namespace std;

vector<vector<int>> subsetSum (vector<int> &arr, int index, int n, int sum, vector<int> current, vector<vector<vector<int>>> &solutions);

#endif