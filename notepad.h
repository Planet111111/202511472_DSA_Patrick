#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <string>

// Using standard namespace scope for the string parameters
using namespace std;

// Function prototypes for file operations
void writeFile(string filename);
void readFile(string filename);
void appendFile(string filename);

#endif // NOTEPAD_H