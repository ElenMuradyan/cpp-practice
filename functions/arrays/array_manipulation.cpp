void rotateArrayByIndex (int arr[], int rotated[], int length, int index){
    for(int i = 0; i < length; ++i){
        rotated[i] = arr[(i + index) % length];
    }
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