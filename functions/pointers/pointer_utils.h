#ifndef POINTER_UTILS_H
#define POINTER_UTILS_H

struct MinMax {
    int *max;
    int *min;
};

void swapIntegers(int *a, int *b);
void reverseArray1(int arr[], int length, int ind = 0);
int countVowels(const char *str);
MinMax findMaxAndMin(int arr[], int length);
void allocateArray();
int* copyArray(int arr[], int length);
int sumArray(int arr[], int length);
int stringLength(const char *str);
void sortArray(int arr[], int length);
void reverseString(char *str, int end, int start);
void allocate2dArray();
bool isPalindromePointer (char *str, int start, int end);
int* findDublicates(int arr[], int length, int &outLength);
int* findLongestSubarray(int arr[], int length, int &outLength);
int* mergeArrays(int arr1[], int arr2[], int length1, int length2);
void reverseArray2 (int arr[], int length, int ind = 0){

#endif