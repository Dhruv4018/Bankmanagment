#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize an account
    Account(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Method to display account details
    void displayDetails() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Method to return the account number for searching
    int getAccountNumber() {
        return accountNumber;
    }
};

class Bank {
private:
    Account* accounts[10]; // Array to store accounts (max 10 accounts for simplicity)
    int totalAccounts;

public:
    Bank() {
        totalAccounts = 0;
    }

    // Method to create a new account
    void createAccount() {
        string name;
        int accNo;
        double initialBalance;

        cout << "Enter Account Holder's Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        // Create a new account object and add it to the array
        if (totalAccounts < 10) {  // Ensure we don't exceed 10 accounts
            accounts[totalAccounts] = new Account(name, accNo, initialBalance);
            totalAccounts++;
            cout << "Account created successfully!" << endl;
        } else {
            cout << "Sorry, account limit reached!" << endl;
        }
    }

    // Method to find an account by account number
    Account* findAccount(int accNo) {
        for (int i = 0; i < totalAccounts; i++) {
            if (accounts[i]->getAccountNumber() == accNo) {
                return accounts[i];
            }
        }
        return nullptr; // Return null if account not found
    }

    // Method to perform bank operations
    void performOperations() {
        int choice, accNo;
        double amount;
        Account* accDep = nullptr;
        Account* accWith = nullptr;
        Account* accDetails = nullptr;

        while (true) {
            cout << "\n--- Bank Management System ---\n";
            cout << "1. Create Account\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. View Account Details\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;

                case 2:
                    cout << "Enter Account Number: ";
                    cin >> accNo;
                    accDep = findAccount(accNo);
                    if (accDep != nullptr) {
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        accDep->deposit(amount);
                    } else {
                        cout << "Account not found!" << endl;
                    }
                    break;

                case 3:
                    cout << "Enter Account Number: ";
                    cin >> accNo;
                    accWith = findAccount(accNo);
                    if (accWith != nullptr) {
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        accWith->withdraw(amount);
                    } else {
                        cout << "Account not found!" << endl;
                    }
                    break;

                case 4:
                    cout << "Enter Account Number: ";
                    cin >> accNo;
                    accDetails = findAccount(accNo);
                    if (accDetails != nullptr) {
                        accDetails->displayDetails();
                    } else {
                        cout << "Account not found!" << endl;
                    }
                    break;

                case 5:
                    cout << "Exiting the system...\n";
                    return;

                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

int main() {
    Bank bank;
    bank.performOperations();
    return 0;
}
