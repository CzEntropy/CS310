//Cristian Taylor
//5-10-2024
//This program will creates a checking and savings account for a user at a given bank. 
//There will be functions within these two classes that allow a user to withdraw, check balance, interest rate and more.
#include <iostream>
#include <iomanip>
#include <conio.h> // Include for _getch()

using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    void printInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharges;

public:
    CheckingAccount(int accNum, double bal, double intRate, double minBal, double servCharges)
        : BankAccount(accNum, bal), interestRate(intRate), minimumBalance(minBal), serviceCharges(servCharges) {}

    void setInterestRate(double intRate) {
        interestRate = intRate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void setMinimumBalance(double minBal) {
        minimumBalance = minBal;
    }

    double getMinimumBalance() const {
        return minimumBalance;
    }

    void setServiceCharges(double servCharges) {
        serviceCharges = servCharges;
    }

    double getServiceCharges() const {
        return serviceCharges;
    }

    void postInterest() {
        balance += balance * interestRate / 100.0;
    }

    bool checkMinBalance() const {
        return balance < minimumBalance;
    }

    void writeCheck(double amount) {
        if (checkMinBalance()) {
            cout << "Insufficient funds. Service charges may apply." << endl;
            balance -= serviceCharges;
        }
        withdraw(amount);
    }

    void withdraw(double amount) override {
        if (checkMinBalance()) {
            cout << "Insufficient funds. Service charges may apply." << endl;
            balance -= serviceCharges;
        }
        BankAccount::withdraw(amount);
    }

    void printInfo() const {
        BankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: $" << minimumBalance << endl;
        cout << "Service Charges: $" << serviceCharges << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double intRate)
        : BankAccount(accNum, bal), interestRate(intRate) {}

    void setInterestRate(double intRate) {
        interestRate = intRate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void postInterest() {
        balance += balance * interestRate / 100.0;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
            return;
        }
        BankAccount::withdraw(amount);
    }

    void printInfo() const {
        BankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    int choice;
    int accNum;
    double balance, interestRate, minBalance, serviceCharges, amount;

    cout << "Enter account number: ";
    cin >> accNum;

    cout << "Enter initial balance: $";
    cin >> balance;

    cout << "Enter interest rate for checking account (%): ";
    cin >> interestRate;

    cout << "Enter minimum balance for checking account: $";
    cin >> minBalance;

    cout << "Enter service charges for checking account: $";
    cin >> serviceCharges;

    CheckingAccount checking(accNum, balance, interestRate, minBalance, serviceCharges);

    cout << "Enter interest rate for savings account (%): ";
    cin >> interestRate;

    SavingsAccount savings(accNum, balance, interestRate);
//Bank menu system
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Print Account Info\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                checking.deposit(amount);
                savings.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                checking.withdraw(amount);
                savings.withdraw(amount);
                break;
            case 3:
                cout << "\nChecking Account Info:\n";
                checking.printInfo();
                cout << "\nSavings Account Info:\n";
                savings.printInfo();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}
