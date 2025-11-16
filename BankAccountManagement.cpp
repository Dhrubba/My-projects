#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    long long accountNumber;
    string accountType;
    double balance;

public:
    void openAccount(string n, long long accNum, string accType, double initialDeposit) {
        name = n;
        accountNumber = accNum;

        if (accType == "savings" || accType == "Savings") {
            accountType = "Savings";
            if (initialDeposit >= 2000) {
                balance = initialDeposit;
                cout << "Account created." << endl;
            } else {
                cout << "Minimum Rs. 2000 required to open a Savings account.\n";
                balance = 0;
            }
        } else if (accType == "current" || accType == "Current") {
            accountType = "Current";
            if (initialDeposit >= 10000) {
                balance = initialDeposit;
                cout << "Account created." << endl;
            } else {
                cout << "Minimum Rs. 10000 required to open a Current account.\n";
                balance = 0;
            }
        } else {
            cout << "Invalid account type entered.\n";
            accountType = "";
            balance = 0;
        }
    }

    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amt) {
        if (amt > 0) {
            if (balance >= amt) {
                balance -= amt;
                cout << "Amount withdrawn successfully.\n";
            } else {
                cout << "Insufficient balance.\n";
            }
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void display() {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    long long getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    BankAccount customers[10];
    int choice, custIndex = 0;

    do {
        cout << "===== Bank Account Management =====\n";
        cout << "1. Open Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                if (custIndex < 10) {
                    string name, accType;
                    long long accNum;
                    double initDeposit;
                    cout << "Enter Account Holder Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Account Number: ";
                    cin >> accNum;
                    cout << "Enter Account Type (Savings/Current): ";
                    cin >> accType;
                    cout << "Enter Initial Deposit: Rs. ";
                    cin >> initDeposit;
                    customers[custIndex].openAccount(name, accNum, accType, initDeposit);
                    custIndex++;
                } else {
                    cout << "Customer limit reached (10 customers).\n";
                }
                break;
            }
            case 2: {
                long long accNum;
                double amt;
                cout << "Enter Account Number to Deposit into: ";
                cin >> accNum;
                bool found = false;
                for (int i = 0; i < custIndex; i++) {
                    if (customers[i].getAccountNumber() == accNum) {
                        cout << "Enter Amount to deposit: Rs. ";
                        cin >> amt;
                        customers[i].deposit(amt);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                long long accNum;
                double amt;
                cout << "Enter Account Number to Withdraw from: ";
                cin >> accNum;
                bool found = false;
                for (int i = 0; i < custIndex; i++) {
                    if (customers[i].getAccountNumber() == accNum) {
                        cout << "Enter Amount to withdraw: Rs. ";
                        cin >> amt;
                        customers[i].withdraw(amt);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                long long accNum;
                cout << "Enter Account Number to Display details: ";
                cin >> accNum;
                bool found = false;
                for (int i = 0; i < custIndex; i++) {
                    if (customers[i].getAccountNumber() == accNum) {
                        customers[i].display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while(choice != 5);

    return 0;
}
