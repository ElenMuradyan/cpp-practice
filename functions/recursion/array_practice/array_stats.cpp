#include <iostream>
#include <string>
using namespace std;

bool isSortedRecursion (int arr[], int length){
    if(length == 0){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }

    return isSortedRecursion(arr + 1, length - 1);
}

int findMaxInArray (int arr[], int size){
    if(size == 1){
        return arr[0];
    }

    int maxval = findMaxInArray(arr + 1, size - 1);

    return arr[0] > maxval ? arr[0] : maxval;
}

bool isPalindrome (int arr[], int start, int end) {
    if(start >= end){
        return true;
    }

    if(arr[start] == arr[end]){
        return isPalindrome(arr, start + 1, end - 1);
    }
    return false;
}