#include <iostream>
#include <vector>

using namespace std;

void RatInAMaze(int n, int x, int y, string path, vector<string> &paths) {
    if(x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    if(x < n - 1){
        RatInAMaze(n, x + 1, y, path + " r1 ", paths);
    }

    if(y < n - 1){
        RatInAMaze(n, x, y + 1, path + " b1 ", paths);
    }

    if(x < n - 1 && y < n - 1){
        RatInAMaze(n, x + 1, y + 1, path + " d1 ", paths);
    }
}