#include <iostream> 
using namespace std; 
// Node of Doubly Linked List 
class Node { 
public: 
string song; 
Node* prev; 
Node* next; 
Node(string s) { 
song = s; 
        prev = NULL; 
        next = NULL; 
    } 
}; 
 
// Playlist class 
class Playlist { 
private: 
    Node* head; 
    Node* tail; 
 
public: 
    Playlist() { 
        head = NULL; 
        tail = NULL; 
    } 
 
    // Add song at end 
    void addSong() { 
        string name; 
        cout << "Enter song name: "; 
        cin.ignore(); 
        getline(cin, name); 
 
        Node* newNode = new Node(name); 
 
        if (head == NULL) { 
            head = tail = newNode; 
        } else { 
            tail->next = newNode; 
            newNode->prev = tail; 
            tail = newNode; 
        } 
 
        cout << "Song added successfully.\n"; 
    } 
 
    // Play forward 
    void playForward() { 
        if (head == NULL) { 
            cout << "Playlist is empty.\n"; 
            return; 
        } 
 
        Node* temp = head; 
        cout << "\nPlaying songs forward:\n"; 
        while (temp != NULL) { 
            cout << temp->song << endl; 
            temp = temp->next; 
        } 
    } 
 
    // Play backward 
    void playBackward() { 
        if (tail == NULL) { 
            cout << "Playlist is empty.\n"; 
            return; 
        } 
 
        Node* temp = tail; 
        cout << "\nPlaying songs backward:\n"; 
        while (temp != NULL) { 
            cout << temp->song << endl; 
            temp = temp->prev; 
        } 
    } 
}; 
 
int main() { 
    Playlist p; 
    int choice; 
 
    while (true) { 
        cout << "\n--- Music Playlist ---\n"; 
        cout << "1. Add Song\n"; 
        cout << "2. Play Forward\n"; 
        cout << "3. Play Backward\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                p.addSong(); 
                break; 
 
            case 2: 
                p.playForward(); 
                break; 
 
            case 3: 
                p.playBackward(); 
                break; 
 
            case 4: 
                cout << "Exiting playlist.\n"; 
                return 0; 
 
            default: 
                cout << "Invalid choice.\n"; 
} 
} 
}