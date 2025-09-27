#include <iostream>
#include <string>

using namespace std;

class Book{
    private:
        string title;
        string author;
        int year;
    public:
        Book(string title, string author): title(title), author(author), year(0) {}
        Book(string title, string author, int year): title(title), author(author), year(year) {}

        void printDetails () {
            cout << "Title: " << title << ", Autor: " << author << ", Year: " << year << endl;
        }
};