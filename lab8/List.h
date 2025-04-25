template<typename Type>
class List {
public:
    virtual void insertAtFront(Type value) = 0;
    virtual void insertAtLast(Type value) = 0;
    virtual void removeAtFront() = 0;
    virtual void removeAtLast() = 0;
    virtual void insertAtSpecificPosition(Type value, Type targetNodeValue) = 0;
    virtual void insertNext(Type nodeValue, Type value) = 0;
    virtual void insertSorted(Type value) = 0;
    virtual void sortLinkedList() = 0;
    virtual Type removeFromPosition(Type position) = 0;
    virtual Type removeNext(Type nodeValue) = 0;
    virtual void reverseListNode() = 0;
};

