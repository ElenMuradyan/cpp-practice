#include <iostream>
#include <string>
#include <algorithm>
#include <map>
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

int* reverseArray (int arr[], int reversed[], int length, int idx = 0){
    if(length == idx){
        return reversed;
    }

    reversed[idx] = arr[length - 1 - idx];
    return reverseArray(arr, reversed, length, idx + 1);
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

int findMissingNumber(int arr[], int length){
    for(int i = 1; i < length; i++){
        if(arr[i] != arr[i-1] + 1){
            return arr[i-1] + 1;
        }
    }
    return 0;
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

int main () {
    int arr[] = {9, 4, -7, 9, 0, 5, 2, 3, 4};
    int length = sizeof(arr)/4;
    int outLength = 0;
    cout << subsequenceSum(arr, length) << endl;
    return 0;
}