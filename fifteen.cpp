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

    int get_length() {
        return length;
    }

    void set_char(int index, char c) {
        this->str[index] = c;
    }

    char get_char(int index) {
        return str[index];
    }

    void print() {
        cout << str << endl;
    }

    String1 concat(String1 &s2) {
        String1 answer(this->length + s2.get_length());

        for(int i = 0; i < length; i++)
            answer.set_char(i, str[i]);

        for(int i = 0; i < s2.get_length(); i++)
            answer.set_char(i + length, s2.get_char(i));

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