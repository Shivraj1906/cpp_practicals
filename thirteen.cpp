#include<iostream>
#include<string.h>

using namespace std;

class Book {
    char *author; //assuming book has only one author
    char *title;
    float price;
    char *publisher;
    int stock;

    public:
    Book(char *author, char *title, float price, char *publisher, int stock) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);

        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);

        this->publisher = new char[strlen(publisher) + 1];
        strcpy(this->publisher, publisher);

        this->price = price;
        this->stock = stock;
    }

    void display() {
        cout << "TITLE: " << title << endl;
        cout << "AUTHOR: " << author << endl;
        cout << "PUBLISHER: " << publisher << endl;
        cout << "PRICE: " << price << endl;
        cout << "STOCK: " << stock << endl;
    }

    static void buy(Book *books, int length, char *title, int quantity) {
        for(int i = 0; i < length; i++) {
            if(!strcmp(books[i].title, title)) {
                if(books[i].stock >= quantity) {
                    books[i].stock -= quantity;
                    cout << "BOOK WAS PURCHASED" << endl;

                    return;
                }

                cout << "NOT ENOUGH STOCK" << endl;
                return;
            }
        }

        cout << "BOOK WAS NOT FOUND" << endl;
    }

    static void search(Book *books, int length, char *keyword) {
        for(int i = 0; i < length; i++) {
            if(!strcmp(books[i].author, keyword) || !strcmp(books[i].title, keyword)) {
                books[i].display();
            }
        }
    }

    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }
};

int main() {
    Book books[] = {Book("Rosen", "Discrete Maths", 700, "McGrew Hill", 5), Book("Korth", "Database Design", 900, "McGrew Hill", 2)};

    Book::search(books, 2, "Discrete Maths");

    Book::buy(books, 2, "Database Design", 3);
    return 0;
}