#include <vector>
#include <iostream>
#include <set>
using namespace std;

int BitmaskSubsets (vector<int> arr, int target){
    int n = arr.size();
    int count = 0;

    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1){
                sum += arr[i];
            }
        }
        if(sum == target) count++;
    }
    return count;
}

int countUniqueORs (vector<int> arr) {
    int n = arr.size();
    set<int> orResults;

    for(int mask = 1; mask < (1 << n); mask++) {
        int currentOr = 0;

        for(int i = 0; i < n; i++){
            if((mask >> i) & 1){
                currentOr |= arr[i];
            }
        }
        orResults.insert(currentOr);
    }

    return orResults.size();
}

int subSetSum (vector<int> arr, int target) {
    int n = arr.size();
    int res = 0;

    for(int mask = 1; mask < (1 << n); mask++){
        int xorSum = 0;

        for(int i = 0; i < n; i++){
            if((mask >> i) & 1){
                xorSum ^= arr[i];
            }
        }
        if(xorSum == target){
            res++;
        }
    }
    return res;
}

vector<vector<int>> partitionArray (vector<int> arr) {
    vector<vector<int>> parts;
    int n = arr.size();

    for(int mask = 1; mask < (1 << n) - 1; mask++) {
        int sum0 = 0, sum1 = 0;
        vector<int> part0, part1;

        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1){
                sum1 ^= arr[i];
                part1.push_back(arr[i]);
            }else{
                sum0 ^= arr[i];
                part0.push_back(arr[i]);
            }
        }
        if(sum0 == sum1){
            parts.push_back(part0);
            parts.push_back(part1);
        }
    }
    return parts;
}