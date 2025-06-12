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