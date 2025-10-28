# RAII Inventory Lab

**Course:** MCSCI-272
**Author:** Daniel Castillo  

---

## Overview
This lab demonstrates the concept of **RAII (Resource Acquisition Is Initialization)** in C++.  
It implements an **Inventory** system that manages dynamically allocated **Book** objects, ensuring all resources are automatically released when the program ends.

---

## Class Structure
**Book**
- Private members: `title`, `author`, `price`
- Public methods: constructor, `displayInfo()`

**Inventory**
- Private member: `std::vector<Book*> books`
- Public methods: `addBook()`, `displayAll()`, `removeBook()`, and a destructor `~Inventory()` for cleanup.
