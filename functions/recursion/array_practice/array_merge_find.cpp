#include <iostream>
#include <string>
#include <map>
#include "array_utilis.h"

using namespace std;

int * mergeArrays (int arr1[], int arr2[], int length1, int length2){
    sortArray(arr1, length1);
    sortArray(arr2, length2);

    int * mergedarray = new int[length1 + length2];

    int a = 0, b = 0, c = 0;

    while(a < length1 && b < length2){
        if(arr1[a] < arr2[b]){
            mergedarray[c++] = arr1[a++];
        }else{
            mergedarray[c++] = arr2[b++];  
        }
    }

    while(a < length1){
        mergedarray[c++] = arr1[a++];
    }

    while(b < length2){
        mergedarray[c++] = arr2[b++];
    }
    return mergedarray;
}

int findMajorityElement(int arr[], int length){
    map<int, int> countElem;

    for(int i = 0; i < length; i++){
        countElem[arr[i]]++;
    }

    for(auto pair : countElem){
        if(pair.second > length/2){
            return pair.first;
        }
    }

    return -1;
}

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