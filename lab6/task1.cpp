template <typename Type>
class Node {
public:
    Type data;
    Node<Type>* next;
};

template <typename Type>
class singlyLinkedList {
protected:
    Node<Type>* head;

public:
    singlyLinkedList() {
        head = nullptr;
    }

    virtual ~singlyLinkedList() {
        Node<Type>* curr = head;
        while (curr) {
            Node<Type>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    virtual void insertAtFront(Type) = 0;

    virtual void insertAtEnd(Type) = 0;

    virtual Type removeFromFront() = 0;

    virtual Type removeFromEnd() = 0;
};
