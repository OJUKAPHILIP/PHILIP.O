#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to represent a bank account
struct Account {
    string userId;
    string password;
    double balance;
};

// Map to store all created accounts
map<string, Account> accounts;

// Function to create a new account
void createAccount() {
    string userId, password;
    cout << "Please enter your user name: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if account already exists
    if (accounts.find(userId) != accounts.end()) {
        cout << "Account already exists!" << endl;
        return;
    }

    // Create new account
    Account newAccount;
    newAccount.userId = userId;
    newAccount.password = password;
    newAccount.balance = 0.0;
    accounts[userId] = newAccount;

    cout << "Thank You! Your account has been created!" << endl;
}

// Function to login to an existing account
bool login(string& userId, string& password) {
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if account exists and password matches
    if (accounts.find(userId) == accounts.end() || accounts[userId].password != password) {
        cout << "*** LOGIN FAILED! ***" << endl;
        return false;
    }

    cout << "Access Granted!" << endl;
    return true;
}

// Function to display main menu
void displayMainMenu() {
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

// Function to handle main menu options
void handleMainMenu(string userId) {
    char option;
    double amount;

    while (true) {
        displayMainMenu();
        cin >> option;

        switch (option) {
            case 'd':
                cout << "Amount of deposit: $";
                cin >> amount;
                accounts[userId].balance += amount;
                break;
            case 'w':
                cout << "Amount of withdrawal: $";
                cin >> amount;
                if (amount > accounts[userId].balance) {
                    cout << "Insufficient balance!" << endl;
                } else {
                    accounts[userId].balance -= amount;
                }
                break;
            case 'r':
                cout << "Your balance is $" << accounts[userId].balance << endl;
                break;
            case 'q':
                return;
            default:
                cout << "Invalid option!" << endl;
        }
    }
}

int main() {
    char option;
    string userId, password;

    while (true) {
        cout << "Hi! Welcome to the ATM Machine! Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cin >> option;

        switch (option) {
            case 'l':
                if (login(userId, password)) {
                    handleMainMenu(userId);
                }
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                return 0;
            default:
                cout << "Invalid option!" << endl;
        }
    }

    return 0;
}