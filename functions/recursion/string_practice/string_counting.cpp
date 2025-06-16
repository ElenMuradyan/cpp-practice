#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countVowels(string str, int count = 0){
    const string vowels = "euioa";
    if (str.empty()) {
        return count; 
    };

    if(vowels.find(str[0]) == string::npos){
        return countVowels(str.substr(1), count);
    }else{
        return countVowels(str.substr(1), count + 1);
    };
}

string countLetters (string str, char letter, int count = 1){
    if (str.empty()) {
        return ""; 
    }

    if(str.length() == 1){
        return letter + to_string(count);
    }

    if(str[1] == letter){
        return countLetters(str.substr(1), letter, count + 1);
    }else{
        string newStr = str.substr(1);
        return letter + to_string(count) + countLetters(newStr, newStr[0]);
    }
}

void printSubsequences(string input, string output, int index){
    if(index == input.length()){
        cout << "\"" << output << "\"" << endl;
        return;
    }

    printSubsequences(input, output, index + 1);
    printSubsequences(input, output + input[index], index + 1);
}