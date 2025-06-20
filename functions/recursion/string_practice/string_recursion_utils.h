#ifndef RECURSION_UTILS_H
#define RECURSION_UTILS_H

#include <string>
#include <vector>

bool isPolindrome(string word);
bool areAnagram(string w1, string w2);
string capitalize(string str);
string replaceOccurrences(string str);
string reverseStr(string str);
string countLetters(string str, char letter, int count = 1);
int countVowels(string str, int count = 0);
string deleteDublicates (string str, char letter);
string removeVowels(string str);
string removeSpaces(string str);
string expandString(string str);
void printSubsequences(string input, string output, int index);
void generateStringPermutations(string str, int start, int end, vector<string> &result);

#endif 
