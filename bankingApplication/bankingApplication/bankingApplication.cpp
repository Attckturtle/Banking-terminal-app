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

int main()
{
    cout << "1. New acoount\n";
    cout << "2. Deposit amount\n";
    cout << "Pick an option\n";
    cin >> chosenOption;
    processChosenOption();

    return 0;
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
}

void depositAnAmount()
{
    string enteredUsername;
    cout << "Enter your username\n";
    cin >> enteredUsername;

    string enteredPassword;
    cout << "Enter your password\n";
    cin >> enteredPassword;

    if (checkIfCorrectAccount(enteredUsername, enteredPassword))
    {
        int amountYouWantToDeposit;
        cout << "How much would you like to deposit?\n";
        cin >> amountYouWantToDeposit;
        int indexOfThing = indexOfWantedAccount(enteredUsername);
        listOfDepositedValues.push_back(amountYouWantToDeposit);
    }
}

int indexOfWantedAccount(string a)
{
    auto indexOfTheThing = find(listOfAccountUsernames.begin(), listOfAccountUsernames.end(), a);
    return indexOfTheThing;
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
    }

    int lengthOfPasswordArray = sizeof(listOfAccountPasswords);
    for (int j = 0; j < lengthOfPasswordArray; j++)
    {
        if (listOfAccountPasswords[j] == b)
        {
            Password = true;
        }
    }

    if (username && Password)
    {
        return true;
    }
}