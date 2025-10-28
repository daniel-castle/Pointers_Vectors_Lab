// Daniel Castillo  MCSCI-272
// inventory.cpp

#include "Inventory.h"
#include <iostream>
using namespace std;

void Inventory::addBook(Book* bookPtr) {
    if (bookPtr != nullptr) {
        books.push_back(bookPtr);
        cout << "[OK] Book added to inventory.\n";
    } else {
        cout << "[Error] Invalid book pointer.\n";
    }
}

void Inventory::displayAll() const {
    if (books.empty()) {
        cout << "(No books in inventory)\n";
        return;
    }

    cout << "\n--- Inventory List ---\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "[" << i << "] ";
        books[i]->displayInfo();
    }
    cout << "-----------------------\n";
}

void Inventory::removeBook(int index) {
    if (index < 0 || index >= static_cast<int>(books.size())) {
        cout << "[Error] Invalid index.\n";
        return;
    }

    delete books[index];             // free's memory
    books.erase(books.begin() + index);  // remove pointer from vector
    cout << "[OK] Book successfully removed.\n";
}

Inventory::~Inventory() {
    for (Book* ptr : books) {
        delete ptr;
    }
    books.clear();
    cout << "[OK] Inventory destroyed, all books deleted.\n";
}