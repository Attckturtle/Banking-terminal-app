#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

string enteredUsername;
string enteredPassword;


bool validAccount;

bool makingAccount;
bool isAccountCorrect;
int chosenOption;
bool correctAccount;
int indexOfThing;

vector<string> listOfAccountUsernames;
vector<string> listOfAccountPasswords;
vector<int> listOfDepositedValues;

void showOptions();
void processChosenOption();
void makeAccount();
void depositAnAmount();
void indexOfWantedAccount();
void checkIfCorrectAccount();

int main()
{
    showOptions();
    return 0;
}

void showOptions() {
    cout << "1. New acoount\n";
    cout << "2. Deposit amount\n";
    cout << "Pick an option\n";
    cin >> chosenOption;
    processChosenOption();
}

void processChosenOption()
{
    switch (chosenOption)
    {
    case 1:
        makeAccount();
        makingAccount = true;
        break;
    case 2:
        depositAnAmount();
        break;
    default:
        cout << "Please pick a valid option\n";
    }
}

void makeAccount()
{
    cout << "Enter a username\n";
    string userName;
    cin >> userName;

    cout << "Enter a password\n";
    string password;
    cin >> password;

    listOfAccountUsernames.push_back(userName);
    listOfAccountPasswords.push_back(password);
    cout << "New account created\n";
    showOptions();
}

void depositAnAmount()
{
    cout << "Enter your username\n";
    cin >> enteredUsername;

    cout << "Enter your password\n";
    cin >> enteredPassword;

    if (validAccount)
    {
        int amountYouWantToDeposit;
        cout << "How much would you like to deposit?\n";
        cin >> amountYouWantToDeposit;
        listOfDepositedValues.push_back(amountYouWantToDeposit);
        showOptions();
    }
    else {
        cout << "Wrong username or password\n";
        depositAnAmount();
    }
}

void indexOfWantedAccount()
{
    for (int i = 0; i < listOfAccountUsernames.size(); i++) {
        if (listOfAccountUsernames[i] == enteredUsername) {
            indexOfThing = i;
        }
        else {
            indexOfThing = 0;
        }
    }
}


void checkIfCorrectAccount()
{
    bool username = false;
    bool Password = false;
    for (int i = 0; i < listOfAccountUsernames.size(); i++)
    {
        if (listOfAccountUsernames[i] == enteredUsername)
        {
            username = true;
        }
        else {
            username = false;
        }
    }

    for (int j = 0; j < listOfAccountPasswords.size(); j++)
    {
        if (listOfAccountPasswords[j] == enteredPassword)
        {
            Password = true;
        }
        else {
            username = false;
        }
    }

    if (username == true && Password == true)
    {
        validAccount = true;
    }
    else {
        validAccount = false;
    }
}