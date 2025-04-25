#pragma once
#include "DoublyLinkedList.h"

template <class T>
class MyDoublyLinkedList : public DoublyLinkedList<T>
{
	// Wrapper Functions
	int SUMOFLIST(Node<T>*, int); 
	int PRODUCTOFPRIME(Node<T>*, int);
	void DISPLAYEVENNUM(Node<T>*);
	int OCCURANCEOFKEY(Node<T>*, T, int&);
	void REVERSELL(Node<T>*);
	bool PALINDROMECHECK(Node<T>*, Node<T>*);
public:
	void insertAtHead(T);
	void insertAtTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void display();
	int size();

	// Lab-10 Tasks:
	int SumOfList();
	int ProductOfPrime();
	void displayEvenNum();
	int occuranceOfKey(T);
	void reverseLL();
	bool PalindromeCheck();

};

template <class T>
int MyDoublyLinkedList<T>::SumOfList()
{
	int sum = 0;
	if (head != nullptr)
		return SUMOFLIST(head, sum);
	return NULL;
}

template <class T>
int MyDoublyLinkedList<T>::SUMOFLIST(Node<T>* n, int sum)
{
	static bool flag = false;
	if (flag == true && n == head)
		return sum;
	flag = true;
	SUMOFLIST(n->next, sum + n->data);
}

template <class T>
int MyDoublyLinkedList<T>::ProductOfPrime()
{
	int product = 1;
	if (head != nullptr)
		return PRODUCTOFPRIME(head, product);
	return NULL;
}

template <class T>
int MyDoublyLinkedList<T>::PRODUCTOFPRIME(Node<T>* n, int product)
{
	static bool flag = false;
	bool prime = true;
	if (flag == true && n == head)
		return product;
	flag = true;
	for (int i = 2; i <= n->data - 1; i++)
	{
		if (n->data % i == 0)
		{
			prime = false;
			break;
		}
	}
	if (prime == true)
		product *= n->data;
	PRODUCTOFPRIME(n->next, product);
}

template <class T>
void MyDoublyLinkedList<T>::displayEvenNum()
{
	if (head != nullptr)
		DISPLAYEVENNUM(head);
}


template <class T>
void MyDoublyLinkedList<T>::DISPLAYEVENNUM(Node<T>* n)
{
	static bool flag = false;
	if (flag == true && n == head)
		return;
	if (n->data % 2 == 0)
		cout << n->data << " ";
	flag = true;
	DISPLAYEVENNUM(n->next);
}


template <class T>
int MyDoublyLinkedList<T>::occuranceOfKey(T value)
{
	int count = 0;
	if (head != nullptr)
		return OCCURANCEOFKEY(head, value, count);
	return 0;
}

template <class T>
int MyDoublyLinkedList<T>::OCCURANCEOFKEY(Node<T>* n, T value, int& count)
{
	static bool flag = false;
	if (flag == true && n == head)
		return count;
	flag = true;
	if (value == n->data)
		count++;
	OCCURANCEOFKEY(n->next, value, count);
}

template <class T>
void MyDoublyLinkedList<T>::reverseLL()
{
	if (head != nullptr)
		REVERSELL(head->prev);
}

template <class T>
void MyDoublyLinkedList<T>::REVERSELL(Node<T>* n)
{
	cout << n->data << endl;
	if (n == head)
		return;
	REVERSELL(n->prev);
}

template <class T>
bool MyDoublyLinkedList<T>::PalindromeCheck()
{
	int siz = size();
	if (head != nullptr)
		return PALINDROMECHECK(head->prev, head);
	return false;
}

template <class T>
bool MyDoublyLinkedList<T>::PALINDROMECHECK(Node<T>* p, Node<T>* n)
{
	static bool flag = true;
	if (n == p)
		return flag;
	if (p->data != n->data)
		return false;
	PALINDROMECHECK(p->prev, n->next);
}

template <class T>
void MyDoublyLinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		head->next = head;
		head->prev = head;
		newNode = nullptr;
	}
	else
	{
		head->prev->next = newNode;
		newNode->prev = head->prev;
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		newNode = nullptr;
	}
}

template <class T>
void MyDoublyLinkedList<T>::insertAtTail(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr)
	{
		head = newNode;
		head->prev = head;
		head->next = head;
		newNode = nullptr;
	}
	else
	{
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
		newNode = nullptr;
	}
}

template <class T>
T MyDoublyLinkedList<T>::deleteFromHead()
{
	if (head == nullptr)
		cout << "Linked List is Empty." << endl;
	else if (head->next == head && head->prev == head)
	{
		T returningValue = head->data;
		head->next = nullptr;
		head->prev = nullptr;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else
	{
		T returningValue = head->data;
		Node<T>* temp = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		temp->next = nullptr;
		temp->prev = nullptr;
		delete temp;
		return returningValue;
	}
	return NULL;
}

template <class T>
T MyDoublyLinkedList<T>::deleteFromTail()
{
	if (head == nullptr)
		cout << "Linked List is Empty." << endl;
	else if (head->next == head && head->prev == head)
	{
		T returningValue = head->data;
		head->prev = nullptr;
		head->next = nullptr;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else
	{
		Node<T>* temp = head->prev;
		T returningValue = temp->data;
		head->prev->prev->next = head;
		head->prev = head->prev->prev;
		temp->prev = nullptr;
		temp->next = nullptr;
		delete temp;
		temp = nullptr;
		return returningValue;
	}
	return NULL;
}

template <class T>
void MyDoublyLinkedList<T>::display()
{
	if (head == nullptr)
		cout << "Linked List is Empty." << endl;
	else
	{
		Node<T>* trail = head;
		while (true)
		{
			cout << trail->data << endl;
			trail = trail->next;
			if (trail == head)
				break;
		}
		cout << "\n\n";
	}
}

template <class T>
int MyDoublyLinkedList<T>::size()
{
	if (head != nullptr)
	{
		int s = 0;
		Node<T>* trail = head;
		while (true)
		{
			s++;
			trail = trail->next;
			if (trail == head)
				break;
		}
		return s;
	}
	return 0;
}