#include <iostream>
#include <string>

using namespace std;

void swapIntegers (int *a, int *b){
    int value = *a;
    *a = *b;
    *b = value;
}

void reverseArray (int arr[], int length, int ind = 0){
    if(length <= 1 || ind == length/2){
        return;
    }

    int *start = &arr[ind];
    int *end = &arr[length - 1 - ind];

    int temp = *start;
    *start = *end;
    *end = temp;
    reverseArray(arr, length, ind + 1);
}

void reverseString (char *str, int end, int start) {
    if(end <= start){
        return;
    }

    char temp = *(str + start);
    *(str + start) = *(str + end - 1);
    *(str + end - 1) = temp;

    reverseString(str, end - 1, start + 1);
}