#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H
#include <iostream>
#include <string>

using namespace std;

void rotateByOne (int arr[], int size);
void rotateArrayByIndex (int arr[], int size, int index);
int findMajorityElement(int arr[], int length);
string maxAndMin(int arr[], int length);
float findAverage(int arr[], int length);
int findMissingNumber(int arr[], int length);
string oddAndEven(int arr[], int length);
bool isSorted(int arr[], int length);
int subArraySum(int arr[], int length);
int subsequenceSum(int arr[], int length);

#endif