# Library Management System – Project Report

## Introduction

The **Library Management System** is a console-based application developed in **C++** using **Object-Oriented Programming (OOP)** principles. The purpose of this project is to automate and simplify the basic operations of a library, such as maintaining book records, checking availability, issuing books, and returning them.

This project demonstrates how real-world systems can be designed using programming concepts like **classes, objects, encapsulation, vectors, constructors, and static methods**. It provides a menu-driven interface that allows users to interact with the system easily through the terminal.

The project is especially useful as an **academic OOP mini-project**, as it clearly showcases practical implementation of class-based programming and data management.

---

## Objectives of the Project

The main objectives of this project are:

* To develop a **Library Management System using C++**.
* To implement **Object-Oriented Programming concepts** in a real-world application.
* To manage library book records efficiently.
* To allow users to **add, search, display, issue, and return books**.
* To track the **availability status of books**.
* To create a **menu-driven user-friendly system**.
* To improve understanding of **STL vectors and modular programming**.

---

## Methodology

The project follows a **structured and modular approach**.

### 1. Requirement Analysis

First, the core requirements of a basic library system were identified:

* Store book details
* Search books
* Check stock availability
* Issue books to users
* Return books

### 2. System Design

The system is designed using:

* A **Book class** to represent book details
* Member variables for ID, title, author, amount, total copies, and available copies
* Functions for handling different library operations
* Static utility methods for availability checking

### 3. Data Handling

The project uses **vector<Book>** to dynamically store multiple book records during execution.

### 4. User Interaction

A **menu-driven interface** is used so the user can select operations easily.

This methodology ensures the code remains:

* Simple
* Reusable
* Easy to maintain
* Easy to upgrade

---

## Implementation

The implementation is done in **C++** using OOP concepts.

### 🔹 Book Class

A `Book` class is created to store all book-related information such as:

* Book ID
* Title
* Author
* Amount
* Total quantity
* Available quantity
* Issue details
* Return details

This class acts as the backbone of the system.

### 🔹 Major Functions Implemented

#### 1. Add Book

Allows the user to insert a new book into the system.

#### 2. Display Books

Displays complete details of all books stored in the library.

#### 3. Search Book

Searches for books using title or author name.

#### 4. Search Book by Amount

Allows searching books based on their price.

#### 5. Check Availability

Uses a static method to verify whether copies of a book are available.

#### 6. Issue Book

Issues a book to a user and decreases the available count.

#### 7. Return Book

Returns the book and updates available stock.

### 🔹 OOP Concepts Used

The following OOP concepts are implemented:

* **Class and Objects** → `Book` class
* **Encapsulation** → data and methods inside class
* **Constructor** → initialization of book data
* **Abstraction** → simplified availability checking
* **Static Methods** → reusable utility functions

### 🔹 Tools and Technologies

* **Programming Language:** C++
* **IDE:** VS Code / CodeBlocks / Dev C++
* **Compiler:** g++
* **Concepts:** OOP, STL Vector, Menu-driven programming

---

## Conclusion

The **Library Management System** project successfully demonstrates the practical use of **Object-Oriented Programming in C++**. It automates essential library operations such as adding books, displaying records, searching, issuing, returning, and checking availability.

This project helped in understanding how OOP concepts can be applied to build a real-world problem-solving application. It also strengthened knowledge of **class design, vectors, modular functions, and user interaction handling**.

Overall, this project serves as an excellent **academic mini-project and portfolio project**, showing a strong foundation in C++ and software design principles.

---

## Future Scope

The project can be enhanced in the future by adding:

* File handling for permanent storage
* Login authentication
* Fine calculation system
* Due date reminders
* Database connectivity
* GUI interface

These improvements can make the syst
