#include <iostream>
using namespace std;

bool isPolindrome (string word) {
    if (word.empty()) {
        return true; 
    }

    if(word.length() == 1){
        return true;
    }else{
    char first = word[0];
    char last = word[word.length() - 1];
    if(first == last){
        return true && isPolindrome(word.substr(1, word.length() - 2));
    }else{
        return false;
    }
    }
}