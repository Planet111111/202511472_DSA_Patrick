#include <iostream>
#include <string>
#include "notepad.h"

using namespace std;

int main() {
    int choice;
    string filename;

    // Use a do-while loop to display the menu repeatedly until option 4 is chosen
    do {
        cout << "\n===============================\n";
        cout << "        SIMPLE NOTEPAD         \n";
        cout << "===============================\n";
        cout << "1. Write File\n";
        cout << "2. Read File\n";
        cout << "3. Append File\n";
        cout << "4. Exit\n";
        cout << "-------------------------------\n";
        cout << "Enter choice: ";
        
        // Handle cases where user types a non-integer
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            cin.clear();            // Clear the error flag
            cin.ignore(1000, '\n'); // Discard invalid input line
            continue;
        }

        // Use a switch statement for menu choices
        switch (choice) {
            case 1:
                cout << "Enter filename to create/write (e.g., notes.txt): ";
                cin >> filename;
                writeFile(filename);
                break;

            case 2:
                cout << "Enter filename to read: ";
                cin >> filename;
                readFile(filename);
                break;

            case 3:
                cout << "Enter filename to append to: ";
                cin >> filename;
                appendFile(filename);
                break;

            case 4:
                cout << "\nThank you for using Simple Notepad. Goodbye!\n";
                break;

            default:
                // Handle invalid numerical choices
                cout << "Invalid choice! Please select an option from 1 to 4.\n";
                break;
        }

    } while (choice != 4); // Exit condition

    return 0;
}