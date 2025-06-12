#include <iostream>

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