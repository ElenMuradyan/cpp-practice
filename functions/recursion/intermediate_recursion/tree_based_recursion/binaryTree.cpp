#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void binaryTree(vector<vector<int>> &result, vector<int> inorder, vector<int> preorder, int &preIndex, int level, int inStart, int inEnd) {
    if(inStart > inEnd){
        return;
    }

    int rootVal = preorder[preIndex++];

    if(result.size() <= level){
        result.push_back({});
    }
    result[level].push_back(rootVal);

    auto it = find(inorder.begin(), inorder.end(), rootVal);
    int index = it - inorder.begin();

    binaryTree(result, inorder, preorder, preIndex, level + 1, inStart, index - 1);
    binaryTree(result, inorder, preorder, preIndex, level + 1, index + 1, inEnd);
}