#include <iostream> 
using namespace std; 
 
class CustomerQueue { 
private: 
    int queue[10]; 
    int front, rear, size; 
 
public: 
    CustomerQueue(int s) { 
        size = s; 
        front = 0; 
        rear = -1; 
    } 
 
    // Add customer 
    void enqueue() { 
        int id; 
        if (isFull()) { 
            cout << "Queue is full. Cannot add customer.\n"; 
            return; 
        } 
        cout << "Enter customer ID: "; 
        cin >> id; 
        queue[++rear] = id; 
        cout << "Customer added to queue.\n"; 
    } 
 
    // Serve customer 
    void dequeue() { 
        if (isEmpty()) { 
            cout << "Queue is empty. No customer to serve.\n"; 
            return; 
        } 
        cout << "Customer served: " << queue[front++] << endl; 
    } 
 
    // Display queue 
    void display() { 
        if (isEmpty()) { 
            cout << "No customers in queue.\n"; 
            return; 
        } 
        cout << "Customers in queue:\n"; 
        for (int i = front; i <= rear; i++) { 
            cout << queue[i] << endl; 
        } 
    } 
 
    bool isEmpty() { 
        return (front > rear); 
    } 
 
    bool isFull() { 
        return (rear == size - 1); 
    } 
}; 
 
int main() { 
    int size, choice; 
    cout << "Enter queue size: "; 
    cin >> size; 
 
    CustomerQueue q(size); 
 
    while (true) { 
        cout << "\n--- Customer Service System ---\n"; 
        cout << "1. Add Customer\n"; 
        cout << "2. Serve Customer\n"; 
        cout << "3. Display Queue\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                q.enqueue(); 
                break; 
 
            case 2: 
                q.dequeue(); 
                break; 
 
            case 3: 
                q.display(); 
                break; 
 
            case 4: 
                cout << "Exiting program.\n"; 
                return 0; 
 
            default: 
                cout << "Invalid choice.\n"; 
        } 
    } 
}