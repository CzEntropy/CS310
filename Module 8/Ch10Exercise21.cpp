//Cristian Taylor
//5-6-2024
// This program creates and defines a bankAccount class
#include <iostream>
#include <string>

class bankAccount {
private:
    std::string accountHolderName;
    int accountNumber;
    std::string accountType;
    double balance;
    static int nextAccountNumber;
    double interestRate;

public:
    bankAccount() {
        accountHolderName = "";
        accountNumber = nextAccountNumber++;
        accountType = "";
        balance = 0.0;
        interestRate = 0.0;
    }

    void setAccountHolderName(std::string name) {
        accountHolderName = name;
    }

    void setAccountType(std::string type) {
        accountType = type;
    }

    void setBalance(double amount) {
        balance = amount;
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            std::cout << "Insufficient balance\n";
    }

    void display() {
        std::cout << "Account Holder Name: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Type: " << accountType << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "Interest Rate: " << interestRate << std::endl;
    }
};

int bankAccount::nextAccountNumber = 1;

int main() {
    bankAccount accounts[10];

    // Example usage
    accounts[0].setAccountHolderName("John Doe");
    accounts[0].setAccountType("Checking");
    accounts[0].setBalance(1000.0);
    accounts[0].setInterestRate(0.05);

    accounts[0].deposit(500.0);
    accounts[0].withdraw(200.0);

    accounts[0].display();

    getch();
    return 0;
}
