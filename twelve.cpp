#include<iostream>

using namespace std;

// Trying to make every class Immutable
class Vector {
    int x;
    int y;
    int z;

    public:
    void init(int x = 0, int y = 0, int z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void set_x(int x) {
        this->x = x;
    }

    void set_y(int y) {
        this->y = y;
    }

    void set_z(int z) {
        this->z = z;
    }

    Vector multiply(int scalar) {
        Vector v;
        v.init(this->x * scalar, this->y * scalar, this->z * scalar);
        return v;
    }

    Vector add(Vector v) {
        Vector answer;
        answer.init(this->x + v.x, this->y + v.y, this->z + v.z);
        return answer;
    }

    void display() {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
    }
};

int main() {
    Vector v;
    v.init(1, 2, 3);

    v.multiply(3).display();

    Vector v2;
    v2.init(2, 3, 4);

    v.add(v2).display();
    return 0;
}