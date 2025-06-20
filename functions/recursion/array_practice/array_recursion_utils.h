#ifndef ARRAY_RECURSION_UTILS_H
#define ARRAY_RECURSION_UTILS_H

#include <string>
#include <vector>

using namespace std;

bool isSortedRecursion(int arr[], int length);
bool isPalindrome(int arr[], int start, int end);
int* reverseArray(int arr[], int reversed[], int length, int idx = 0);
int sumOfArray(int arr[], int size);
int findMaxInArray(int arr[], int size);
int binarySearchRecursive(int arr[], int start, int end, int key);
void printArraySubs(int arr[], int size, int i, string output);
int removeElement(int arr[], int size, int elem, int i = 0);
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int i = 0, int j = 0, int k = 0);
void sortArray(int arr[], int length);
void rotateArrayByIndex(int arr[], int size, int index);
void subsetSum (vector<int> arr, int num, int index, vector<int> &current, vector<vector<int>> &solutions);

#endif