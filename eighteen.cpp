#include<iostream>
#include<string.h>

using namespace std;

void reverse(char *str, int char_count) {
    int length = strlen(str);

    int char_to_reverse = char_count == 0 ? length : char_count;


    //Throwing segmentation fault
    for(int i = 0, j = char_to_reverse - 1; i < char_to_reverse / 2; i++, j--) {
        char temp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = temp;
    }
}

int main() {

    char *str = "Foobar";

    reverse(str, 0);

    cout << str << endl;
    return 0;
}