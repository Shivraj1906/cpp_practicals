#include<iostream>
#include<string.h>

using namespace std;

class Bank {
    int acount_number;
    char *customer_name;
    char *type_of_account;
    float balance;

    public:
    Bank(int account_number, char *customer_name, char *type_of_account, float balance) {
        this->acount_number = account_number;
        this->balance = balance;

        this->customer_name = new char[strlen(customer_name) + 1];
        strcpy(this->customer_name, customer_name);

        this->type_of_account = new char[strlen(type_of_account) + 1];
        strcpy(this->type_of_account, type_of_account);
    }

    void withdraw(float amount) {
        float temp = balance - amount;

        if(temp < 0) {
            cout << "NOT ENOUGH BALANCE" << endl;
            return;
        }

        balance = temp;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void show_balance() {
        cout << "BALANCE: " << balance << endl;
    }

    ~Bank() {
        delete[] customer_name;
        delete[] type_of_account;
    }
};

int main() {
    Bank a[3] = {Bank(1, "shivraj", "savings", 500), Bank(2, "Vraj", "savings", 1000), Bank(3, "Mann", "current", 5000)};

    a[0].withdraw(100);
    a[1].deposit(200);

    for(int i = 0; i < 3; i++)
        a[i].show_balance();
    return 0;
}