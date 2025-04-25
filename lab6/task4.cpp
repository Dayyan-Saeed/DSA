#include <iostream>
using namespace std;

template <class Type>
class Node {
public:
    Type data;
    Node* next;
};

template <class Type>
class MySinglyLinkedList {
private:
    Node<Type>* head;
    int size;

public:
    MySinglyLinkedList() {
        head = NULL;
        size = 0;
    }

    ~MySinglyLinkedList() {
        Node<Type>* current = head;
        while (current != NULL) {
            Node<Type>* temp = current;
            current = current->next;
            delete temp;
        }
        size = 0;
    }

    void insertAtFront(Type value) {
        Node<Type>* newNode = new Node<Type>;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtEnd(Type value) {
        Node<Type>* newNode = new Node<Type>;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node<Type>* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    Type removeFromFront() {
        if (head == NULL) {
            throw "List is empty.";
        }
        Node<Type>* temp = head;
        Type value = temp->data;
        head = head->next;
        delete temp;
        size--;
        return value;
    }

    Type removeFromEnd() {
        if (head == NULL) {
            throw "List is empty.";
        }
        Type value;
        if (head->next == NULL) {
            value = head->data;
            delete head;
            head = NULL;
        }
        else {
            Node<Type>* current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            value = current->next->data;
            delete current->next;
            current->next = NULL;
        }
        size--;
        return value;
    }

    bool insertAt(int index, Type value) {
        if (index < 0 || index > size) {
            return false;
        }
        if (index == 0) {
            insertAtFront(value);
        }
        else if (index == size) {
            insertAtEnd(value);
        }
        else {
            Node<Type>* newNode = new Node<Type>;
            newNode->data = value;
            Node<Type>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
        return true;
    }

    bool search(Type value) {
        Node<Type>* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else {
            Node<Type>* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void removeDuplicates() {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            while (temp->next != nullptr) {
                if (temp->next->data == current->data) {
                    Node* duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete duplicate;
                }
                else {
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }

    void shuffleMerge(MySinglyLinkedList& list1, MySinglyLinkedList& list2) {
        if (list1.head == nullptr && list2.head == nullptr) {
            return;
        }
        else if (list1.head == nullptr) {
            head = list2.head;
            list2.head = nullptr;
            return;
        }
        else if (list2.head == nullptr) {
            head = list1.head;
            list1.head = nullptr;
            return;
        }

        Node* current1 = list1.head;
        Node* current2 = list2.head;
        Node* temp = nullptr;

        while (current1 != nullptr && current2 != nullptr) {
            if (head == nullptr) {
                if (current1->data < current2->data) {
                    head = current1;
                    current1 = current1->next;
                }
                else {
                    head = current2;
                    current2 = current2->next;
                }
                temp = head;
            }
            else {
                if (current1->data < current2->data) {
                    temp->next = current1;
                    current1 = current1->next;
                }
                else {
                    temp->next = current2;
                    current2 = current2->next;
                }
                temp = temp->next;
            }
        }

        if (current1 != nullptr) {
            temp->next = current1;
        }

        if (current2 != nullptr) {
            temp->next = current2;
        }

        list1.head = nullptr;
        list2.head = nullptr;
    }

};
