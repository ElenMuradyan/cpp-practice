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

void rotateByOne (int arr[], int size){
    for(int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
}

void rotateArrayByIndex (int arr[], int size, int index) {
    if(index == 0){
        return;
    }
    int val = arr[size - 1];

    rotateByOne(arr, size);
    arr[0] = val;
    rotateArrayByIndex(arr, size, index - 1);
}

int removeElement (int arr[], int size, int elem, int i = 0){
    if(i == size){
        return size;
    }

    if(arr[i] == elem){        
        cout << arr[i] << "hi " << elem << endl;

        for(int j = i; j < size - 1; j++){
            arr[j] = arr[j + 1];
        }
        return removeElement(arr, size - 1, elem, i);
    }
    return removeElement(arr, size, elem, i + 1);
}