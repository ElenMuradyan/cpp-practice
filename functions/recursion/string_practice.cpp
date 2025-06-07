#include <iostream>
#include <string>
#include <algorithm>

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

string expandString (string str) {
    if (str.empty()) {
        return ""; 
    }

    if(str.length() == 2){
        return string(str[1] - '0', str[0]);
    }
    return expandString(str.substr(0, 2)) + expandString(str.substr(2));
}

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

int main () {
    string word1 = " listEn";
    string word2 = "S ilent";
    cout << areAnagram(word1, word2) << endl;
    return 0;
}