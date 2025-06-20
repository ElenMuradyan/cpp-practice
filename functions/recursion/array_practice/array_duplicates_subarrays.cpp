#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int start, int end, int key) {
    if(start > end){
        return -1;
    }

    int mid = ((start + end)/2);

    if(arr[mid] == key){
        return mid;
    }else if(key > arr[mid]){
        return binarySearchRecursive(arr, mid + 1, end, key);
    }else{
        return binarySearchRecursive(arr, start, mid -1, key);
    }
}
void printArraySubs (int arr[], int size, int i, string output) {
    if(i == size){
        cout << "\"" << output << "\"" << endl;
        return; 
    }

    printArraySubs(arr, size, i + 1, output);
    printArraySubs(arr, size, i + 1, output + to_string(arr[i]) + " ");
}
