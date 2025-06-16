#include <iostream>

using namespace std;

int fibonachi (int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonachi(n - 1) + fibonachi(n - 2);
}

int gcd (int a, int b){
    if(b == 0) return a;

    return gcd(b, a % b);
}

void towerOfHanoi (int n, char source, char helper, char destination) {
    if(n == 1){
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, helper);

    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    towerOfHanoi(n - 1, helper, source, destination);
}

string decimalToBinary (int num) {
    if (num == 0) {
        return "0";
    }
    if (num == 1)
        return "1";

    return decimalToBinary(num / 2) + to_string(num % 2);
}

void replaceCharacters (char *str, char letter, char replace){
    if(*str == '\0'){
        return;
    }
    if(*str == letter){
        str[0] = replace;
    }
    replaceCharacters(str + 1, letter, replace);
}
