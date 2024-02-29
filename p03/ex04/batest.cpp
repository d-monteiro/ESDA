#include <iostream>
#include "bank_account.h"

using namespace std;


void runTests() {
    // Test constructor and getter functions
    BankAccount acc(123456, "John Doe", 1000.00);
    cout << "Account Number: " << acc.getAccountNumber() << endl;
    cout << "Account Holder Name: " << acc.getAccountHolderName() << endl;
    cout << "Balance: $" << acc.getBalance() << endl;

    // Test setter functions
    acc.setAccountNumber(654321);
    acc.setAccountHolderName("Jane Smith");
    acc.setBalance(2000.00);
    cout << "Updated Account Number: " << acc.getAccountNumber() << endl;
    cout << "Updated Account Holder Name: " << acc.getAccountHolderName() << endl;
    cout << "Updated Balance: $" << acc.getBalance() << endl;

    // Test deposit function
    acc.deposit(500.00);
    cout << "Current balance after deposit: $" << acc.getBalance() << endl;

    // Test withdraw function
    acc.withdraw(200.00);
    cout << "Current balance after withdrawal: $" << acc.getBalance() << endl;

    // Test insufficient balance for withdrawal
    acc.withdraw(3000.00);
    cout << "Current balance after attempted withdrawal: $" << acc.getBalance() << endl;
}

int main() {
    runTests();
    return 0;
}