#include<iostream>
#include<string.h>

using namespace std;

class Account {
    int account_number;
    char *depositor;
    char *type_of_account;
    float balance;

    static int account_counter;

    public:
    Account(char *depositor, char *type_of_account, float balance) {
        this->depositor = new char[strlen(depositor) + 1];
        strcpy(this->depositor, depositor);

        this->type_of_account = new char[strlen(type_of_account) + 1];
        strcpy(this->type_of_account, type_of_account);

        this->balance = balance;
        this->account_number = ++account_counter;
    }

    Account(const Account &account) {
        this->account_number = account.account_number;
        
        this->depositor = new char[strlen(account.depositor) + 1];
        strcpy(this->depositor, account.depositor);

        this->type_of_account = new char[strlen(account.type_of_account) + 1];
        strcpy(this->type_of_account, account.type_of_account);

        this->balance = account.balance;
    }

    float get_balance() {
        return balance;
    }

    void withdraw(float amount) {
        float temp = balance - amount;

        if(temp < 0) {
            cout << "NOT ENOUGH BALANCE" << endl;
            return;
        }

        balance = temp;
        cout << "BALANCE UPDATED" << endl;
    }

    void deposit(float amount) {
        balance += amount;

        cout << "BALANCE UPDATED" << endl;
    }

    void display() {
        cout << "NAME: " << depositor << endl;
        cout << "BALANCE: " << balance << endl;
    }

    ~Account() {
        delete[] depositor;
        delete[] type_of_account;
    }
};

int Account::account_counter = 0;

int main() {

    Account accounts[] = {Account("Shivraj", "savings", 500), Account("Vraj", "current", 2000)};

    for(int i = 0; i < 2; i++) {
        if(accounts[i].get_balance() < 1000) {
            accounts[i].display();
        }
    }
    return 0;
}