#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int id;
    double price;

public:
    Item(int id = 0, double price = 0.0) {
        this->id = id;
        this->price = price;
    }

    void setData(int id, double price) {
        this->id = id;
        this->price = price;
    }

    double getPrice() {
        return price;
    }

    void printInfo() {
        cout << "ID: " << id << ", Price: " << price << endl;
    }
};

class Book : public Item {
private:
    string title;
    string author;
    int year;

public:
    Book(int id = 0, double price = 0.0, string title = "", string author = "", int year = 0)
        : Item(id, price) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    void setBookData(int id, double price, string title, string author, int year) {
        setData(id, price);
        this->title = title;
        this->author = author;
        this->year = year;
    }

    int getYear() {
        return year;
    }

    string getAuthor() {
        return author;
    }

    void printInfo() {
        Item::printInfo();
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of books (up to 50): ";
    cin >> n;

    if (n <= 0 || n > 50) {
        cout << "Invalid number of books!" << endl;
        return 1;
    }

    Book books[50];
    double totalPrice = 0.0;

    for (int i = 0; i < n; i++) {
        int id, year;
        double price;
        string title, author;

        cout << "Enter details for book " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Price: ";
        cin >> price;
        cin.ignore();
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Year: ";
        cin >> year;

        books[i].setBookData(id, price, title, author, year);
        totalPrice += price;
    }

    cout << "\nBooks information:" << endl;
    for (int i = 0; i < n; i++) {
        books[i].printInfo();
        cout << endl;
    }

    double totalWithVAT = totalPrice * 1.2;
    cout << "Total price with VAT: " << totalWithVAT << endl;

    string searchAuthor;
    cout << "\nEnter author to search for books after 2020: ";
    cin.ignore();
    getline(cin, searchAuthor);

    cout << "\nBooks by " << searchAuthor << " after 2020:" << endl;
    for (int i = 0; i < n; i++) {
        if (books[i].getAuthor() == searchAuthor && books[i].getYear() > 2020) {
            books[i].printInfo();
            cout << endl;
        }
    }

    return 0;
}
