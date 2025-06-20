#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sumOfArray(int arr[], int size){
    if(size == 1){
        return arr[0];
    }

    return arr[0] + sumOfArray(arr + 1, size - 1);
}

void subsetSum (vector<int> arr, int num, int index, vector<int> &current, vector<vector<int>> &solutions){
    if(num == 0){
        solutions.push_back(current);
        return;
    }
    if(num < 0 || index == arr.size()) {
        return;
    }
    current.push_back(arr[index]);

    subsetSum(arr, num - arr[index], index + 1, current, solutions);
    current.pop_back();
    subsetSum(arr, num, index + 1, current, solutions);
}
