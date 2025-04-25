#pragma once
#include<iostream>
using namespace std;
struct node
{
	node* next;
	int data;

};
class linklistheadonly
{
private:
	node* head;
	int size;
public:
	linklistheadonly()
	{
		head = nullptr;
		size = 0;
	}

	void insertAtFront(int data)
	{
		size++;
		node* temp = new node();
		temp->data = data;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;

		}
		else
		{
			temp->next = head;
			head = temp;

		}

	}
	void insertAtEnd(int data)
	{
		size++;
		if (head == nullptr)
		{
			insertAtFront(data);

		}
		else
		{
			node* temp = new node;
			temp->data = data;
			temp->next = nullptr;
			node* move = head;
			while (move->next != nullptr)
			{
				move = move->next;

			}
			move->next = temp;

		}
	}
	void printList()
	{
		node* temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << "\n";
			temp = temp->next;

		}

	}
	void removeFromFront()
	{
		node* temp = head->next;
		head->next = nullptr;
		delete head;
		head = temp;
		size--;
	}
	void removeFromEnd()
	{
		node* move = head;
		while (move->next->next != nullptr)
		{
			move = move->next;

		}
		node* temp = move;
		move = move->next;
		temp->next = nullptr;
		delete move;


	}
	bool isempty()
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}

	int getsize()
	{
		return size;
	}

	int getHead()
	{
		return head->data;
	}
	int getTail()
	{
		node* move = head;
		while (move->next != nullptr)
		{
			move = move->next;

		}
		return move->data;

	}
	void remove(int starting, int ending)
	{
		node* move = head->next;
		node* prev = head;
		int i = 0;
		while (move != nullptr)
		{
			if (starting == 0)
			{
				removeFromFront();
			}
			else if ((i >= starting) && (i < ending))
			{
				prev->next = move->next;
				move = prev->next;
				//move->data = 67;





			}
			i++;
			prev = prev->next;
			move = move->next;


		}


	}
	void insertAtPosition(int index, int data)
	{
		
		int i = 0;
		node* temp = new node;
		temp->next = nullptr;
		temp->data = data;
		bool headbool = 0;
		bool tailbool = 0;
		if (index==0)
		{
			insertAtFront(data);
			headbool = 1;
		}
		else if (index>=size)
		{
			tailbool = 1;
			insertAtEnd(data);

		}
		node* move = head;

		
		while (move != nullptr)
		{
			if ((headbool)||(tailbool))
			{
				break;
			}
			i++;
			if (i == index)
			{
				temp->next = move->next->next;
				move->next = temp;


			}
			
			move = move->next;
			size++;

		}

	}



	void RemovefromPosition(int index)
	{

		int i = 0;
		
		node* temp=head->next;
		
		bool headbool = 0;
		bool tailbool = 0;
		if (index == 0)
		{
			removeFromFront();
			headbool = 1;
		}
		else if (index >= size)
		{
			tailbool = 1;
			removeFromEnd();

		}
		node* move = head;


		while (move != nullptr)
		{
			if ((headbool) || (tailbool))
			{
				break;
			}
			i++;
			if (i == index)
			{
				 
				temp->next = move->next;
				move->next = nullptr;
				move = temp;
				


			}

			move = move->next;
			temp = temp->next;

		}

	}
	void insertSorted(int data)
	{
		insertAtEnd(data);
		node* temp = head;
		node* move = head;
		while (temp!=nullptr)
		{
			while (move!=nullptr)
			{
				if (temp->data<move->data)
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


};