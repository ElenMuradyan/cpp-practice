#include <iostream>
#include <string>
#include <map>
using namespace std;

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
