#include <iostream> 
using namespace std; 
class Stack { 
private: 
char arr[100]; 
int top; 
 
public: 
    Stack() { 
        top = -1; 
    } 
 
    void push(char ch) { 
        arr[++top] = ch; 
    } 
 
    void pop() { 
        top--; 
    } 
 
    bool isEmpty() { 
        return (top == -1); 
    } 
 
    char peek() { 
        return arr[top]; 
    } 
}; 
 
bool isMatching(char open, char close) { 
    if (open == '(' && close == ')') return true; 
    if (open == '{' && close == '}') return true; 
    if (open == '[' && close == ']') return true; 
    return false; 
} 
 
int main() { 
    Stack s; 
    string exp; 
 
    cout << "Enter expression: "; 
    cin >> exp; 
 
    for (int i = 0; i < exp.length(); i++) { 
        char ch = exp[i]; 
 
        // If opening bracket, push 
        if (ch == '(' || ch == '{' || ch == '[') { 
            s.push(ch); 
        } 
        // If closing bracket 
        else if (ch == ')' || ch == '}' || ch == ']') { 
            if (s.isEmpty()) { 
                cout << "Not Balanced\n"; 
                return 0; 
            } 
            char topChar = s.peek(); 
            s.pop(); 
 
            if (!isMatching(topChar, ch)) { 
                cout << "Not Balanced\n"; 
                return 0; 
            } 
        } 
    } 
 
    // After complete scan 
    if (s.isEmpty()) 
        cout << "Balanced\n"; 
    else 
        cout << "Not Balanced\n"; 
 
    return 0; 
}