#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string deleteDublicates (string str, char letter){
    if (str.empty()) {
        return ""; 
    }

    if(str.length() == 1){
        return str;
    }

    if(str[1] == letter){
        return deleteDublicates(str.substr(1), str[0]);
    }else{
        return letter + deleteDublicates(str.substr(1), str[1]);
    }
}


string removeVowels(string str){
    const string vowels = "euioa";
    if (str.empty()) {
        return ""; 
    };
    int index = vowels.find(str[0]);

    if(index == string::npos){
        return str[0] + removeVowels(str.substr(1));
    }else{
        return removeVowels(str.substr(1));
    };
}

string removeSpaces(string str){
    if (str.empty()) {
        return ""; 
    };
    int index = str.find(" ");

    if(index == string::npos){
        return str;
    }else{
        return str.substr(0, index) + removeSpaces(str.substr(index + 1));
    };
}