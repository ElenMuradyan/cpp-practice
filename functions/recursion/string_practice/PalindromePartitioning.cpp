#include <iostream>
#include <string>
#include <vector>
#include "string_recursion_utils.h"

using namespace std;

void PalindromePartitioning(string str, int index, vector<string> &current, vector<vector<string>> &solutions){
    if(index == str.size()){
        solutions.push_back(current);
        return;
    }

    for(int i = index; i < str.size(); i++){
        string part = str.substr(index, i - index + 1);
        if(isPolindrome(part)){
            current.push_back(part);
            PalindromePartitioning(str, i + 1, current, solutions);
            current.pop_back();
        }
    }
}