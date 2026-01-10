#include <iostream> 
using namespace std; 
 
// Node of BST 
class Node { 
public: 
    int roll; 
    string name; 
    Node* left; 
    Node* right; 
 
    Node(int r, string n) { 
        roll = r; 
        name = n; 
        left = NULL; 
        right = NULL; 
    } 
}; 
 
// BST class 
class BST { 
private: 
    Node* root; 
 
    // Recursive insert 
    Node* insert(Node* node, int roll, string name) { 
        if (node == NULL) { 
            return new Node(roll, name); 
        } 
 
        if (roll < node->roll) 
            node->left = insert(node->left, roll, name); 
        else if (roll > node->roll) 
            node->right = insert(node->right, roll, name); 
 
        return node; 
    } 
 
    // Recursive search 
    Node* search(Node* node, int roll) { 
        if (node == NULL || node->roll == roll) 
            return node; 
 
        if (roll < node->roll) 
            return search(node->left, roll); 
        else 
            return search(node->right, roll); 
    } 
 
    // Inorder traversal 
    void inorder(Node* node) { 
        if (node == NULL) 
            return; 
 
        inorder(node->left); 
        cout << "Roll: " << node->roll 
             << ", Name: " << node->name << endl; 
        inorder(node->right); 
    } 
 
public: 
    BST() { 
        root = NULL; 
    } 
 
    void insertStudent() { 
        int roll; 
        string name; 
 
        cout << "Enter roll number: "; 
        cin >> roll; 
        cin.ignore(); 
 
        cout << "Enter student name: "; 
        getline(cin, name); 
 
        root = insert(root, roll, name); 
        cout << "Student inserted successfully.\n"; 
    } 
 
    void searchStudent() { 
        int roll; 
        cout << "Enter roll number to search: "; 
        cin >> roll; 
 
        Node* result = search(root, roll); 
        if (result != NULL) 
            cout << "Student Found → Roll: " << result->roll 
                 << ", Name: " << result->name << endl; 
        else 
            cout << "Student not found.\n"; 
    } 
 
    void displayStudents() { 
        if (root == NULL) { 
            cout << "No student records.\n"; 
            return; 
        } 
 
        cout << "Student Records (Inorder Traversal):\n"; 
        inorder(root); 
    } 
}; 
 
int main() { 
    BST tree; 
    int choice; 
 
    while (true) { 
        cout << "\n--- Student Record System (BST) ---\n"; 
        cout << "1. Insert Student\n"; 
        cout << "2. Search Student\n"; 
        cout << "3. Display Students\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                tree.insertStudent(); 
                break; 
 
            case 2: 
                tree.searchStudent(); 
                break; 
 
            case 3: 
                tree.displayStudents(); 
                break; 
 
            case 4: 
                cout << "Exiting program.\n"; 
                return 0; 
 
            default: 
                cout << "Invalid choice.\n"; 
        } 
    } 
}