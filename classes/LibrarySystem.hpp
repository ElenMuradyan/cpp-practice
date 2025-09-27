#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Library;  

class Book {
    private:
        string title;
        string author;
        bool availability;

    public:
        Book(string title, string author, bool availability): title(title), author(author), availability(availability){}
    friend class Library;
};

class Member {
    private:
        int id;
        string name;
        vector<string> borrowedBooks;

    public:
        Member(int id, string name, vector<string> borrowedBooks): id(id), name(name), borrowedBooks(borrowedBooks){}
    friend class Library;
};

class Library {
    private:
        static vector<Member> members;
        static vector<Book> books;

    public:
        void issueBook(Book &book, Member &member){
            if(book.availability == true){
                member.borrowedBooks.push_back(book.title);
                book.availability = false;
            }else{
                cout << "Book not available" << endl;
            }
        }

        static Book createAndAddABook (string title, string author, bool availability) {
            const Book book = Book(title, author, availability);
            books.push_back(book);
            return book;
        }

        static Member addMember(int id, string name, vector<string> borrowedBooks) {
            const Member member = Member(id, name, borrowedBooks);
            members.push_back(member);
            return member;
        }

        void returnBook(Book &book, Member &member){
            if(find(member.borrowedBooks.begin(), member.borrowedBooks.end(), book.title) != member.borrowedBooks.end()){
                member.borrowedBooks.erase(remove(member.borrowedBooks.begin(), member.borrowedBooks.end(), book.title), member.borrowedBooks.end());
                book.availability = true;
            }
        }

        Book* searchBook(string title) {
            for(int i = 0; i < books.size(); i++) {
                if(books[i].title == title && books[i].availability){
                    return &books[i];
                }
            }
            cout << "Book not found." << endl;
            return nullptr;  
        }
};
vector<Book> Library::books;

int main() {
    Library lib;

    const Book book = Library::createAndAddABook("To Kill a Mockingbird", "Harper Lee", true);

    cout << lib.searchBook("To Kill a Mockingbird") << endl;
    return 0;
}