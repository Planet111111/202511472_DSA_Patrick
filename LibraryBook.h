#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <iostream>
using namespace std;

class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool borrowed;

public:
    LibraryBook();
    LibraryBook(int id, string t, string a);

    ~LibraryBook();

    int getBookID();
    string getTitle();
    string getAuthor();
    string getBorrowerName();
    int getDaysBorrowed();
    bool getBorrowed();

    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setBorrowed(bool status);

    void borrowBook(string borrower, int days);
    void returnBook();
    void displayBook();
};

#endif