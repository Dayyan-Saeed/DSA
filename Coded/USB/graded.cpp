#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*next;
};
class LinkedList
{
	Node*head;
	Node*tail;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void insertAtend(int value)
	{
		Node*newnode = new Node;
		newnode->data = value;
		newnode->next = NULL;
		if (head == NULL && tail == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
	void deleteSpecifickey(int key)
	{
		if (head == NULL && tail == NULL)
		{
			return;
		}
		else
		{
			if (head->data == key)
			{
				if (head->next == NULL)
				{
					delete[] head;
					head = NULL;
					tail = NULL;

				}
				else
				{
					Node* temp = head;
					head = head->next;
					delete[] temp;
					temp = NULL;
				}
			}
			else
			{
				Node* curr = head;
				while (true)
				{
					if (curr->next->data == key)
					{
						if (curr->next == tail)
						{
							Node*temp = curr->next;
							tail = curr;
							delete[] temp;
							temp = NULL;
							break;
						}
						else
						{
							Node* temp = curr->next;
							curr->next = curr->next->next;
							delete[] temp;
							temp = NULL;
							break;
						}
					}
					curr = curr->next;
					if (curr->next == NULL)
						break;
				}
				return;
			}
		}
	}
	void display()
	{
		if (head != NULL&& tail != NULL)
		{
			Node*curr = head;
			while (curr != NULL)
			{
				cout << curr->data << " ";
				curr = curr->next;
			}
		}
	}
};
class Hash
{
	LinkedList *obj;
	int noOfBuckets;
	int currsize;
public:
	Hash()
	{
		noOfBuckets = 10;
		obj = new LinkedList[noOfBuckets];
	}
	Hash(int size)
	{
		noOfBuckets = size;
		obj = new LinkedList[noOfBuckets];
	}
	int hashfun(int key)
	{
		return key%noOfBuckets;
	}
	void insertitem(int key)
	{
		int index = hashfun(key);
		obj[index].insertAtend(key);
	}
	void deleteitem(int key)
	{
		int index = hashfun(key);
		obj[index].deleteSpecifickey(key);
	}
	void display()
	{
		for (int i = 0; i < noOfBuckets; i++)
		{
			obj[i].display();
		}
		cout << endl;
	}
};
int main()
{
	int arr[7] = { 15, 25, 32, 17, 16, 9, 10 };
	Hash obj(7);
	for (int i = 0; i < 7; i++)
	{
		obj.insertitem(arr[i]);
	}
	cout << "Before Deletion: ";
	obj.display();
	cout << "After Deleteing Key 25n: ";

	obj.deleteitem(25);
	obj.display();
	system("pause");
	return 0;
}