#include <iostream>
#include <vector>

std::string enteredUsername;
std::string enteredPassword;

bool validAccount;

bool makingAccount;
bool isAccountCorrect;
bool correctAccount;
int indexOfThing;

std::vector<std::string> listOfAccountUsernames;
std::vector<std::string> listOfAccountPasswords;
std::vector<int> listOfDepositedValues;

void showOptions();
void processChosenOption(int a);
void makeAccount();
void depositAnAmount();
void withdrawAnAmount();
void indexOfWantedAccount(std::string a);
void checkIfCorrectAccount(std::string a, std::string b);

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
    int chosenOption;
    std::cin >> chosenOption;
    processChosenOption(chosenOption);
}

void processChosenOption(int a)
{
    switch (a)
    {
    case 1:
        makeAccount();
        break;
    case 2:
        depositAnAmount();
        break;
    case 3:
        withdrawAnAmount();
        break;
    default:
        std::cout << "Please pick a valid option\n";
        showOptions();
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

    indexOfWantedAccount(enteredUsername);
    checkIfCorrectAccount(enteredUsername, enteredPassword);

    if (validAccount)
    {
        int amountYouWantToDeposit;
        std::cout << "How much would you like to deposit?\n";
        std::cin >> amountYouWantToDeposit;

        switch (indexOfThing)
        {
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
        if (tries >= 3)
        {
            std::cout << "Locking all acounts";
        }
        else
        {
            depositAnAmount();
        }
    }
}

void withdrawAnAmount()
{
    std::cout << "Enter your username\n";
    std::cin >> enteredUsername;

    std::cout << "Enter your password\n";
    std::cin >> enteredPassword;

    checkIfCorrectAccount(enteredUsername, enteredPassword);

    if (validAccount)
    {
        int amountYouWantToWithdraw;
        std::cout << "How much would you like to withdraw?\n";
        std::cin >> amountYouWantToWithdraw;

        switch (indexOfThing)
        {
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
        if (tries >= 3)
        {
            std::cout << "Locking all acounts";
        }
        else
        {
            withdrawAnAmount();
        }
    }
}

void indexOfWantedAccount(std::string a)
{
    for (int i = 0; i < listOfAccountUsernames.size(); i++)
    {
        if (listOfAccountUsernames[i] == a)
        {
            indexOfThing = i;
        }
    }
    if (indexOfThing == NULL)
    {
        indexOfThing = 0;
    }
}

void checkIfCorrectAccount(std::string a, std::string b)
{
    bool accountValid = false;
    for (int i = -1; i <= listOfAccountUsernames.size(); i++)
    {
        if (listOfAccountUsernames[i] == a && listOfAccountPasswords[i] == b)
        {
            accountValid = true;
        }
    }

    if (accountValid)
    {
        validAccount = true;
    }
}