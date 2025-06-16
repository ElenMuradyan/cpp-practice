#ifndef BASIC_PROBLEMS_H
#define BASIC_PROBLEMS_H
#include <iostream>
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

#endif 
