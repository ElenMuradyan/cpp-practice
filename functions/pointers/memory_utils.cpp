#include <iostream>
#include <string>

using namespace std;

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
