#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private: 
        int accountNumber;
        string owner;
        int balance;
    
    public:
        BankAccount(int acc, string owner, int balance): accountNumber(acc), owner(owner), balance(balance) {}

        int deposit(int money) {
            if(money >= 0) {
                balance += money;
            }
            return balance;
        }

        void withdraw() {
            balance = 0;
        }

        void printBalance() const{
            cout << balance << endl;
        }
};