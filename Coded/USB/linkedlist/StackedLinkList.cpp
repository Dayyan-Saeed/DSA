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
	void push(T value)
	{
		Node<T>* newnode = new Node<T>();
		newnode->data = value;
		newnode->next = nullptr;
		if (isempty())
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
	T pop()
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
	MyLinkedList<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.display();
	cout << stack.pop() << endl;
	stack.display();
	return 0;
}