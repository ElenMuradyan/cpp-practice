#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial (int num){
    if(num <= 1){
        return 1;
    }

    return num * factorial(num - 1);
}

int sumOfNaturalNum (int num){
    if(num <= 1){
        return 1;
    }

    return num + sumOfNaturalNum(num - 1);
}

int power (int n, int pow) {
    if(pow == 0) return 1;

    return n * power(n, pow - 1);
}

void nThStep (int n, int &ways, int way = 0) {
    if(way == n){
        ways++;
        return;
    }
    if(way > n){
        return;
    }

    nThStep(n, ways, way + 1);
    nThStep(n, ways, way + 2);
}

void generateBinary(int n, string current, vector<string> &res) {
    if(current.length() == n){
        res.push_back(current);
        return;
    }
    generateBinary(n, current + "1", res);
    generateBinary(n, current + "0", res);
}