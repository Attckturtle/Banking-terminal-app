#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

string enteredUsername;
string enteredPassword;

bool makingAccount;
bool isAccountCorrect;
int chosenOption;
vector<string> listOfAccountUsernames;
vector<string> listOfAccountPasswords;
vector<int> listOfDepositedValues;

void showOptions();
void processChosenOption();
void makeAccount();
void depositAnAmount();
int indexOfWantedAccount(string a);
bool checkIfCorrectAccount(string a, string b);

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
    string enteredUsername;
    cout << "Enter your username\n";
    cin >> enteredUsername;

    string enteredPassword;
    cout << "Enter your password\n";
    cin >> enteredPassword;

    bool checkIfValidAccount = checkIfCorrectAccount(enteredUsername, enteredPassword);

    if (checkIfValidAccount == true)
    {
        int amountYouWantToDeposit;
        cout << "How much would you like to deposit?\n";
        cin >> amountYouWantToDeposit;
        int indexOfThing = indexOfWantedAccount(enteredUsername);
        listOfDepositedValues.push_back(amountYouWantToDeposit);
        showOptions();
    }
    else {
        cout << "Wrong username or password";
        depositAnAmount();
    }
}

int indexOfWantedAccount(string a)
{
    for (int i = 0; i < sizeof(listOfAccountUsernames); i++) {
        if (listOfAccountUsernames[i] == a) {
            return i;
        }
        else {
            return 0;
        }
    }
}


bool checkIfCorrectAccount(string a, string b)
{
    bool username = false;
    bool Password = false;
    int lengthOfUsernameArray = sizeof(listOfAccountUsernames);
    for (int i = 0; i < lengthOfUsernameArray; i++)
    {
        if (listOfAccountUsernames[i] == a)
        {
            username = true;
        }
        else {
            username = false;
        }
    }

    int lengthOfPasswordArray = sizeof(listOfAccountPasswords);
    for (int j = 0; j < lengthOfPasswordArray; j++)
    {
        if (listOfAccountPasswords[j] == b)
        {
            Password = true;
        }
        else {
            username = false;
        }
    }

    if (username && Password)
    {
        return true;
    }
}