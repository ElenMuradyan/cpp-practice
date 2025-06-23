#ifndef BASIC_RECURSION_PROBLEMS_H
#define BASIC_RECURSION_PROBLEMS_H
#include <iostream>
#include <vector>

using namespace std;

int factorial(int num);
int sumOfNaturalNum(int num);
int power(int n, int pow);

int reverse(int n, int result = 0);
int countDigits(int num);
int sumOfDigits(int num);
int maxDigit(int num);
int countOccurrences(int num, int digit);
int fibonachi (int n);
int gcd (int a, int b);
void towerOfHanoi (int n, char source, char helper, char destination);
string decimalToBinary (int num);
void replaceCharacters (char *str, char letter, char replace);
int sumOfDigits2 (int n, const int &sum);
int productOfDigits (int n, const int &product);
void nThStep (int n, int &ways, int way = 0);
void generateBinary(int n, string current, vector<string> &res);
void nThStep (int n, int &ways, int way = 0);
int squarePower(int num, int power);
int tribonachi(int n);
int josephus(int n, int k);
int C(int n);
int fibonachiMemo (int n, vector<int> &nums);
int CatalanMemo (int n, vector<int> &nums);

#endif 
