#include<iostream>
#include<string.h>

using namespace std;

class Bank {
    char *name;
    int accno;

    public:
    Bank(char *n, int a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        accno = a;
    }

    void display_bank() {
        cout << "ACC NO: " << accno << endl;
        cout << "NAME: " << name << endl;
    }
};

class Savings : private Bank {
    float balance;

    public:
    Savings(char *n, int a, float balance) : Bank(n, a) {
        this->balance = balance;
    }

    void display() {
        display_bank();
        cout << "BALANCE: " << balance << endl;
    }
};

int main() {
    Savings a1("Foo", 1, 500);

    a1.display();
    return 0;
}