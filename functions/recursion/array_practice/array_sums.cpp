#include <iostream>
#include <string>
using namespace std;

int sumOfArray(int arr[], int size){
    if(size == 1){
        return arr[0];
    }

    return arr[0] + sumOfArray(arr + 1, size - 1);
}