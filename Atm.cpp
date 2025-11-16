#include <iostream>
using namespace std;

class ATM {
private:
    int pin,balance;

public:
    ATM() {
        pin = 7869;     
        balance = 100000; 
    }

    bool validatePIN() {
        int checkpin;
        cout << "Enter ATM PIN: ";
        cin >> checkpin;
        if (checkpin == pin) {
            cout << "Entry Successful\n";
            return true;
        } else {
            cout << "Invalid PIN!\n";
            return false;
        }
    }

    void checkBalance() {
        cout << "Your available balance is: " << balance << endl;
    }

    void deposit() {
        int amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout <<"Amount deposited successfully!\n";
        cout <<"Your current balance is: "<< balance << endl;
    }

    void withdraw() {
        int amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            cout << "Please collect your cash!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }
};

int main() {
    ATM atm;
    int choice;

    if (!atm.validatePIN()) {
        return 0;
    }

    do {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: atm.checkBalance(); break;
            case 2: atm.deposit(); break;
            case 3: atm.withdraw(); break;
            case 4: cout << "Thank you for using ATM\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 4);

    return 0;
}
