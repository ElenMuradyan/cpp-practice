#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string capitalize (string str){
        if (str.empty()) {
        return ""; 
    };

    str[0] = toupper(str[0]);
    int index = str.find(' ');

    if(index == string::npos){
        return str;
    }else{
        return str.substr(0, index + 1) + capitalize(str.substr(index + 1));
    }
}

string reverseStr (string str){
    if(str.empty()){
        return "";
    };

    if(str.length() == 1){
        return str;
    }else{
        return str[str.length() - 1] + reverseStr(str.substr(0, str.length() - 1));
    }
}

string replaceOccurrences (string str){
    if(str.empty()){
        return "";
    };
    const int index = str.find(" ");

    if(index != string::npos){
        string firstPart = str.substr(0, index);
        string lastPart = str.substr(index + 1, str.length() -1);

        return firstPart + "-" + replaceOccurrences(lastPart);
    }else{
        return str;
    }
}

void generateStringPermutations (string str, int start, int end, vector<string> &result) {
    if(start == end){
        result.push_back(str);
        return;
    }

    for(int i = start; i <= end; i++){
        swap(str[start], str[i]);
        generateStringPermutations (str, start + 1, end, result);
        swap(str[start], str[i]);
    }
}