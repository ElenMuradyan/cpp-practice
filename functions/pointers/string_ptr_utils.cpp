#include <iostream>
#include <string>

using namespace std;

int countVowels (const char *str){
    const string vowels = "eioua";
    int count = 0;

    while(*str != '\0'){
        if(vowels.find(tolower(*str)) != string::npos){
            count++;
        }
        str++;
    }
    return count;
}


int stringLength (const char * str){
    int length = 0;

    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
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
