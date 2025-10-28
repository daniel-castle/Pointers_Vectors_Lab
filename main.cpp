// Daniel Castillo  MCSCI-272
// main.cpp
// Purpose: Demonstrates RAII and memory-safe management of dynamically allocated books.

#include <iostream>
#include <limits>
#include "Inventory.h"
using namespace std;

/**
 * @brief Clears erroneous input and ignores any remaining characters in the input buffer.
 *
 * This function is used to handle scenarios where the input stream is in a bad state
 * due to invalid user input. It resets the state of the input stream and removes
 * any characters remaining in the input buffer up to a specified limit.
 *
 * This is helpful to ensure clean, valid input operations for subsequent interactions.
 */
void ClearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Displays a menu for the Book Inventory System and retrieves the user's choice.
 *
 * This function prints a list of available options for managing the inventory system,
 * prompts the user for input, and validates the input to ensure it is a number within the valid range.
 * If invalid input is detected, it will repeatedly ask the user for a valid choice.
 *
 * @return An integer representing the user's valid menu choice (1–4).
 */
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

/**
 * @brief Entry point of the Book Inventory System program.
 *
 * This function initializes an inventory object and provides a menu-driven system
 * for users to interact with the inventory. It supports adding new books, displaying
 * all books, and removing books by their index. The program runs in a loop until
 * the user chooses to exit by selecting the quit option in the menu.
 *
 * The options in the menu are:
 * 1. Add New Book: Prompts the user for the book title, author, and price, and adds the
 *    book to the inventory. If invalid input is provided for the price, a default price of
 *    $0.0 is assigned.
 * 2. Display All Books: Displays information for all books currently in the inventory.
 * 3. Remove Book: Prompts the user for the index of a book to remove from the inventory.
 *    If invalid input is provided for the index, the operation is aborted.
 * 4. Quit: Terminates the program.
 *
 * Input validation handles invalid menu choices, non-numeric input for the price,
 * and invalid input for the book removal index.
 *
 * @return int Exit status of the program.
 */
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