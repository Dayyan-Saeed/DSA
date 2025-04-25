#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node* next;
};
template<class T>
class MyLinkedList
{
	int count;
	Node<T>*head;
	Node<T>*tail;
public:
	MyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	bool isempty()
	{
		return (head == nullptr&&tail == nullptr);
	}
	//insert atend
	void enqeueue(T value)
	{
		Node<T>* newnode = new Node<T>();
		newnode->data = value;
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
	T dequeue()
	{
		if (isempty())
		{
			cout << "LinkList is empty" << endl;
		}
		else if (head == tail)
		{
			T temp = head->data;
			tail = nullptr;
			delete[] head;
			head = nullptr;
			return temp;
		}
		else
		{
			T temp1 = head->data;
			Node<T>* temp = head;
			head = head->next;
			delete[] temp;
			temp = nullptr;
			return temp1;
		}
		return NULL;
	}
	void display()
	{
		if (!isempty())
		{
			Node<T>* curr = head;
			while (true)
			{
				cout << curr->data << " ";
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
};

int main()
{
	MyLinkedList<int> queue;
	queue.enqeueue(1);
	queue.enqeueue(2);
	queue.enqeueue(3);
	queue.display();

	cout << queue.dequeue() << endl;
	queue.display();

	return 0;
}