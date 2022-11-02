#include<iostream>

using namespace std;

class Product {
    int id;
    int quantity;
    float price;

    public:
    Product(int id = 0, int quantity = 0, float price = 0) {
        this->id = id;
        this->quantity = quantity;
        this->price = price;
    }

    float total_amount() {
        return price * quantity;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "QUANTITY: " << quantity << endl;
        cout << "PRICE: " << price << endl;
        cout << "TOTAL AMOUNT: " << total_amount() << endl;
    }
};

int main() {
    Product p1(1, 5, 55.5f);

    p1.display();
    return 0;
}