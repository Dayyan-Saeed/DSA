#pragma once
#include "Node.h"

template <class T>
class DoublyLinkedList
{
protected:
	Node<T>* head;
public:
	DoublyLinkedList();
	virtual void insertAtHead(T) = 0;
	virtual void insertAtTail(T) = 0;
	virtual T deleteFromHead() = 0;
	virtual T deleteFromTail() = 0;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
}