#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    float price;
    int stock;

public:
    static int successfulTransactions;
    static int unsuccessfulTransactions;

    // Default constructor
    Book() {
        title = "";
        author = "";
        publisher = "";
        price = 0.0;
        stock = 0;
    }

    // Parameterized constructor
    Book(string t, string a, string p, float pr, int s) {
        title = t;
        author = a;
        publisher = p;
        price = pr;
        stock = s;
    }

    // Function to add or update book details
    void addUpdateBook(string t, string a, string p, float pr, int s) {
        title = t;
        author = a;
        publisher = p;
        price = pr;
        stock = s;
    }

    // Function to search for a book by title
    bool searchBook(string t) {
        if (title == t) {
            cout << "Book found:\n";
            cout << "Title: " << title << "\n";
            cout << "Author: " << author << "\n";
            cout << "Publisher: " << publisher << "\n";
            cout << "Price: " << price << "\n";
            cout << "Stock: " << stock << "\n";
            return true;
        }
        return false;
    }

    // Function to purchase a book
    void purchaseBook(int quantity) {
        if (quantity <= stock) {
            stock -= quantity;
            float totalCost = quantity * price;
            successfulTransactions++;
            cout << "Purchase successful! Total cost: $" << totalCost << "\n";
            cout << "Remaining stock: " << stock << "\n";
        } else {
            unsuccessfulTransactions++;
            cout << "Purchase unsuccessful. Not enough stock available.\n";
        }
    }

    // Getter for stock
    int getStock() {
        return stock;
    }
};

// Initialize static data members
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

int main() {
    const int MAX_BOOKS = 100;
    Book inventory[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add book\n";
        cout << "2. Update book\n";
        cout << "3. Search book\n";
        cout << "4. Purchase book\n";
        cout << "5. Display transaction counts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (numBooks < MAX_BOOKS) {
                string title, author, publisher;
                float price;
                int stock;

                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter publisher: ";
                cin >> publisher;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter stock: ";
                cin >> stock;

                inventory[numBooks].addUpdateBook(title, author, publisher, price, stock);
                numBooks++;

                cout << "Book added successfully.\n";
            } else {
                cout << "Inventory is full. Cannot add more books.\n";
            }
        } else if (choice == 2) {
            string title, author, publisher;
            float price;
            int stock;

            cout << "Enter book title to update: ";
            cin >> title;

            bool found = false;
            for (int i = 0; i < numBooks; i++) {
                if (inventory[i].searchBook(title)) {
                    cout << "Enter new author: ";
                    cin >> author;
                    cout << "Enter new publisher: ";
                    cin >> publisher;
                    cout << "Enter new price: ";
                    cin >> price;
                    cout << "Enter new stock: ";
                    cin >> stock;

                    inventory[i].addUpdateBook(title, author, publisher, price, stock);
                    found = true;
                    cout << "Book updated successfully.\n";
                    break;
                }
            }

            if (!found) {
                cout << "Book not found.\n";
            }
        } else if (choice == 3) {
            string title;
            cout << "Enter book title to search: ";
            cin >> title;

            bool found = false;
            for (int i = 0; i < numBooks; i++) {
                if (inventory[i].searchBook(title)) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found.\n";
            }
        } else if (choice == 4) {
            string title;
            int quantity;
            cout << "Enter book title to purchase: ";
            cin >> title;
            cout << "Enter quantity to purchase: ";
            cin >> quantity;

            bool found = false;
            for (int i = 0; i < numBooks; i++) {
                if (inventory[i].searchBook(title)) {
                    inventory[i].purchaseBook(quantity);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found.\n";
                Book::unsuccessfulTransactions++;
            }
        } else if (choice == 5) {
            cout << "Successful transactions: " << Book::successfulTransactions << "\n";
            cout << "Unsuccessful transactions: " << Book::unsuccessfulTransactions << "\n";
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

