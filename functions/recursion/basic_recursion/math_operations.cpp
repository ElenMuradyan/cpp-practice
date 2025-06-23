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

int squarePower (int num, int power){
    if(power == 1){
        return num;
    }

    int half = squarePower(num, power / 2);

    return power % 2 ? half * half * num : half * half; 
}

int josephus (int n, int k) {
    if(n == 1) return 0;

    return (josephus(n - 1, k) + k) % n;
}

int C (int n) {
    if(n <= 1){
        return 1;
    }

    int sum = 0;

    for(int i = 0; i < n ; i++){
        sum = sum + C(i) * C(n - i - 1);
    }

    return sum;
}

int tribonachi (int n) {
    if(n == 3) return 1;
    if(n < 3) return 0;

    return tribonachi(n - 1) + tribonachi(n - 2) + tribonachi(n - 3);
}


int fibonachiMemo (int n, vector<int> &nums) {
    if(n <= 1) return n;
    if(nums[n] != -1) return nums[n];
    nums[n] = fibonachiMemo(n - 1, nums) + fibonachiMemo(n - 2, nums);
    return nums[n];
}

int CatalanMemo (int n, vector<int> &nums) {
    if(n <= 0) return 1;
    if(nums[n] != -1) return nums[n];
    nums[n] = 0;
    for(int i = 0; i < n; i++){
        nums[n] += CatalanMemo(i, nums) * CatalanMemo(n - i - 1, nums);
    }
    return nums[n];
}