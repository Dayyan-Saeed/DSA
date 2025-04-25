#pragma once
#include "DoublyLinkedList.h"

template <class T>
class MyDoublyLinkedList : public DoublyLinkedList<T>
{
public:
	void insertAtFront(T);
	void insertAtEnd(T);
	T removeFromFront();
	T removeFromEnd();
	bool insertAt(int, T);
	bool search(T);
	int size();
	void reverseList();
	void getTotalSum();
	void swapHeadAndTail();
	void removeDuplicates();
	void shuffleMerge(const MyDoublyLinkedList<T>);
	void display();
};

template <class T>
void MyDoublyLinkedList<T>::insertAtFront(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr)
	{
		head = newNode;
		newNode = nullptr;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		newNode = nullptr;
	}
}

template <class T>
void MyDoublyLinkedList<T>::insertAtEnd(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr)
	{
		head = newNode;
		newNode = nullptr;
	}
	else
	{
		Node<T>* trail = head;
		while (trail->next != nullptr)
			trail = trail->next;
		trail->next = newNode;
		newNode->prev = trail;
		newNode = nullptr;
	}
}

template <class T>
T MyDoublyLinkedList<T>::removeFromFront()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else if (head->next == nullptr)
	{
		T returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else
	{ 
		T returningValue = head->data;
		Node<T>* temp = head;
		head->next->prev = nullptr;
		head = head->next;
		temp->next = nullptr;
		delete temp;
		temp = nullptr;
		return returningValue;
	}
	return NULL;
}

template <class T>
T MyDoublyLinkedList<T>::removeFromEnd()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		while (trail->next != nullptr)
			trail = trail->next;
		trail->prev->next = nullptr;
		Node<T>* temp = trail;
		delete temp;
	}
	return NULL;
}

template <class T>
int MyDoublyLinkedList<T>::size()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty" << endl;
	else
	{
		int size = 0;
		Node<T>* trail = head;
		while (true)
		{
			size++;
			trail = trail->next;
			if (trail == nullptr)
				break;
		}
		return size;
	}
	return NULL;
}

template <class T>
bool MyDoublyLinkedList<T>::insertAt(int index, T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (size() == 0)
	{
		head = newNode;
		newNode = nullptr;
	}
	else if (index == 0)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		newNode = nullptr;
	}
	else if (index < size())
	{
		Node<T>* trail = head;
		for (int i = 0; i < index - 1; i++)
			trail = trail->next;
		newNode->next = trail;
		newNode->prev = trail->prev;
		trail->prev->next = newNode;
		newNode = nullptr;
		trail = nullptr;
	}
	else if (index == size())
	{
		Node<T>* trail = head;
		while (trail->next != nullptr)
			trail = trail->next;
		trail->next = newNode;
		newNode->prev = trail;
		
	}
	else
		cout << "\t\t\t Index doesn't exist in Linked List yet." << endl;
	return false;
}

template <class T>
bool MyDoublyLinkedList<T>::search(T value)
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		while (trail != nullptr)
		{
			if (value == trail->data)
				return true;
			trail = trail->next;
		}
	}
	return false;
}

template <class T>
void MyDoublyLinkedList<T>::display()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		cout << "\t\t\t Linked List: " << endl;
		while (true)
		{
			cout << "\t\t\t " << trail->data << endl;
			trail = trail->next;
			if (trail == nullptr)
				break;
		}
	}
}

template <class T>
void MyDoublyLinkedList<T>::reverseList()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		Node<T>* temp = nullptr;
		int s = size();
		for (int i = 0; i < s - 1; i++)
		{
			temp = trail->prev;
			trail->prev = trail->next;
			trail->next = temp;
			trail = trail->prev;
		}
		head = trail;
		temp = head->prev;
		head->prev = head->next;
		head->next = temp;
		temp = nullptr;
		trail = nullptr;
	}
}

template <class T>
void MyDoublyLinkedList<T>::getTotalSum()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		int sum = 0;
		while (trail != nullptr)
		{
			sum += trail->data;
			trail = trail->next;
		}
		cout << "\t\t\t Sum: " << sum << endl;
		trail = nullptr;
	}
}

template <class T>
void MyDoublyLinkedList<T>::swapHeadAndTail()
{
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		while (trail->next != nullptr)
			trail = trail->next;
		T temp = head->data;
		head->data = trail->data;
		trail->data = temp;
		trail = nullptr;
	}
}

template <class T>
void MyDoublyLinkedList<T>::removeDuplicates()
{
	// It is impossible (I think so OR I can't think of it) to implement this function on a unsorted Doubly Linked List while
	// traversing only once. So, I'm implementing my logic for unsorted Doubly Linked List.
	if (head == nullptr)
		cout << "\t\t\t Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		Node<T>* innerTrail = nullptr;
		Node<T>* temp = nullptr;
		while (trail != nullptr)
		{
			innerTrail = trail->next;
			while (innerTrail != nullptr)
			{
				if (trail->data == innerTrail->data)
				{
					innerTrail->prev->next = innerTrail->next;
					innerTrail->next->prev = innerTrail->prev;
					temp = innerTrail;
					innerTrail = innerTrail->next;
					temp->next = nullptr;
					temp->prev = nullptr;
					delete temp;
				}
				else
					innerTrail = innerTrail->next;
			}
			trail = trail->next;
		}
	}
}

template <class T>
void MyDoublyLinkedList<T>::shuffleMerge(const MyDoublyLinkedList<T> list)
{
	if (head == nullptr && list.head != nullptr)
		head = list.head;
	else if (head != nullptr && list.head != nullptr)
	{
		Node<T>* trail = head;
		Node<T>* trail2 = list.head;
		Node<T>* temp = nullptr;
		while (true)
		{
			if (trail != nullptr && trail2 != nullptr)
			{
				trail2->prev = trail;
				temp = trail2->next;
				trail2->next = trail->next;
				trail->next = trail2;
				trail = trail2->next;
				trail2 = temp;
			}
			else if (trail == nullptr && trail2 != nullptr)
				trail->next = trail2;
			else
				break;
		}
	}
}