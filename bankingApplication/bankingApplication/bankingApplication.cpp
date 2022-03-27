#include <iostream>
#include <vector>
#include <algorithm>

std::string enteredUsername;
std::string enteredPassword;

bool validAccount;
bool makingAccount;
bool isAccountCorrect;
bool correctAccount;

int indexOfThing;
int tries = 0;

std::vector<std::string> listOfAccountUsernames;
std::vector<std::string> listOfAccountPasswords;
std::vector<int> listOfDepositedValues;

void showOptions();
void processChosenOption(int a);
void makeAccount();
void login();
void afterLoginScreen();
void processSecondChosenOption(int a);
void depositAnAmount();
void withdrawAnAmount();
void playTheLottery();
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
    std::cout << "2. Login to account\n";
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
        login();
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

void login() {
    std::cout << "Enter your username\n";
    std::cin >> enteredUsername;

    std::cout << "Enter your password\n";
    std::cin >> enteredPassword;

    indexOfWantedAccount(enteredUsername);
    checkIfCorrectAccount(enteredUsername, enteredPassword);
    if (validAccount) {
        afterLoginScreen();
    }
}

void afterLoginScreen() {
    std::cout << "1. Deposit amount\n";
    std::cout << "2. Withdraw amount\n";
    std::cout << "3. Play lottery\n";
    std::cout << "Pick an option\n";
    int chosenOption;
    std::cin >> chosenOption;
    processSecondChosenOption(chosenOption);
}

void processSecondChosenOption(int a) {
    switch (a) {
    case 1:
        depositAnAmount();
        break;
    case 2:
        withdrawAnAmount();
        break;
    case 3:
        playTheLottery();
        break;
    default:
        std::cout << "Pick a valid option";
    }
}

void depositAnAmount()
{
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

        afterLoginScreen();
    }
}

void withdrawAnAmount()
{
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

        afterLoginScreen();
    }
}

void playTheLottery() {
    if (true) {
        int lotteryResults;
        int lotteryTicketCost = 5;
        if (listOfDepositedValues[indexOfThing] < 5) {
        }
        else if (listOfDepositedValues[indexOfThing] > 5) {
            int a;
            a = rand() % 1000 + 1;
            if (a == 1) {
                lotteryResults = 500000;
                listOfDepositedValues[indexOfThing] += lotteryResults;
                std::cout << "You win!\n";
            }
            else {
                char tryAgain;
                std::cout << "You lose\n";
                std::cout << "Try Again?\n" << "T/F\n";
                std::cin >> tryAgain;
                tryAgain = toupper(tryAgain);
                switch (tryAgain) {
                case 'T':
                    playTheLottery();
                    break;
                case 'F':
                    std::cout << "show options";
                    afterLoginScreen();
                    break;
                }
            }
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
    bool usernameValid;
    bool passwordValid;

    if (std::binary_search(listOfAccountUsernames.begin(), listOfAccountUsernames.end(), a)) {
        usernameValid = true;
    }
    else {
        usernameValid = false;
    }

    if (std::binary_search(listOfAccountPasswords.begin(), listOfAccountPasswords.end(), b)) {
        passwordValid = true;
    }
    else {
        passwordValid = false;
    }

    if (usernameValid && passwordValid) {
        validAccount = true;
    }
    else if (!usernameValid && !passwordValid) {
        validAccount = false;
    }
}