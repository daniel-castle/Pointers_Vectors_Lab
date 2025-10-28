cmake_minimum_required(VERSION 4.0)
project(Pointers_Lab_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pointers_Lab_1 main.cpp
        Inventory.cpp
        Inventory.h
        Book.h)
