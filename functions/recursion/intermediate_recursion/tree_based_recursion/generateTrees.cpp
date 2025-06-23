int generateTrees (int num){
    if(num <= 1){
        return 1;
    }

    int sum = 0;
    for(int i = 0; i < num; i++){
        sum += generateTrees(i) * generateTrees(num - 1 - i);
    }

    return sum;
}