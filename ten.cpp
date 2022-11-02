#include<iostream>
#define MAX 100
using namespace std;

class Number {
    int a[MAX];
    int length;

    public:
    void init(int length) {
        for(int i = 0; i < length; i++)
            cin >> a[i];
        this->length = length;
    }

    void display() {
        for(int i = 0; i < length; i++)
            cout << a[i] << " ";
    }

    int max() {
        int max = a[0];
        for(int i = 1; i < length; i++) {
            if(a[i] > max)
                max = a[i];
        }

        return max;
    }

    int min() {
        int min = a[0];
        for(int i = 1; i < length; i++) {
            if(a[i] < min)
                min = a[i];
        }

        return min;
    }

    void sort() {
        for(int i = 0; i < length - 1; i++) {
            for(int j = i + 1; j < length; j++) {
                if(a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
};

int main() {
    Number n;
    n.init(5);

    cout << "MAX: " << n.max() << endl;
    cout << "MIN: " << n.min() << endl;

    n.sort();

    n.display();
    return 0;
}