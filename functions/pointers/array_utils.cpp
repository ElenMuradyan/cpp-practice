#include <iostream>
#include <map>
using namespace std;

using namespace std;

int sumArray (int arr[], int length){
    int sum = 0;
    int *end = arr + length;

    while (arr < end){
        sum += *arr;
        arr++;
    }
    
    return sum;
}

void sortArray (int arr[], int length){
    if(length <= 1){
        return;
    }

    for(int ind = 0; ind < length - 1; ind++){
        int *arr_0 = arr + ind;
        if(*arr_0 > *(arr_0 + 1)){
            int temp = *arr_0;
            *arr_0 = *(arr_0 + 1);
            *(arr_0 + 1) = temp;
        }
    }
    sortArray(arr, length - 1);
}

struct MinMax {
    int *max;
    int *min;
};

MinMax findMaxAndMin (int arr[], int length){
    MinMax result;
    result.max = &arr[0];
    result.min = &arr[0];

    for(int i = 0; i < length; i++) {
        if(arr[i] > *(result.max)){
            result.max = &arr[i];
        }
        if(arr[i] < *(result.min)){
            result.min = &arr[i];
        }
    }
    return result;
}

int * findDublicates (int arr[], int length, int &outLength){
    map<int, int> countElem;

    for(int i = 0; i < length; i++){
        countElem[arr[i]]++;
    }
    int countOfDublicates = 0;

    for(auto pair : countElem){
        if(pair.second >= 2){
            countOfDublicates++;
        }
    };

    int * dublicates = new int[countOfDublicates];
    outLength = 0;
    for(auto pair : countElem){
        if(pair.second >= 2){
            dublicates[outLength++] = pair.first;
        }
    };
    return dublicates;
}

int * findLongestSubarray (int arr[], int length, int & outLength){
    if (length == 0) {
        outLength = 0;
        return nullptr;
    }

    int start = 0;
    int currentLength = 1;
    int maxLength = 1;
    int maxStart = 0;

    for(int i = 1; i < length; i++){
        if(arr[i] == arr[i - 1] + 1){
            currentLength++;
        }else{
            if(currentLength > maxLength){
                maxLength = currentLength;
                maxStart = start;
            }
            start = i;
            currentLength = 1;
        }
    }

    if(currentLength > maxLength){
        maxLength = currentLength;
        maxStart = start;
    }

    int * subArray = new int[maxLength];

    for(int i = 0; i < maxLength; i++){
        subArray[i] = arr[maxStart + i];
    }
    outLength = maxLength;
    return subArray;
}

int* reverseArray (int arr[], int reversed[], int length, int idx = 0){
    if(length == idx){
        return reversed;
    }

    reversed[idx] = arr[length - 1 - idx];
    return reverseArray(arr, reversed, length, idx + 1);
}
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