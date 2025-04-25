#include <iostream>
using namespace std;

template <typename Type>
class Node {
public:
    Type data;
    Node<Type>* next;
    Node<Type>(Type val) {
        data = val;
        next = NULL;
    }
};

template <typename Type>
class Stack {
private:
    Node<Type>* top;
    int size;
public:
    Stack<Type>() {
        top = NULL;
        size = 0;
    }
    void push(Type val) {
        Node<Type>* newNode = new Node<Type>(val);
        if (top == NULL) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }
    Type pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return NULL;
        }
        Type popped = top->data;
        Node<Type>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return popped;
    }
    Type peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return NULL;
        }
        return top->data;
    }
    void display() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node<Type>* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> myStack;
    int choice, value;
    while (true) {
        cout << "What would you like to do?" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            myStack.push(value);
            break;
        case 2:
            cout << "Popped value: " << myStack.pop() << endl;
            break;
        case 3:
            cout << "Top value: " << myStack.peek() << endl;
            break;
        case 4:
            cout << "Stack: ";
            myStack.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
