#include <iostream>
#include <string>
using namespace std;

string maxAndMin (int arr[], int length){
    int min = arr[0];
    int max = arr[0];

    for (int index = 0; index < length; index++) {
        if(arr[index] > max){
            max = arr[index];
        }
        if(arr[index] < min){
            min = arr[index];
        }
    }
    return "Max:" + to_string(max) + ", Min:" + to_string(min);
}

float findAverage (int arr[], int length){
    float sum = 0;

    for (int index = 0; index < length; index++) {
        sum += arr[index];
    };

    return sum / length;
}

int findMissingNumber(int arr[], int length){
    for(int i = 1; i < length; i++){
        if(arr[i] != arr[i-1] + 1){
            return arr[i-1] + 1;
        }
    }
    return 0;
}

string oddAndEven (int arr[], int length){
    int even = 0;
    int odd = 0;

    for (int index = 0; index < length; index++) {
        if(arr[index] % 2){
            odd++;
        }else{
            even++;
        }
    }
    return "Even:" + to_string(even) + ", Odd:" + to_string(odd);
}

bool isSorted (int arr[], int length){
    for (int index = 0; index < length - 1; index++) {
        if(arr[index] > arr[index + 1]){
            return false;
        }
    }
    return true;
}