#include<iostream>
using namespace std;

class stack{
    private:
        int arr[10];
        int top;
        int size;

    public:
        stack(int s){
            size=s;
            top=-1;
        }

        void push()
        {
            int value;
            if(isFull())
            {
                cout<<"Stack is Overflow,cannot push\n";
                return;
            }
            cout<<"Enter value to push: ";
            cin>>value;
            arr[++top]=value;
            cout<<"Value pushed successfully.\n";
        }

        void pop()
        {
            if(isEmpty())
            {
                cout<<"Stack is Underflow,cannot pop\n";
                return;
            }
            cout<<"Popped value :"<<arr[top--]<<"\n";
        }

        void display()
        {
            if(isEmpty())
            {
                cout<<"Stack is Empty\n";
                return;
            }
            for(int i=top;i>=0;i--)
            {
                cout<<arr[i]<<endl;
            }
        }

        bool isEmpty(){
            return (top==-1);
        }

        bool isFull()
        {
            return (top==size-1);
        }
};

int main()
{
    int size,choice;
    cout<<"Enter Size of stack: ";
    cin>>size;

    stack s(size);

    while (true) { 
        cout << "\n--- Stack Operations ---\n"; 
        cout << "1. Push\n"; 
        cout << "2. Pop\n"; 
        cout << "3. Display\n"; 
        cout << "4. Check Empty\n"; 
        cout << "5. Check Full\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                s.push(); 
                break; 
 
            case 2: 
                s.pop(); 
                break; 
 
            case 3: 
                s.display(); 
                break; 
 
            case 4: 
                if (s.isEmpty()) 
                    cout << "Stack is empty.\n"; 
                else 
                    cout << "Stack is not empty.\n"; 
                break; 
 
            case 5: 
                if (s.isFull()) 
                    cout << "Stack is full.\n"; 
                else 
                    cout << "Stack is not full.\n"; 
                break; 
 
            case 6: 
                cout << "Exiting program.\n"; 
                return 0; 
 
            default: 
                cout << "Invalid choice.\n"; 
        } 
    } 
    return 0;
} 
