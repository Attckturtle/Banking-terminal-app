#include <iostream>
#include <string>
#include <iomanip>
#include <list>
using namespace std;

bool makingAccount;
bool isAccountCorrect;
int chosenOption;
list<string>listOfAccountUsernames = {""};
list<string>listOfAccountPasswords = {""};

int main()
{
    cout << "1. New acoount\n";
    cout << "2. Deposit amount\n";
    cout << "Pick an option\n";
    cin >> chosenOption;
    processChosenOption();
}

void processChosenOption() {
    switch (chosenOption) {
    case 1:
        makeAccount();
        makingAccount = true;
        break;
    case 2:
        depositAnAmount();
        break;
    default:
        cout << "Please pick a valid option";
    }
}

void makeAccount() {
    cout << "Enter a username";
    string userName;
    cin >> userName;

    cout << "Enter a password";
    string password;
    cin >> password;

    listOfAccountUsernames.push_back(userName);
    listOfAccountPasswords.push_back(password);
}

void depositAnAmount() {
    string enteredUsername;
    cout << "Enter your username";
    cin >> enteredUsername;

    string enteredPassword;
    cout << "Enter your password";
    cin >> enteredPassword;

    isAccountCorrect = checkIfCorrectAccount(enteredUsername, enteredPassword);
}

bool checkIfCorrectAccount(a, b) {
    if (a == listOfAccountUsernames) {

    }
}