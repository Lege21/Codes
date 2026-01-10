#include <iostream> 
using namespace std; 
/* ---------- BOOK LINKED LIST ---------- */ 
class Book { 
public: 
    int id; 
    string title; 
    bool available; 
    Book* next; 
 
    Book(int i, string t) { 
        id = i; 
        title = t; 
        available = true; 
        next = NULL; 
    } 
}; 
 
Book* bookHead = NULL; 
 
void addBook() { 
    int id; 
    string title; 
    cout << "Enter Book ID: "; 
    cin >> id; 
    cin.ignore(); 
    cout << "Enter Book Title: "; 
    getline(cin, title); 
 
    Book* newBook = new Book(id, title); 
    newBook->next = bookHead; 
    bookHead = newBook; 
 
    cout << "Book added successfully.\n"; 
} 
 
Book* findBook(int id) { 
    Book* temp = bookHead; 
    while (temp != NULL) { 
        if (temp->id == id) 
            return temp; 
        temp = temp->next; 
    } 
    return NULL; 
} 
 
void displayBooks() { 
    if (bookHead == NULL) { 
        cout << "No books available.\n"; 
        return; 
    } 
 
    Book* temp = bookHead; 
    cout << "\nBook List:\n"; 
    while (temp != NULL) { 
        cout << "ID: " << temp->id 
             << " | Title: " << temp->title 
             << " | Available: " << (temp->available ? "Yes" : "No") << endl; 
        temp = temp->next; 
    } 
} 
 
/* ---------- USER ARRAY ---------- */ 
class User { 
public: 
    int id; 
    string name; 
    int issuedBook; // -1 if none 
}; 
 
User users[10]; 
int userCount = 0; 
 
void addUser() { 
    cout << "Enter User ID: "; 
    cin >> users[userCount].id; 
    cin.ignore(); 
    cout << "Enter User Name: "; 
    getline(cin, users[userCount].name); 
    users[userCount].issuedBook = -1; 
    userCount++; 
    cout << "User added successfully.\n"; 
} 
 
int findUser(int id) { 
    for (int i = 0; i < userCount; i++) 
        if (users[i].id == id) 
            return i; 
    return -1; 
} 
 
/* ---------- ISSUE BOOK ---------- */ 
void issueBook() { 
    int uid, bid; 
    cout << "Enter User ID: "; 
    cin >> uid; 
    cout << "Enter Book ID: "; 
    cin >> bid; 
 
    int uIndex = findUser(uid); 
    Book* book = findBook(bid); 
 
    if (uIndex == -1 || book == NULL) { 
        cout << "Invalid user or book.\n"; 
        return; 
    } 
 
    if (book->available) { 
        book->available = false; 
        users[uIndex].issuedBook = bid; 
        cout << "Book issued successfully.\n"; 
    } else { 
        cout << "Book not available.\n"; 
    } 
} 
 
/* ---------- RETURN BOOK ---------- */ 
void returnBook() { 
    int uid; 
    cout << "Enter User ID: "; 
    cin >> uid; 
 
    int uIndex = findUser(uid); 
    if (uIndex == -1 || users[uIndex].issuedBook == -1) { 
        cout << "Invalid return.\n"; 
        return; 
    } 
 
    Book* book = findBook(users[uIndex].issuedBook); 
    book->available = true; 
    users[uIndex].issuedBook = -1; 
 
    cout << "Book returned successfully.\n"; 
} 
 
/* ---------- MAIN ---------- */ 
int main() { 
    int choice; 
 
    while (true) { 
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n"; 
        cout << "1. Add Book\n"; 
        cout << "2. Display Books\n"; 
        cout << "3. Add User\n"; 
        cout << "4. Issue Book\n"; 
        cout << "5. Return Book\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: addBook(); break; 
            case 2: displayBooks(); break; 
            case 3: addUser(); break; 
            case 4: issueBook(); break; 
            case 5: returnBook(); break; 
            case 6: return 0; 
            default: cout << "Invalid choice.\n"; 
        } 
    } 
}