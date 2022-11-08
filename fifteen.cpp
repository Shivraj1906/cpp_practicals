#include<iostream>
#include<string.h>
using namespace std;

//Immutable class
class String1 {
    char *str;
    int length;

    public: 
    String1(char *str) {
        length = strlen(str);
        this->str = new char[length + 1];
        strcpy(this->str, str);
    }

    String1(int length) {
        this->length = length;
        str = new char[length + 1];
    }

    void print() {
        cout << str << endl;
    }

    String1 concat(String1 &s2) {
        String1 answer(this->length + s2.length);

        for(int i = 0; i < length; i++)
            answer.str[i] = str[i];

        for(int i = 0; i < s2.length; i++)
            answer.str[i + length] = s2.str[i];

        return answer;
    }

    ~String1() {
        delete[] str;
    }
};

int main() {
    String1 s1("Foo");
    String1 s2("Bar");

    s1.concat(s2).print();
    return 0;
}