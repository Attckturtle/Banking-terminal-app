#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

std::string enteredUsername;
std::string enteredPassword;

bool validAccount;

bool makingAccount;
bool isAccountCorrect;
int chosenOption;
bool correctAccount;
int indexOfThing;

std::vector<std::string> listOfAccountUsernames;
std::vector<std::string> listOfAccountPasswords;
std::vector<int> listOfDepositedValues;

void showOptions();
void processChosenOption();
void makeAccount();
void depositAnAmount();
void withdrawAnAmount();
void indexOfWantedAccount();
void checkIfCorrectAccount();

int main()
{
    showOptions();
    return 0;
}

void showOptions()
{
    std::cout << "1. New acoount\n";
    std::cout << "2. Deposit amount\n";
    std::cout << "3. Withdraw amount\n";
    std::cout << "Pick an option\n";
    std::cin >> chosenOption;
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
    case 3:
        withdrawAnAmount();
        break;
    default:
        std::cout << "Please pick a valid option\n";
    }
}

void makeAccount()
{
    std::cout << "Enter a username\n";
    std::string userName;
    std::cin >> userName;

    std::cout << "Enter a password\n";
    std::string password;
    std::cin >> password;

    listOfAccountUsernames.push_back(userName);
    listOfAccountPasswords.push_back(password);
    listOfDepositedValues.push_back(0);

    std::cout << "New account created\n";
    showOptions();
}

void depositAnAmount()
{
    std::cout << "Enter your username\n";
    std::cin >> enteredUsername;

    std::cout << "Enter your password\n";
    std::cin >> enteredPassword;

    checkIfCorrectAccount();

    if (validAccount)
    {
        int amountYouWantToDeposit;
        std::cout << "How much would you like to deposit?\n";
        std::cin >> amountYouWantToDeposit;

        switch (indexOfThing) {
        case 0:
            listOfDepositedValues[0] += amountYouWantToDeposit;
            std::cout << "Your current balance is $" << listOfDepositedValues[0] << std::endl;
            break;
        case 1:
            listOfDepositedValues[1] += amountYouWantToDeposit;
            std::cout << "Your current balance is $" << listOfDepositedValues[1] << std::endl;
            break;
        case 2:
            listOfDepositedValues[2] += amountYouWantToDeposit;
            std::cout << "Your current balance is $" << listOfDepositedValues[2] << std::endl;
            break;
        }

        showOptions();
    }
    else
    {
        int tries = 0;
        tries++;
        std::cout << "Wrong username or password\n";
        if (tries >= 3) {
            std::cout << "Locking all acounts";
        }
        else {
            depositAnAmount();
        }
    }
}

void withdrawAnAmount() {
    std::cout << "Enter your username\n";
    std::cin >> enteredUsername;

    std::cout << "Enter your password\n";
    std::cin >> enteredPassword;

    checkIfCorrectAccount();

    if (validAccount)
    {
        int amountYouWantToWithdraw;
        std::cout << "How much would you like to withdraw?\n";
        std::cin >> amountYouWantToWithdraw;

        switch (indexOfThing) {
        case 0:
            listOfDepositedValues[0] -= amountYouWantToWithdraw;
            std::cout << "Your current balance is $" << listOfDepositedValues[0] << std::endl;
            break;
        case 1:
            listOfDepositedValues[1] -= amountYouWantToWithdraw;
            std::cout << "Your current balance is $" << listOfDepositedValues[1] << std::endl;
            break;
        case 2:
            listOfDepositedValues[2] -= amountYouWantToWithdraw;
            std::cout << "Your current balance is $" << listOfDepositedValues[2] << std::endl;
            break;
        }

        showOptions();
    }
    else
    {
        int tries = 0;
        tries++;
        std::cout << "Wrong username or password\n";
        if (tries >= 3) {
            std::cout << "Locking all acounts";
        }
        else {
            withdrawAnAmount();
        }
    }
}

void indexOfWantedAccount()
{
    for (int i = 0; i < listOfAccountUsernames.size(); i++)
    {
        if (listOfAccountUsernames[i] == enteredUsername)
        {
            indexOfThing = i;
        }
    }
    if (indexOfThing == NULL) {
        indexOfThing = 0;
    }
}

void checkIfCorrectAccount()
{
    bool username = false;
    bool Password = false;
    for (int i = -1; i <= listOfAccountUsernames.size(); i++)
    {
        if (listOfAccountUsernames[i] == enteredUsername)
        {
            username = true;
        }

        if (listOfAccountPasswords[i] == enteredPassword)
        {
            Password = true;
        }
    }

    if (username && Password)
    {
        validAccount = true;
    }
    else
    {
        validAccount = false;
    }
}