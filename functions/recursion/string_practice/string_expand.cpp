#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string expandString (string str) {
    if (str.empty()) {
        return ""; 
    }

    if(str.length() == 2){
        return string(str[1] - '0', str[0]);
    }
    return expandString(str.substr(0, 2)) + expandString(str.substr(2));
}