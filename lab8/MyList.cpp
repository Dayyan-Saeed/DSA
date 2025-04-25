#include "Node.h"
#include "List.h"

template<typename Type>
class MyList : public List<Type> {
private:
    Node<Type>* head;

public:
    MyList() : head(nullptr) {}

    ~MyList() {
        Node<Type>* current = head;
        while (current != nullptr) {
            Node<Type>* next = current->Next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    int sizeOfList() {
        int count = 0;
        Node<Type>* current = head;
        while (current != nullptr) {
            count++;
            current = current->Next;
        }
        return count;
    }

    void insertAtFront(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        newNode->Next = head;
        head = newNode;
    }

    void insertAtLast(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<Type>* current = head;
            while (current->Next != nullptr) {
                current = current->Next;
            }
            current->Next = newNode;
        }
    }

    void removeAtFront() {
        if (head != nullptr) {
            Node<Type>* temp = head;
            head = head->Next;
            delete temp;
        }
    }

    void removeAtLast() {
        if (head != nullptr) {
            if (head->Next == nullptr) {
                delete head;
                head = nullptr;
            }
            else {
                Node<Type>* current = head;
                while (current->Next->Next != nullptr) {
                    current = current->Next;
                }
                delete current->Next;
                current->Next = nullptr;
            }
        }
    }

    void insertAtSpecificPosition(Type value, Type targetNodeValue) {
        Node<Type>* newNode = new Node<Type>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<Type>* current = head;
            while (current != nullptr) {
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
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<Type>* current = head;
            while (current != nullptr) {
                if (current->Data == nodeValue) {
                    if (current->Next == nullptr) {
                        current->Next = newNode;
                    }
                    else {
                        newNode->Next = current->Next;
                        current->Next = newNode;
                    }
                    break;
                }
                current = current->Next;
            }
        }
    }

    void insertSorted(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (head == nullptr || head->Data >= value) {
            newNode->Next = head;
            head = newNode;
        }
        else {
            Node<Type>* current = head;
            while (current->Next != nullptr && current->Next->Data < value) {
                current = current->Next;
            }
            newNode->Next = current->Next;
            current->Next = newNode
        }
    }

        void sortLinkedList() {
            if (head == nullptr || head->Next == nullptr)
                return;

            Node<Type>* current = head;
            Node<Type>* index = nullptr;
            Type temp;

            while (current != nullptr) {
                index = current->Next;

                while (index != nullptr) {
                    if (current->Data > index->Data) {
                        temp = current->Data;
                        current->Data = index->Data;
                        index->Data = temp;
                    }
                    index = index->Next;
                }

                current = current->Next;
            }
        }


        Type removeFromPosition(Type position) {
            if (head == nullptr || position <= 0)
                return -1;

            Node<Type>* current = head;
            Node<Type>* prev = nullptr;

            if (position == 1) {
                head = current->Next;
                Type value = current->Data;
                delete current;
                return value;
            }

            int count = 1;
            while (current != nullptr && count < position) {
                prev = current;
                current = current->Next;
                count++;
            }

            if (current == nullptr)
                return -1;

            prev->Next = current->Next;
            Type value = current->Data;
            delete current;
            return value;
        }

        Type removeNext(Type nodeValue) {
            if (head == nullptr)
                return -1;

            Node<Type>* current = head;
            while (current != nullptr && current->Data != nodeValue) {
                current = current->Next;
            }

            if (current == nullptr || current->Next == nullptr)
                return -1;

            Node<Type>* nextNode = current->Next;
            current->Next = nextNode->Next;
            Type value = nextNode->Data;
            delete nextNode;
            return value;
        }

        void reverseListNode() {
            if (head == nullptr || head->Next == nullptr)
                return;

            Node<Type>* prev = nullptr;
            Node<Type>* current = head;
            Node<Type>* nextNode = nullptr;

            while (current != nullptr) {
                nextNode = current->Next;
                current->Next = prev;
                prev = current;
                current = nextNode;
            }

            head = prev;
        }
};
    
