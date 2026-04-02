#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    double amount;
    int totalBooks;
    int availableBooks;
    string issueDate;
    string returnDate;
    string issuedToName;
    string issuedToPhone;

    Book(int i, string t, string a, double amt, int total) {
        id = i;
        title = t;
        author = a;
        amount = amt;
        totalBooks = total;
        availableBooks = total;
        issueDate = "N/A";
        returnDate = "N/A";
        issuedToName = "N/A";
        issuedToPhone = "N/A";
    }

    void display() const {
        cout << "ID: " << id << '\n'
             << "Title: " << title << '\n'
             << "Author: " << author << '\n'
             << "Amount: " << amount << '\n'
             << "Total Books: " << totalBooks << '\n'
             << "Available: " << availableBooks << '\n'
             << "Last Issue Date: " << issueDate << '\n'
             << "Last Return Date: " << returnDate << '\n'
             << "Issued To: " << issuedToName << '\n'
             << "Phone: " << issuedToPhone << "\n\n";
    }
};

vector<Book> library;

class AvailabilityChecker {
public:
    static bool isAvailable(const Book &book) {
        return book.availableBooks > 0;
    }

    static void showAvailability(const Book &book) {
        if (isAvailable(book)) {
            cout << "Book is available. Copies left: " << book.availableBooks << endl;
        } else {
            cout << "Book is not available.\n";
        }
    }
};

void addBook() {
    int id;
    double amount;
    int totalBooks;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Book Amount: ";
    cin >> amount;

    cout << "Enter Number of Books Available: ";
    cin >> totalBooks;

    library.push_back(Book(id, title, author, amount, totalBooks));
    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (library.empty()) {
        cout << "No books in library!\n";
        return;
    }

    for (auto &b : library) {
        b.display();
    }
}

void searchBook() {
    string keyword;
    bool found = false;

    if (library.empty()) {
        cout << "No books in library!\n";
        return;
    }

    cin.ignore();
    cout << "Enter title or author to search: ";
    getline(cin, keyword);

    for (auto &b : library) {
        if (b.title.find(keyword) != string::npos ||
            b.author.find(keyword) != string::npos) {
            b.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No matching books found!\n";
    }
}

void searchBookByAmount() {
    double targetAmount;
    bool found = false;

    if (library.empty()) {
        cout << "No books in library!\n";
        return;
    }

    cout << "Enter amount to search: ";
    cin >> targetAmount;

    for (const auto &b : library) {
        if (fabs(b.amount - targetAmount) < 0.0001) {
            b.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No books found for this amount!\n";
    }
}

void checkBookAvailability() {
    int id;

    if (library.empty()) {
        cout << "No books in library!\n";
        return;
    }

    cout << "Enter Book ID to check availability: ";
    cin >> id;

    for (const auto &b : library) {
        if (b.id == id) {
            cout << "Title: " << b.title << endl;
            AvailabilityChecker::showAvailability(b);
            return;
        }
    }

    cout << "Book ID not found!\n";
}

void issueBook() {
    int id;
    string date;
    string name;
    string phone;

    cout << "Enter Book ID to issue: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter User Name: ";
    getline(cin, name);
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Issue Date (DD-MM-YYYY): ";
    getline(cin, date);

    for (auto &b : library) {
        if (b.id == id && AvailabilityChecker::isAvailable(b)) {
            b.availableBooks--;
            b.issueDate = date;
            b.issuedToName = name;
            b.issuedToPhone = phone;
            cout << "Book issued successfully!\n";
            cout << "Book will be available to user till 30 days.\n";
            return;
        }
    }
    cout << "Book not available!\n";
}

void returnBook() {
    int id;
    string date;
    cout << "Enter Book ID to return: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Return Date (DD-MM-YYYY): ";
    getline(cin, date);

    for (auto &b : library) {
        if (b.id == id && b.availableBooks < b.totalBooks) {
            b.availableBooks++;
            b.returnDate = date;
            b.issuedToName = "N/A";
            b.issuedToPhone = "N/A";
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Invalid book ID!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Search Book By Amount\n";
        cout << "5. Check Availability\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: searchBookByAmount(); break;
            case 5: checkBookAvailability(); break;
            case 6: issueBook(); break;
            case 7: returnBook(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
