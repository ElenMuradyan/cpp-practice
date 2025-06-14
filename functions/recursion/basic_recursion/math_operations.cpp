#include <iostream>
#include <string>

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