#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    bool isIssued;

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isIssued = false;
    }

    void display() {
        cout << "[" << (isIssued ? "ISSUED" : "AVAILABLE") << "] "
             << title << " by " << author << " (ISBN: " << isbn << ")" << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string t, a, i;
        cout << "Enter Title: "; getline(cin >> ws, t);
        cout << "Enter Author: "; getline(cin, a);
        cout << "Enter ISBN: "; getline(cin, i);
        books.push_back(Book(t, a, i));
        cout << "Book added successfully!\n";
    }

    void searchBook() {
        string query;
        cout << "Search by title or author: "; getline(cin >> ws, query);
        bool found = false;
        for (auto &b : books) {
            if (b.title.find(query) != string::npos || b.author.find(query) != string::npos) {
                b.display();
                found = true;
            }
        }
        if (!found) cout << "No matching books found.\n";
    }

    void issueBook() {
        string t;
        cout << "Enter book title to issue: "; getline(cin >> ws, t);
        for (auto &b : books) {
            if (b.title == t) {
                if (!b.isIssued) {
                    b.isIssued = true;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        string t;
        cout << "Enter book title to return: "; getline(cin >> ws, t);
        for (auto &b : books) {
            if (b.title == t) {
                if (b.isIssued) {
                    b.isIssued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "This book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void showAll() {
        if (books.empty()) cout << "Library is empty.\n";
        for (auto &b : books) b.display();
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Management ---\n";
        cout << "1. Add Book\n2. Search\n3. Issue\n4. Return\n5. View All\n6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.searchBook(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.showAll(); break;
        }
    } while (choice != 6);

    return 0;
}
