#include<iostream>

using namespace std;
class B;
class A {
    int a;
    public:
    A(int a) {
        this->a = a;
    }

    friend int max(A, B);
};

class B {
    int b;
    public:
    B(int b) {
        this->b = b;
    }
    friend int max(A, B);
};

int max(A x, B y) {
    if(x.a > y.b)
        return x.a;
    return y.b;
}

int main() {
    A a(5);
    B b(10);

    cout << "MAX: " << max(a, b) << endl;
    return 0;
}