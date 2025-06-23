#ifndef TREE_ALGORITHMS_H
#define TREE_ALGORITHMS_H

#include <vector>

using namespace std;

int generateTrees(int num);

void binaryTree(vector<vector<int>> &result, vector<int> inorder, vector<int> preorder, int &preIndex, int level, int inStart, int inEnd);

#endif