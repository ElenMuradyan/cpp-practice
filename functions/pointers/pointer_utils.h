// pointer_utils.h
#ifndef POINTER_UTILS_H
#define POINTER_UTILS_H

struct MinMax {
    int *max;
    int *min;
};

void swapIntegers(int *a, int *b);
void reverseArray(int arr[], int length, int ind = 0);
int countVowels(const char *str);
MinMax findMaxAndMin(int arr[], int length);
void allocateArray();
int* copyArray(int arr[], int length);
int sumArray(int arr[], int length);
int stringLength(const char *str);
void sortArray(int arr[], int length);
void reverseString(char *str, int end, int start);
void allocate2dArray();

#endif