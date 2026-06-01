#include "LibraryBook.h"

LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    borrowed = false;
}

LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    borrowed = false;
}

LibraryBook::~LibraryBook() {
    cout << "Book Object Destroyed: " << title << endl;
}

int LibraryBook::getBookID() {
    return bookID;
}

string LibraryBook::getTitle() {
    return title;
}

string LibraryBook::getAuthor() {
    return author;
}

string LibraryBook::getBorrowerName() {
    return borrowerName;
}

int LibraryBook::getDaysBorrowed() {
    return daysBorrowed;
}

bool LibraryBook::getBorrowed() {
    return borrowed;
}

void LibraryBook::setBorrowerName(string name) {
    borrowerName = name;
}

void LibraryBook::setDaysBorrowed(int days) {
    daysBorrowed = days;
}

void LibraryBook::setBorrowed(bool status) {
    borrowed = status;
}

void LibraryBook::borrowBook(string borrower, int days) {
    borrowerName = borrower;
    daysBorrowed = days;
    borrowed = true;
}

void LibraryBook::returnBook() {
    borrowerName = "";
    daysBorrowed = 0;
    borrowed = false;
}

void LibraryBook::displayBook() {
    cout << "\nBook ID: " << bookID;
    cout << "\nTitle: " << title;
    cout << "\nAuthor: " << author;

    if (borrowed) {
        cout << "\nBorrower: " << borrowerName;
        cout << "\nDays Borrowed: " << daysBorrowed;
        cout << "\nStatus: Borrowed\n";
    } else {
        cout << "\nStatus: Available\n";
    }
}