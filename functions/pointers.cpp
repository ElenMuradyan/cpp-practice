#include <iostream>
#include <string>

using namespace std;

void swapIntegers (int *a, int *b){
    int value = *a;
    *a = *b;
    *b = value;
}

void reverseArray (int arr[], int length, int ind = 0){
    if(length <= 1 || ind == length/2){
        return;
    }

    int *start = &arr[ind];
    int *end = &arr[length - 1 - ind];

    int temp = *start;
    *start = *end;
    *end = temp;
    reverseArray(arr, length, ind + 1);
}

int countVowels (const char *str){
    const string vowels = "eioua";
    int count = 0;

    while(*str != '\0'){
        if(vowels.find(tolower(*str)) != string::npos){
            count++;
        }
        str++;
    }
    return count;
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

void allocateArray () {
    int size;

    cout << "Enter the size of the array." << endl;
    cin >> size;
    int *arr = new int[size];

    cout << "Enter " << size << " elements" << endl;

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "You entered:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}

int* copyArray (int arr[], int length){
    int * copy = new int[length];

    for(int i = 0; i < length; i++) {
        copy[i] = arr[i];
    }
    return copy;
}

int sumArray (int arr[], int length){
    int sum = 0;
    int *end = arr + length;

    while (arr < end){
        sum += *arr;
        arr++;
    }
    
    return sum;
}

int stringLength (const char * str){
    int length = 0;

    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
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

void reverseString (char *str, int end, int start) {
    if(end <= start){
        return;
    }

    char temp = *(str + start);
    *(str + start) = *(str + end - 1);
    *(str + end - 1) = temp;

    reverseString(str, end - 1, start + 1);
}

void allocate2dArray () {
    int sizeOfArray, sizeOfInnerArray;

    cout << "Enter the size of the array." << endl;
    cin >> sizeOfArray;
    cout << "Enter the size of the inner arrays." << endl;
    cin >> sizeOfInnerArray;

    int **arr = new int*[sizeOfArray];

    for(int i = 0; i < sizeOfArray; i++){
        arr[i] = new int[sizeOfInnerArray];
    }

    for(int i = 0; i < sizeOfArray; i++){
        cout << "Enter " << sizeOfInnerArray << " items for array " << i << endl;
        for(int j = 0; j < sizeOfInnerArray; j++) {
                cout << "Enter element " << j << " for array " << i << endl;
                cin >> arr[i][j];
                cout << endl;
        }
    }

    cout << "You entered:\n";

    for(int i = 0; i < sizeOfArray; i++){
        for(int j = 0; j < sizeOfInnerArray; j++) {
        cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < sizeOfArray; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
