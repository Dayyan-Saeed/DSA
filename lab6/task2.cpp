#include <iostream>

template <typename Type>
class Node {
public:
    Type data;
    Node<Type>* next;

    Node(Type data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename Type>
class MySinglyLinkedList {
private:
    Node<Type>* head;
    int size;

public:
    MySinglyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~MySinglyLinkedList() {
        Node<Type>* curr = head;
        while (curr) {
            Node<Type>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void insertAtFront(Type data) {
        Node<Type>* newNode = new Node<Type>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtEnd(Type data) {
        Node<Type>* newNode = new Node<Type>(data);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<Type>* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }

        size++;
    }

    Type removeFromFront() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node<Type>* temp = head;
        Type data = temp->data;
        head = head->next;
        delete temp;
        size--;

        return data;
    }

    Type removeFromEnd() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        if (head->next == nullptr) {
            Node<Type>* temp = head;
            Type data = temp->data;
            head = nullptr;
            delete temp;
            size--;
            return data;
        }

        Node<Type>* curr = head;
        while (curr->next->next) {
            curr = curr->next;
        }

        Node<Type>* temp = curr->next;
        Type data = temp->data;
        curr->next = nullptr;
        delete temp;
        size--;

        return data;
    }

    bool insertAt(int index, Type data) {
        if (index < 0 || index > size) {
            return false;
        }

        Node<Type>* newNode = new Node<Type>(data);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<Type>* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }

        size++;

        return true;
    }

    bool search(Type data) {
        Node<Type>* curr = head;
        while (curr) {
            if (curr->data == data) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void display() {
        Node<Type>* curr = head;
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};
