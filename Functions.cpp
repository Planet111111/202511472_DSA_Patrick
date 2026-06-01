#include "Functions.h"

void addBook(LibraryBook books[], int &count) {
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books[count] = LibraryBook(id, title, author);
    count++;

    cout << "Book Added Successfully.\n";
}

void displayBooks(LibraryBook books[], int count) {
    for(int i = 0; i < count; i++) {
        books[i].displayBook();
    }
}

void searchBook(LibraryBook books[], int count) {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(books[i].getBookID() == id) {
            books[i].displayBook();
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void borrowBookMenu(LibraryBook books[], int count) {
    int id, days;
    string borrower;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    for(int i = 0; i < count; i++) {
        if(books[i].getBookID() == id) {

            if(books[i].getBorrowed()) {
                cout << "Book Already Borrowed.\n";
                return;
            }

            cout << "Borrower Name: ";
            getline(cin, borrower);

            cout << "Days Borrowed: ";
            cin >> days;

            books[i].borrowBook(borrower, days);

            cout << "Book Borrowed Successfully.\n";
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void returnBookMenu(LibraryBook books[], int count) {
    int id;

    cout << "Enter Book ID: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(books[i].getBookID() == id) {
            books[i].returnBook();
            cout << "Book Returned Successfully.\n";
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void displayOverdueBooks(LibraryBook books[], int count) {
    cout << "\nOverdue Books:\n";

    for(int i = 0; i < count; i++) {
        if(books[i].getBorrowed() &&
           books[i].getDaysBorrowed() > 14) {
            books[i].displayBook();
        }
    }
}

void calculateTotalFines(LibraryBook books[], int count) {
    double totalFine = 0;

    for(int i = 0; i < count; i++) {
        if(books[i].getBorrowed() &&
           books[i].getDaysBorrowed() > 14) {

            int overdueDays =
                books[i].getDaysBorrowed() - 14;

            totalFine += overdueDays * 500;
        }
    }

    cout << "Total Fine: "
         << totalFine << " RWF\n";
}