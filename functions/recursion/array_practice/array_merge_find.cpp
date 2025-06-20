#include <iostream>
#include <string>
#include <map>
#include "array_recursion_utils.h"

using namespace std;

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int i = 0, int j = 0, int k = 0) {
    if(i == size1 && j < size2){
        while(j < size2){
            merged[k++] = arr2[j++];
        }
        return;
    }else if(j == size2 && i < size1){
        while(i < size1){
            merged[k++] = arr1[i++];
        }
        return;
    }
    
    if(arr1[i] > arr2[j]){
        merged[k] = arr2[j];
        mergeSortedArrays(arr1, size1, arr2, size2, merged, i, j + 1, k + 1);
    }else{
        merged[k] = arr1[i];
        mergeSortedArrays(arr1, size1, arr2, size2, merged, i + 1, j, k + 1);
    }
}