#pragma once
#include<iostream>
using namespace std;
template<class T>
struct node
{
	T data;
	node<T>* next;
};

template<class T>
class singlylinklist
{
	node<T>* head;
	node<T>* tail;
	int size;
	node<T>** array;
	int arraysize;
	
	
public:
	singlylinklist()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
		arraysize = 0;
		array = nullptr;
	}
	void AddOnTail(T dataa)
	{
		node<T>* temp = new node<T>();
		temp->data = dataa;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;

		}
		size++;
	
	}
	void AddOnFront(T dataa)
	{
		node<T>* temp = new node<T>();
		temp->data = dataa;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			 head=temp;

		}
		size++;

	}
	void RemoveFromEnd()
	{
		node<T>* temp = head;
		while (temp->next!=tail)
		{
			temp = temp->next;
		}
		temp->next = nullptr;
		tail = temp;
		size--;
	}
	void RemoveFromFront()
	{
		node<T>* temp = head;
		head = head->next;
		temp->next = nullptr;
		size--;
	}
	bool isempty()
	{
		if (head == nullptr)
		{
			return true;
		}
	}
	int getsize()
	{
		return this-> size;
	}
	void removeDuplicates()
	{
		node<T>* temp = head;



		while (1) {

			

			if (temp == nullptr) {
				break;
			}



			node<T>* temp2 = temp->next;
			node<T>* previousNode = temp;



			while (true) {



				if (temp2 == nullptr) {
					break;
				}



				if (temp->data == temp2->data) {    //NODE TO DELETE
					node<T>* nodeToDelete = temp2;
					previousNode->next = temp2->next;
					temp2 = temp2->next;
					delete nodeToDelete;
					nodeToDelete = nullptr;
				}
				else {
					previousNode = temp2;
					temp2 = temp2->next;
				}



			}



			temp = temp->next;
		}



	}
	//code is updated now useless
	void SearchDuplicates()
	{
		node<T>* temp = head;
		node<T>* search = head;
		array = new node<T>*[size];
		int i = 0;
		int j = 0;
		while (i<size+1)
		{
			do
			{

				if ((temp->next!=search->next)&&((temp->data)==(search->data)))
				{
					array[j] = temp;
					j++;
					arraysize--;
				}
				temp = temp->next;
			}
			while (temp != nullptr);
			search = search->next;
			i++;

		}
	}
	T Front()
	{
		return head->data;
	}
	T Back()
	{
		return tail->data;
	}
	void display()
	{
		cout << "displaying all the nodes \n";
 		node<T>* temp = new node<T>();
		temp = head;
		cout << temp->data  << '\n';
		while (temp->next != nullptr)
		{
			temp = temp->next;
			cout << temp->data<< '\n';

		}
	}

};
