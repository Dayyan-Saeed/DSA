#include <iostream>
using namespace std;
template <class Type>
struct Node
{
	Type info;
	Node* next;
};
template <class Type>
class LinkedList
{
protected:
	Node<Type>* head;
	Node<Type>* tail;
public:
	virtual void insertAtFront(Type) = 0;
	virtual void insertAtEnd(Type) = 0;
	virtual Type removeFromFront() = 0;
	virtual Type removeFromEnd() = 0;
	virtual Type front() = 0;
	virtual Type back() = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
};
template <class Type>
class MyLinkedList : public LinkedList<Type>
{

public:
	void insertAtFront(Type info)
	{
		Node<Type>* newnode = new Node<Type>();
		newnode->info = info;
		newnode->next = nullptr;
		if ((head == nullptr) && (tail == nullptr))
		{
			tail = newnode;
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
			newnode = nullptr;
		}
	}
	void insertAtEnd(Type info)
	{
		Node<Type>* newnode = new Node<Type>();
		newnode->info = info;
		newnode->next = nullptr;
		if ((head == nullptr) && (tail == nullptr))
		{
			tail = newnode;
			head = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = tail->next;
			newnode = nullptr;
		}
	}
	Type removeFromFront()
	{
		if (empty())
		{
			cout << "LinkList is empty" << endl;
		}
		else if (head == tail)
		{
			Type temp = head->info;
			tail = nullptr;
			delete[] head;
			head = nullptr;
			return temp;
		}
		else
		{
			Type temp1 = head->info;
			Node<Type>* temp = head;
			head = head->next;
			delete[] temp;
			temp = nullptr;
			return temp1;
		}
		return NULL;
	}
	Type removeFromEnd()
	{
		if (empty())
		{
			cout << "LinkList is empty" << endl;
		}
		else if (head == tail)
		{
			Type temp = tail->info;
			head = nullptr;
			delete[] tail;
			tail = nullptr;
			return temp;
		}
		else
		{
			Node<Type>* curr = head;
			while (true)
			{
				if (curr->next->next == nullptr)
				{
					Type temp1 = curr->next->info;
					tail = curr;
					curr = curr->next;
					tail->next = nullptr;
					delete[] curr;
					curr = nullptr;
					return temp1;
				}
				curr = curr->next;
			}
		}
		return NULL;
	}
	Type front()
	{
		if (!empty())
		{
			return head->info;
		}
		return NULL;
	}
	Type back()
	{
		if (!empty())
		{
			return tail->info;
		}
		return NULL;
	}
	bool empty()
	{
		if ((head == nullptr) && (tail == nullptr))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int size()
	{
		if (!empty())
		{
			int countsize = 0;
			Node<Type>* curr = head;
			while (true)
			{
				if (curr == tail)
				{
					countsize++;
					break;
				}
				curr = curr->next;
				countsize++;
			}
			return countsize;
		}
		return NULL;
	}
	void display()
	{
		if (!empty())
		{
			Node<Type>* curr = head;
			while (true)
			{
				cout << curr->info << " ";
				curr = curr->next;
				if (curr == nullptr)
				{
					break;
				}
			}
			cout << endl;
		}
		else
		{
			cout << "LinkList is empty" << endl;
		}
	}
	void deleteNode(const Type& deleteItem)
	{
		Node<Type> *current; //pointer to traverse the list
		Node<Type> *currnext; //pointer just before current
		bool found;
		if (head == nullptr) //Case 1; the list is empty.
			cout << "Cannot delete from an empty list."
			<< endl;
		else
		{
			if (head->info == deleteItem) //Case 2
			{
				current = head;
				head = head->next;
				//count--;
				if (head == NULL) //the list has only one node
					tail = NULL;
				delete current;
			}
			else //search the list for the node with the given info
			{
				found = false;
				currnext = head; //set currnext to point
				//to the head node
				current = head->next; //set current to point to
				//the second node
				while (current != NULL && !found)
				{
					if (current->info != deleteItem)
					{
						currnext = current;
						current = current->next;
					}
					else
						found = true;
				}//end while
				if (found) //Case 3; if found, delete the node
				{
					currnext->next = current->next;
					//count--;
					if (tail == current) //node to be deleted was the
						//tail node
						tail = currnext; //update the value of tail
					delete current; //delete the node from the list
				}
				else
					cout << "The item to be deleted is not in "
					<< "the list." << endl;
			}//end else
		}//end else
	}//end deleteNode
};

int main()
{
	MyLinkedList<int> L1;
	L1.insertAtEnd(4);
	L1.insertAtFront(5);
	L1.insertAtEnd(2);
	L1.deleteNode(4);
	L1.insertAtEnd(9);
	L1.insertAtFront(7);
	L1.display();
	cout << L1.front();
	cout << L1.back();
	return 0;
}