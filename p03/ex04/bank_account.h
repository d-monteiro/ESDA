#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, string accHolder, double bal);
    int getAccountNumber();
    void setAccountNumber(int accNum);
    string getAccountHolderName();
    void setAccountHolderName(string accHolder);
    double getBalance();
    void setBalance(double bal);
    void deposit(double amount);
    void withdraw(double amount);
};

#endif // _BANKACCOUNT_H_
