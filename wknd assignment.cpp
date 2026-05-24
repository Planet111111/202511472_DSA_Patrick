#include <iostream>
using namespace std;

// Function to calculate average
float average(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

int main()
{
    string name;
    int m1, m2, m3;
    char choice;

    do
    {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter 3 marks: ";
        cin >> m1 >> m2 >> m3;

        cout << "Average = " << average(m1, m2, m3) << endl;

        cout << "Add another student? (Y/N): ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');

    return 0;
}