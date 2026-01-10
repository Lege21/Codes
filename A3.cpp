#include <iostream> 
using namespace std; 
 
// Node structure 
class Node { 
public: 
    int roll; 
    string name; 
    Node* next; 
 
    Node(int r, string n) { 
        roll = r; 
        name = n; 
        next = NULL; 
    } 
}; 
 
// Singly Linked List class 
class StudentList { 
private: 
    Node* head; 
 
public: 
    StudentList() { 
        head = NULL; 
    } 
 
    // Insert student at end 
    void insertStudent() { 
        int roll; 
        string name; 
 
        cout << "Enter roll number: "; 
        cin >> roll; 
        cin.ignore(); 
 
        cout << "Enter student name: "; 
        getline(cin, name); 
 
        Node* newNode = new Node(roll, name); 
 
        if (head == NULL) { 
            head = newNode; 
        } else { 
            Node* temp = head; 
            while (temp->next != NULL) { 
                temp = temp->next; 
            } 
            temp->next = newNode; 
        } 
 
        cout << "Student inserted successfully.\n"; 
    } 
 
    // Delete student by roll number 
    void deleteStudent() { 
        if (head == NULL) { 
            cout << "List is empty.\n"; 
            return; 
        } 
 
        int roll; 
        cout << "Enter roll number to delete: "; 
        cin >> roll; 
 
        // If first node to be deleted 
        if (head->roll == roll) { 
            Node* toDelete = head; 
            head = head->next; 
            delete toDelete; 
            cout << "Student deleted successfully.\n"; 
            return; 
        } 
 
        Node* temp = head; 
        while (temp->next != NULL && temp->next->roll != roll) { 
            temp = temp->next; 
        } 
 
        if (temp->next == NULL) { 
            cout << "Student not found.\n"; 
        } else { 
            Node* toDelete = temp->next; 
            temp->next = toDelete->next; 
            delete toDelete; 
            cout << "Student deleted successfully.\n"; 
        } 
    } 
 
    // Display all students 
    void displayStudents() { 
        if (head == NULL) { 
            cout << "No student records.\n"; 
            return; 
        } 
 
        Node* temp = head; 
        cout << "\nStudent Records:\n"; 
        while (temp != NULL) { 
            cout << "Roll: " << temp->roll 
                 << ", Name: " << temp->name << endl; 
            temp = temp->next; 
        } 
    } 
}; 
 
int main() { 
    StudentList list; 
    int choice; 
 
    while (true) { 
        cout << "\n--- Student Record System (SLL) ---\n"; 
        cout << "1. Insert Student\n"; 
        cout << "2. Delete Student\n"; 
        cout << "3. Display Students\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                list.insertStudent(); 
                break; 
 
            case 2: 
                list.deleteStudent(); 
                break; 
 
            case 3: 
                list.displayStudents(); 
                break; 
 
            case 4: 
                cout << "Exiting program.\n"; 
                return 0; 
 
            default: 
                cout << "Invalid choice.\n"; 
        } 
    } 
}