#include <iostream>
#include <string>
#include <algorithm>
#include "string_utils.h"
using namespace std;

bool isPolindrom (string word) {
    if (word.empty()) {
        return true; 
    }

    if(word.length() == 1){
        return true;
    }else{
    char first = word[0];
    char last = word[word.length() - 1];
    if(first == last){
        return true && isPolindrom(word.substr(1, word.length() - 2));
    }else{
        return false;
    }
    }
}

bool isPalindromePointer (char *str, int start, int end) {
    if(end <= start){
        return true;
    }

    if(*(str + start) == *(str + end - 1)){
        return isPalindromePointer(str, start + 1, end - 1);
    }else{
        return false;
    }
}

bool areAnagram (string w1, string w2){
    string word1 = removeSpaces(w1);
    string word2 = removeSpaces(w2);
    if(word1.length() != word2.length()){
        return false;
    }

    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    return word1 == word2;
}