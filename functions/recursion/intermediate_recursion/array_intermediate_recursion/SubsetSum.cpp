#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsetSum (vector<int> &arr, int index, int n, int sum, vector<int> current, vector<vector<vector<int>>> &solutions) {
    if(!solutions[n].empty()){
        return solutions[n];
    }

    if(n == sum){
        solutions[n].push_back(current);
        return solutions[n];
    }

    if(index == arr.size() || sum > n){
        return solutions[n];
    }

    current.push_back(arr[index]);
    subsetSum(arr, index + 1, n, sum + arr[index], current, solutions);
    current.pop_back();
    subsetSum(arr, index + 1, n, sum, current, solutions);
    return solutions[n];
}