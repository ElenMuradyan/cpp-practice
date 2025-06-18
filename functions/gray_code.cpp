#include <iostream>
#include <bitset>
using namespace std;

void grayCode (int n){
    int total = 1 << n;

    for(int i = 0; i < total; i++){
        int num = i ^ (i >> 1);
        cout << bitset<16>(num).to_string().substr(16 - n) << endl;
    }
    return;
}


