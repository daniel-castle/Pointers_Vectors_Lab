// Daniel Castillo  MCSCI-272
// book.h

#ifndef POINTERS_LAB_1_BOOK_H
#define POINTERS_LAB_1_BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    Book(const string& bookTitle, const string& bookAuthor, double bookPrice) : title(bookTitle),
    author(bookAuthor), price(bookPrice) {}

    void displayInfo() const {
        cout << "--------------------------\n";
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price : $" << price << endl;
    }
};

#endif //POINTERS_LAB_1_BOOK_H