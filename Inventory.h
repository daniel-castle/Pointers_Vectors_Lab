// Daniel Castillo  MCSCI-272
// Inventory.h

#ifndef POINTERS_LAB_1_INVENTORY_H
#define POINTERS_LAB_1_INVENTORY_H

#include <vector>
#include "Book.h"
using namespace std;

class Inventory {
private:
    vector<Book*> books;  // Vector of pointers to dynamically allocated Book objects

public:
    // Adds a dynamically allocated Book pointer
    void addBook(Book* bookPtr);

    // Displays all books currently in the inventory
    void displayAll() const;

    // Removes a specific book by index
    void removeBook(int index);

    // Destructor — cleans up all dynamically allocated Book objects
    ~Inventory();
};

#endif //POINTERS_LAB_1_INVENTORY_H