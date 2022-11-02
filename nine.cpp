#include<iostream>

using namespace std;

class Bank {
    int account_number;
    float balance;

    public:
    void init(int account_number = 0, float balance = 0) {
        this->account_number = account_number;
        this->balance = balance;
    }

    void withdraw(int amount) {
        int temp = balance - amount;

        if(temp < 0) {
            cout << "Not enough balance" << endl;
            return;
        }

        balance = temp;
    }

    void deposit(int amount) {
        balance += amount;
    }

    void display() {
        cout << "ACCOUNT NO: " << account_number << endl;
        cout << "BALANCE: " << balance << endl;
    }
};

int main() {
    Bank a1;
    a1.init(1, 500);
    a1.withdraw(20);
    a1.deposit(20);
    a1.display();
    return 0;
}