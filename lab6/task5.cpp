#include <iostream>
using namespace std;

template<typename Type>
class TwoWayCircularLinkedList {
private:
    struct Node {
        Type data;
        Node* next, * prev;
        Node(Type val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    int size;
public:
    TwoWayCircularLinkedList() : head(nullptr), size(0) {}

    void insertAtFront(Type val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(Type val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else {
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
        }
        size++;
    }

    void reverse() {
        if (head == nullptr) {
            return;
        }
        Node* curr = head;
        do {
            Node* temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = temp;
        } while (curr != head);
        head = head->prev;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    TwoWayCircularLinkedList<int> list;

    // Inserting elements at front
    list.insertAtFront(5);
    list.insertAtFront(4);
    list.insertAtFront(3);
    list.insertAtFront(2);
    list.insertAtFront(1);

    // Displaying the list
    cout << "Original List: ";
    list.display();

    // Reversing the list
    list.reverse();

    // Displaying the reversed list
    cout << "Reversed List: ";
    list.display();

    // Inserting elements at end
    list.insertAtEnd(6);
    list.insertAtEnd(7);

    // Displaying the list
    cout << "List after insertions at end: ";
    list.display();

    return 0;
}
