#include <iostream>
#include <string>

using namespace std;

int userMoney = 1000;
string recordBook[100];
int recordNumber = 0;

void showAccountMoney()
{
    cout << "\nCurrent Amount: "
         << userMoney
         << " FRW\n";
}

void saveMoney()
{
    int cashInput;

    cout << "Enter amount to deposit: ";
    cin >> cashInput;

    userMoney += cashInput;

    recordBook[recordNumber] =
    "Added " + to_string(cashInput);

    recordNumber++;

    cout << "Deposit completed.\n";
}

void takeMoney()
{
    int cashOutput;

    cout << "Enter amount to withdraw: ";
    cin >> cashOutput;

    if(cashOutput <= userMoney)
    {
        userMoney -= cashOutput;

        recordBook[recordNumber] =
        "Removed " + to_string(cashOutput);

        recordNumber++;

        cout << "Withdrawal completed.\n";
    }
    else
    {
        cout << "Balance is not enough.\n";
    }
}

void printHistory()
{
    cout << "\nRecent Transactions\n";

    if(recordNumber == 0)
    {
        cout << "No activity available.\n";
    }

    for(int counter = 0;
        counter < recordNumber;
        counter++)
    {
        cout << counter + 1
             << ". "
             << recordBook[counter]
             << endl;
    }
}

bool checkPin()
{
    int enteredCode;
    int remainingTry = 3;

    while(remainingTry > 0)
    {
        cout << "Enter ATM PIN: ";
        cin >> enteredCode;

        if(enteredCode == 4321)
        {
            return true;
        }

        remainingTry--;

        cout
        << "Incorrect PIN. "
        << remainingTry
        << " attempts left.\n";
    }

    return false;
}

int main()
{
    if(!checkPin())
    {
        cout << "Account locked.\n";
        return 0;
    }

    int menuOption;

    do
    {
        cout << "\n===== ATM SERVICE =====\n";
        cout << "1. View Balance\n";
        cout << "2. Deposit Cash\n";
        cout << "3. Withdraw Cash\n";
        cout << "4. Transaction List\n";
        cout << "5. Logout\n";

        cout << "Select option: ";
        cin >> menuOption;

        switch(menuOption)
        {
            case 1:
                showAccountMoney();
                break;

            case 2:
                saveMoney();
                break;

            case 3:
                takeMoney();
                break;

            case 4:
                printHistory();
                break;

            case 5:
                cout
                << "Session ended.\n";
                break;

            default:
                cout
                << "Wrong option.\n";
        }

    }
    while(menuOption != 5);

    return 0;
}