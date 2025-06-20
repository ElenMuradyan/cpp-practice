#include <iostream>
#include <string>
#include <algorithm>
#include "string_recursion_utils.h"

using namespace std;
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