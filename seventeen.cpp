#include<iostream>
#include<string.h>

using namespace std;

class String1 {
    char *str;
    int length;

    public:
    String1(char *str) {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);

        length = strlen(str);
    }

    String1(const String1& s) {
        this->str = new char[s.length + 1];
        strcpy(this->str, s.str);

        this->length = s.length;
    }

    void display() {
        cout << str << endl;
    }

    int compare_string(String1 substr, int index) {
        int flag = 1;
        int counter = 0;
        for(int i = index; i < substr.length + index; i++, counter++) {
            if(substr.str[counter] != str[i]) {
                flag = 0;
                break;
            }
        }
        return flag;
    }

    //assuming replace_string and substring have same length
    void replace(String1 substring, String1 replace_string) {
        for(int i = 0; i < length - substring.length + 1; i++) {
            if(compare_string(substring, i)) {
                cout << i << endl;
                for(int j = 0; j < substring.length; j++, i++) {
                    str[i] = replace_string.str[j];
                }
            }
        }
    }

    ~String1() {
        delete[] str;
    }
};

int main() {

    String1 s1("Shivraj");
    String1 s2("raj");
    String1 s3("Who");
    
    s1.replace(s2, s3);

    s1.display();

    return 0;
}