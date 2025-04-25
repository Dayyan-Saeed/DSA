#pragma once
#include "Node.h"

template <class T>
class DoublyLinkedList
{
protected:
	Node<T>* head;
public:
	DoublyLinkedList();
	virtual void insertAtFront(T) = 0;
	virtual void insertAtEnd(T) = 0;
	virtual T removeFromFront() = 0;
	virtual T removeFromEnd() = 0;
};	

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
}