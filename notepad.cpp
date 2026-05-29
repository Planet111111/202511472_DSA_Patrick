#include <iostream>
#include <fstream>
#include <string>
#include "notepad.h"

using namespace std;

// Function to create a new file and write text to it
void writeFile(string filename) {
    // Open file in standard output (write) mode. This overwrites existing files.
    ofstream outFile(filename);
    
    if (!outFile) {
        cout << "Error: Could not create the file.\n";
        return;
    }

    cout << "\n--- Writing to " << filename << " ---\n";
    cout << "Enter your text. Type 'END' on a new line and press Enter to save and finish:\n";
    
    string line;
    // Clear the input buffer leftovers before reading lines
    cin.ignore(); 
    
    // Use a while loop to read multiple lines of text
    while (getline(cin, line)) {
        if (line == "END") {
            break; // Stop writing when user types END
        }
        outFile << line << "\n"; // Save the line into the file
    }

    outFile.close(); // Properly close the file
    cout << "File saved successfully.\n";
}

// Function to open a file and display its contents
void readFile(string filename) {
    // Open file in input (read) mode
    ifstream inFile(filename);
    
    // Handle file-not-found situations
    if (!inFile) {
        cout << "\nError: File '" << filename << "' does not exist.\n";
        return;
    }

    cout << "\n--- Displaying Contents of " << filename << " ---\n";
    string line;
    bool isEmpty = true;

    // Read the file line by line until the end of the file (EOF)
    while (getline(inFile, line)) {
        cout << line << "\n";
        isEmpty = false;
    }

    if (isEmpty) {
        cout << "(The file is empty)\n";
    }
    cout << "-----------------------------------\n";

    inFile.close(); // Properly close the file
}

// Function to append new text to an existing file
void appendFile(string filename) {
    // Open the file in append mode (ios::app) to keep old data
    ofstream outFile(filename, ios::app);
    
    if (!outFile) {
        cout << "Error: Could not open the file for appending.\n";
        return;
    }

    cout << "\n--- Appending to " << filename << " ---\n";
    cout << "Enter text to append. Type 'END' on a new line and press Enter to finish:\n";
    
    string line;
    cin.ignore(); // Clear the input buffer leftovers
    
    // Loop to read multiple lines of text
    while (getline(cin, line)) {
        if (line == "END") {
            break; // Stop appending when user types END
        }
        outFile << line << "\n"; // Add new text without deleting old content
    }

    outFile.close(); // Properly close the file
    cout << "Data appended successfully.\n";
}