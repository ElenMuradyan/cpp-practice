#include <iostream>
#include <string>

using namespace std;

class Account {
    protected:
        int id;
        double balance;
    public:
        Account(int id, double balance): id(id), balance(balance){}
        virtual void display() const {
            cout << "Account ID: " << id << ", Balance: $" << balance << endl;
        }
        virtual ~Account() {};
};

class SavingsAccount : public Account{
    private:
        double interestRate;
    public:
        SavingsAccount(int id, double balance, double interestRateArg): Account(id, balance), interestRate(interestRateArg){}
        void display() const override {
            cout << "Savings Account ID: " << id << ", Balance: $" << balance << ", Interest Rate: " << (interestRate * 100) << "%" << endl;
        }
        void addInterest() {
            balance += balance * interestRate;
        }
};

class CheckingAccount : public Account {
    private: 
        int fee;
    public:
        CheckingAccount(int id, double balance, double fee): Account(id, balance), fee(fee){}
        void display() const override {
            cout << "Checking Account ID: " << id << ", Balance: $" << balance<< ", Fee: $" << fee << endl;
        }
        void deductFee() {
            if(balance >= fee){
                balance -= fee;
            }else {
                cout << "Insufficient funds to deduct fee." << endl;
            }
        }
};