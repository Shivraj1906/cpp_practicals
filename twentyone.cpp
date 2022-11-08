#include<iostream>
#include<string.h>

#define CHAR_MAX 50

using namespace std;

class Animal {
    char *name;
    float speed;

    public:
    Animal() {
        name = new char[CHAR_MAX];

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter speed: ";
        cin >> speed;
    }

    Animal(char *name, float speed) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->speed = speed;
    }

    void display() {
        cout << "NAME: " << name << endl;
        cout << "SPEED: " << speed << endl;
    }

    int operator<=(Animal &a) {
        if(speed <= a.speed)
            return 1;
        return 0;
    }

    Animal& operator++() {
        this->speed++;
        return *this;
    }

    Animal& operator++(int n) {
        Animal a(name, speed);
        this->speed++;
        return a;
    }

    ~Animal() {
        delete[] name;
    }
};

int main() {
    Animal a1("Cheetah", 40);
    Animal a2("Horse", 30);

    if(a2 <= a1)
        cout << "Horse is slower" << endl;

    a1++;
    ++a1;
    a1.display();
    return 0;
}