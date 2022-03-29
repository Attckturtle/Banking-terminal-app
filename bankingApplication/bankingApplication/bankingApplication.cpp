#include <iostream>
#include <vector>
#include <algorithm>

std::string enteredUsername;
std::string enteredPassword;

int indexOfBankThing;

std::vector<std::string> listOfAccountUsernames;
std::vector<std::string> listOfAccountPasswords;
std::vector<int> listOfDepositedValues;

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
    bool validAccount;

    std::cout << "Enter your username\n";
    std::cin >> enteredUsername;

    std::cout << "Enter your password\n";
    std::cin >> enteredPassword;

    indexOfWantedAccount(enteredUsername);
    validAccount = checkIfCorrectAccount(enteredUsername, enteredPassword);
    if (validAccount) {
        afterLoginScreen();
    }
    else {
        std::cout << "Try again";
        login();
    }
}

void afterLoginScreen() {
    std::cout << "1. Deposit amount\n";
    std::cout << "2. Withdraw amount\n";
    std::cout << "3. Play lottery\n";
    std::cout << "Pick an option\n";
    int chosenOption;
    std::cin >> chosenOption;
    switch (chosenOption) {
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
        afterLoginScreen();
    }
}

void depositAnAmount()
{
    int amountYouWantToDeposit;
    std::cout << "How much would you like to deposit?\n";
    std::cin >> amountYouWantToDeposit;
    listOfDepositedValues[indexOfBankThing] += amountYouWantToDeposit;
    std::cout << "Your current balance is $" << listOfDepositedValues[indexOfBankThing] << std::endl;
    afterLoginScreen();
}

void withdrawAnAmount()
{
    int amountYouWantToWithdraw;
    std::cout << "How much would you like to withdraw?\n";
    std::cin >> amountYouWantToWithdraw;
    listOfDepositedValues[indexOfBankThing] -= amountYouWantToWithdraw;
    std::cout << "Your current balance is $" << listOfDepositedValues[indexOfBankThing] << std::endl;
    afterLoginScreen();
}

void playTheLottery() {
    if (true) {
        int lotteryResults;
        int lotteryTicketCost = 5;
        if (listOfDepositedValues[indexOfBankThing] < 5) {
        }
        else if (listOfDepositedValues[indexOfBankThing] > 5) {
            int a;
            a = rand() % 1000 + 1;
            if (a == 1) {
                lotteryResults = 500000;
                listOfDepositedValues[indexOfBankThing] += lotteryResults;
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
            indexOfBankThing = i;
        }
    }
    if (indexOfBankThing == NULL)
    {
        indexOfBankThing = 0;
    }
}

bool checkIfCorrectAccount(std::string a, std::string b)
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
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    showOptions();
    return 0;
}