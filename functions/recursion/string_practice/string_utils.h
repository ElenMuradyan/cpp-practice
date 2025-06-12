#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

bool isPolindrom(std::string word);
bool areAnagram(std::string w1, std::string w2);

std::string capitalize(std::string str);
std::string replaceOccurrences(std::string str);
std::string reverseStr(std::string str);

std::string countLetters(std::string str, char letter, int count = 1);
int countVowels(std::string str, int count = 0);

std::string deleteDublicates(std::string str, char letter);
std::string removeVowels(std::string str);
std::string removeSpaces(std::string str);

std::string expandString(std::string str);

#endif 