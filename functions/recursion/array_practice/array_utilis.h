#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <string>

std::string maxAndMin(int arr[], int length);
float findAverage(int arr[], int length);
std::string oddAndEven(int arr[], int length);
bool isSorted(int arr[], int length);
bool isSortedRecursion (int arr[], int length);

int* reverseArray(int arr[], int reversed[], int length, int idx = 0);
void rotateArrayByIndex(int arr[], int rotated[], int length, int index);
void sortArray(int arr[], int length);

int* mergeArrays(int arr1[], int arr2[], int length1, int length2);
int findMissingNumber(int arr[], int length);
int findMajorityElement(int arr[], int length);

int* findDublicates(int arr[], int length, int &outLength);
int* findLongestSubarray(int arr[], int length, int &outLength);
bool isPalindrome (int arr[], int start, int end);

int sumOfArray(int arr[], int size);
int subArraySum(int arr[], int length);
int subsequenceSum(int arr[], int length);
int findMaxInArray (int arr[], int size);
int binarySearchRecursive(int arr[], int start, int end, int key);
void rotateByOne (int arr[], int size);
void rotateArrayByIndex (int arr[], int size, int index);
void printArraySubs (int arr[], int size, int i, string output);
int removeElement (int arr[], int size, int elem, int i = 0);
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int i = 0, int j = 0, int k = 0);
#endif