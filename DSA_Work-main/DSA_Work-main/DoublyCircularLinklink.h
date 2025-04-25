#pragma once
#include<iostream>
using namespace std;

struct node
{
	node* next;
	node* prev;
	int data;

};
class DoublyCircularLinklink
{
private:
	node* head;
	node* tail;
public:

	DoublyCircularLinklink()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insertDataONhead(int data)
	{
		node* temp = new node;
		temp->next = nullptr;
		temp->prev = nullptr;
		temp->data = data;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;

		}
		else
		{
			temp->prev = tail;
			temp->next = head;
			head = temp;
			tail->next = head;
		}


	}
	void insertDataONtail(int data)
	{
		node* temp = new node;
		temp->next = nullptr;
		temp->prev = nullptr;
		temp->data = data;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;

		}
		else
		{
			tail->next = temp;
			temp->next = head;
			temp->prev = tail;
			tail = temp;
			head->prev = tail;
		}


	}
	int Count()
	{
		node* temp = head;
		int length = 0;
		do
		{
			
			temp = temp->next;
			length++;

		} while (temp != head);
		return length;
	}
	void printList()
	{
		node* temp = head;
		cout << temp->data << "\n";
		temp = temp->next;
		while (temp != head)
		{
			cout << temp->data << "\n";
			temp = temp->next;

		}
		
		

	}
	int GetNth(int index)
	{
		node* temp = head;
		int i = 0;
		do
		{
			if (i==index)
			{
				return temp->data;
			}
			temp = temp->next;
			i++;

		} while (temp != head);


	}
	void DeleteList()
	{
		node* temp = head;
		node* del = temp;
		temp = temp->next;
		delete del;
		del = nullptr;
		head = nullptr;

		while (temp != nullptr)
		{
			del = temp;
			delete del;
			del = nullptr;

			temp = temp->next;


		}
		head = nullptr;
		tail = nullptr;



	}
	int Pop()
	{
		node* temp = tail;
		int dat = temp->data;
		tail = tail->prev;
		delete temp;
		temp = nullptr;
		//tail->next = nullptr;
		//tail->next = head;
		head->prev = tail;
		tail->next = head;
		return dat;


	 }
	void Append(DoublyCircularLinklink list)
	{
		node* temp = list.head;
		do
		{

			insertDataONtail(temp->data);
			temp = temp->next;
			

		} while (temp != list.head);
		//list.DeleteList();
		
		
	}
	void SortedInsert(int data)
	{
		insertDataONtail(data);
		node* temp = head;
		node* move = head;
		while (temp != nullptr)
		{
			while (move != nullptr)
			{
				if (temp->data < move->data)
				{
					int swap = temp->data;
					temp->data = move->data;
					move->data = swap;

				}
				move = move->next;

			}
			move = head;
			temp = temp->next;
		}
	}
	void InsertNth(int index,int data)
	{
		int i = 0;
		node* temp = new node;
		temp->next = nullptr;
		temp->prev = nullptr;
		temp->data = data;

		bool headbool = 0;
		bool tailbool = 0;
		int size = Count();
		if (index == 0)
		{
			insertDataONhead(data);
			headbool = 1;
		}
		
		else if (index >= size)
		{
			tailbool = 1;
			insertDataONtail(data);

		}
		node* move = head;


		while (temp != nullptr)
		{
			if ((headbool) || (tailbool))
			{
				break;
			}
			i++;
			if (i == index)
			{
				temp->next=move->next;
				move->next = temp;
				temp->prev = move;
				

			}

			move = move->next;
			

		}

	}
	void RemoveDuplicates()
	{
		node* temp=head;
		
		do
		{
			node* move = temp->next;
			while (move!=temp)
			{
				if (temp->data==move->data)
				{
					node* del = move;
					temp->next = move->next;
					move = move->next;
					delete del;
					del = nullptr;
				}
				move = move->next;

			}
			temp = temp->next;

		} while (temp != head);

		
	}
	void ShuffleMerge(DoublyCircularLinklink list1,DoublyCircularLinklink list2)
	{
		
		int list1size = list1.Count(); 
		int list2size = list2.Count();
		node* l1 = list1.head;
		node* l2 = list2.head;
		DoublyCircularLinklink result;
		int i = 3;
		while (true)
		{ 
			if (i%2==0)
			{
				result.insertDataONtail(l2->data);
				list2size--;


			}
			else
			{
				result.insertDataONtail(l1->data);
				list1size--;


			}

			if ((list1size!=0)&&(list2size!=0 ))
			{
				i++;

			}
			else if ((list1size == 0) && (list2size == 0))
			{
				break;
			}
			else if ((list1size != 0) && (list2size == 0))
			{
				
				i = 3;
			}
			else if ((list2size != 0) && (list1size == 0))
			{
				
				i = 4;
			}
			l1 = l1->next;
			l2 = l2->next;

		}
		head = result.head;



	}
	void reverse()
	{
		node* swap2 = head->next;
		node* swap = head;
		head = tail;
		tail = swap;

		
		head->prev = tail;
		tail->next = head;
		head->next->next = swap2;
	}

};
