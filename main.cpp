// Daniel Castillo  MCSCI-272
// main.cpp
// Purpose: Demonstrates RAII and memory-safe management of dynamically allocated books.

#include <iostream>
#include <limits>
#include "Inventory.h"
using namespace std;

void ClearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Menu() {
    int choice;
    cout << "\nBook Inventory System\n";
    cout << "1. Add New Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Remove Book\n";
    cout << "4. Quit\n";
    cout << "Enter choice: ";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice. Enter 1–4: ";
        ClearBadInput();
    }
    ClearBadInput();
    return choice;
}

int main() {
    Inventory store;
    int choice;

    do {
        choice = Menu();
        switch (choice) {
            case 1: {
                string title, author;
                double price;

                cout << "Enter book title: ";
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter price: ";
                if (!(cin >> price)) {
                    cout << "[Error] Invalid price. Defaulting to $0.\n";
                    price = 0.0;
                    ClearBadInput();
                }
                ClearBadInput();

                store.addBook(new Book(title, author, price));
                break;
            }
            case 2:
                store.displayAll();
                break;
            case 3: {
                int index;
                cout << "Enter book index to remove: ";
                if (!(cin >> index)) {
                    cout << "[Error] Invalid input.\n";
                    ClearBadInput();
                    break;
                }
                store.removeBook(index);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
        }
    } while (choice != 4);

    return 0;
}