#include <iostream>
#include <string>
using namespace std;

int subArraySum(int arr[], int length){
    if(length == 0){
        return 0;
    }

    int max = arr[0];
    int sum = 0;

    for(int i = 0; i < length; i++){
        if(arr[i] < 0){
            continue;
        }else{
            sum += arr[i];
            if(arr[i] > max){
                max = arr[i];
            }
        }
    }

    return sum > 0 ? sum : max;
}

int subsequenceSum(int arr[], int length){
    if(length == 0){
        return 0;
    }

    int maxSum = arr[0];
    int currentSum = arr[0];

    for(int i = 1; i < length; i++){
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(currentSum, maxSum);
    }

    return maxSum;
}

