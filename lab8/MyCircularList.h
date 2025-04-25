#pragma once

#include "Node.h"
#include "List.h"

template<typename Type>
class MyCircularList : public List<Type> {
private:
    Node<Type>* tail;

public:
    MyCircularList() : tail(nullptr) {}

    ~MyCircularList() {
        if (tail == nullptr)
            return;

        Node<Type>* current = tail->Next;
        while (current != tail) {
            Node<Type>* next = current->Next;
            delete current;
            current = next;
        }
        delete tail;
        tail = nullptr;
    }

    bool isEmpty() {
        return (tail == nullptr);
    }

    int sizeOfList() {
        if (tail == nullptr)
            return 0;

        int count = 1;
        Node<Type>* current = tail->Next;
        while (current != tail) {
            count++;
            current = current->Next;
        }
        return count;
    }

    void insertAtFront(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->Next = tail;
        }
        else {
            newNode->Next = tail->Next;
            tail->Next = newNode;
        }
    }

    void insertAtLast(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->Next = tail;
        }
        else {
            newNode->Next = tail->Next;
            tail->Next = newNode;
            tail = newNode;
        }
    }

    void removeAtFront() {
        if (tail == nullptr)
            return;

        if (tail->Next == tail) {
            delete tail;
            tail = nullptr;
        }
        else {
            Node<Type>* temp = tail->Next;
            tail->Next = temp->Next;
            delete temp;
        }
    }

    void removeAtLast() {
        if (tail == nullptr)
            return;

        if (tail->Next == tail) {
            delete tail;
            tail = nullptr;
        }
        else {
            Node<Type>* current = tail->Next;
            while (current->Next != tail) {
                current = current->Next;
            }
            current->Next = tail->Next;
            delete tail;
            tail = current;
        }
    }

    void insertAtSpecificPosition(Type value, Type targetNodeValue) {
        Node<Type>* newNode = new Node<Type>(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->Next = tail;
        }
        else {
            Node<Type>* current = tail->Next;
            while (current != tail) {
                if (current->Data == targetNodeValue) {
                    newNode->Next = current->Next;
                    current->Next = newNode;
                    break;
                }
                current = current->Next;
            }
        }
    }

    void insertNext(Type nodeValue, Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->Next = tail;
        }
        else {
            Node<Type>* current = tail->Next;
            while (current != tail) {
                if (current->Data == nodeValue) {
                    newNode->Next = current->Next;
                    current->Next = newNode;
                    break;
                }
                current = current->Next;
            }
            if (current == tail) {
                newNode->Next
                    = tail->Next;
                tail->Next = newNode;
                tail = newNode;
            }
        }
    }

    void insertSorted(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->Next = tail;
        }
        else if (value <= tail->Data) {
            newNode->Next = tail->Next;
            tail->Next = newNode;
        }
        else {
            Node<Type>* current = tail->Next;
            while (current->Next != tail->Next && value > current->Next->Data) {
                current = current->Next;
            }
            newNode->Next = current->Next;
            current->Next = newNode;
            if (current == tail) {
                tail = newNode;
            }
        }
    }

    void sortLinkedList() {
        if (tail == nullptr || tail->Next == tail)
            return;

        Node<Type>* current = tail->Next;
        Node<Type>* index = nullptr;
        Type temp;

        do {
            index = current->Next;

            while (index != tail->Next) {
                if (current->Data > index->Data) {
                    temp = current->Data;
                    current->Data = index->Data;
                    index->Data = temp;
                }
                index = index->Next;
            }

            current = current->Next;
        } while (current != tail);
    }

    Type removeFromPosition(Type position) {
        if (tail == nullptr || position <= 0)
            return -1;

        if (position == 1) {
            Node<Type>* head = tail->Next;
            if (head == tail) {
                delete head;
                tail = nullptr;
                return -1;
            }
            else {
                tail->Next = head->Next;
                Type value = head->Data;
                delete head;
                return value;
            }
        }

        int count = 1;
        Node<Type>* current = tail->Next;
        Node<Type>* prev = tail;
        while (count < position) {
            prev = current;
            current = current->Next;
            count++;
        }

        if (current == tail)
            return -1;

        prev->Next = current->Next;
        Type value = current->Data;
        delete current;
        return value;
    }

    Type removeNext(Type nodeValue) {
        if (tail == nullptr)
            return -1;

        Node<Type>* current = tail->Next;
        while (current != tail) {
            if (current->Data == nodeValue) {
                Node<Type>* nextNode = current->Next;
                if (nextNode == tail) {
                    current->Next = tail->Next;
                    Type value = tail->Data;
                    delete tail;
                    tail = current;
                    return value;
                }
                else {
                    current->Next = nextNode->Next;
                    Type value = nextNode->Data;
                    delete nextNode;
                    return value;
                }
            }
            current = current->Next;
        }
        return -1;
    }

    void reverseListNode() {
        if (tail == nullptr || tail->Next == tail)
            return;

        Node<Type>* prev = nullptr;
        Node<Type>* current = tail->Next;
        Node<Type>* nextNode = nullptr;

        do {
            nextNode = current->Next;
            current->Next = prev;
            prev = current;
            current = nextNode;
        } while (current != tail->Next);

        tail->Next = prev;
        tail = current;
    }
};
