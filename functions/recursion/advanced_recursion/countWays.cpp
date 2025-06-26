#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;


int countWays (int n, vector<vector<int>> canDo, int person, vector<int> &tasks) {
    if(person == n) return 1;

    int count = 0;
    for(int task = 0; task < n; task++){
        if(canDo[person][task] == 1 && find(tasks.begin(), tasks.end(), task) == tasks.end()){
            tasks.push_back(task);
            count += countWays(n, canDo, person + 1, tasks);
            tasks.pop_back();
        }
    }
    return count;
}