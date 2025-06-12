#include <iostream>

using namespace std;

int* reverseArray (int arr[], int reversed[], int length, int idx = 0){
    if(length == idx){
        return reversed;
    }

    reversed[idx] = arr[length - 1 - idx];
    return reverseArray(arr, reversed, length, idx + 1);
}

void rotateArrayByIndex (int arr[], int rotated[], int length, int index){
    for(int i = 0; i < length; ++i){
        rotated[i] = arr[(i + index) % length];
    }
}

void sortArray (int arr[], int length){
    if(length <= 1){
        return;
    }

    for (int i = 0; i < length - 1; i++){
        if(arr[i] > arr[i + 1]){
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    sortArray(arr, length - 1);
}
