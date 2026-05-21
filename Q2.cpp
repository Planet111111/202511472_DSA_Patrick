#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void cppBackground()
{
    int pickChoice;

    cout << "\nC++ Background Topics\n";
    cout << "1. Creator of C++\n";
    cout << "2. Development Journey\n";
    cout << "3. Modern Improvements\n";

    cin >> pickChoice;

    switch(pickChoice)
    {
        case 1:
            cout
            << "C++ was introduced "
            << "by Bjarne Stroustrup.\n";
            break;

        case 2:
            cout
            << "C++ extended C language "
            << "by adding object-oriented programming.\n";
            break;

        case 3:
            cout
            << "Modern C++ supports "
            << "smart pointers and lambda expressions.\n";
            break;

        default:
            cout
            << "Topic unavailable.\n";
    }
}

void cppLessons()
{
    int lessonChoice;

    cout << "\nC++ Learning Menu\n";
    cout << "1. Variables\n";
    cout << "2. Decisions\n";
    cout << "3. Repetition Structures\n";
    cout << "4. Arrays\n";
    cout << "5. Open Chapter File\n";

    cin >> lessonChoice;

    switch(lessonChoice)
    {
        case 1:
            cout
            << "Examples: int, float, char and string.\n";
            break;

        case 2:
            cout
            << "Decision statements use if and switch.\n";
            break;

        case 3:
            cout
            << "Loops include for, while and do while.\n";
            break;

        case 4:
            cout
            << "Arrays help store many values.\n";
            break;

        case 5:
        {
            ifstream chapterData(
            "chapter.txt");

            if(chapterData.is_open())
            {
                string textLine;

                while(getline(
                chapterData,
                textLine))
                {
                    cout
                    << textLine
                    << endl;
                }

                chapterData.close();
            }
            else
            {
                cout
                << "Chapter file missing.\n";
            }

            break;
        }

        default:
            cout
            << "Option invalid.\n";
    }
}

int main()
{
    int systemChoice;

    do
    {
        cout
        << "\n===== C++ KNOWLEDGE SYSTEM =====\n";

        cout
        << "1. View C++ Background\n";

        cout
        << "2. Learn C++ Concepts\n";

        cout
        << "3. Exit System\n";

        cin >> systemChoice;

        switch(systemChoice)
        {
            case 1:
                cppBackground();
                break;

            case 2:
                cppLessons();
                break;

            case 3:
                cout
                << "Program terminated.\n";
                break;

            default:
                cout
                << "Input not accepted.\n";
        }

    }
    while(systemChoice != 3);

    return 0;
}