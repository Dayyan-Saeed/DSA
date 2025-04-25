#include<iostream>
using namespace std;
//Task 1 
template <class T>
struct Node
{
	T data;
	Node*next;
};
template<class T>
class LinkedList
{
protected:
	Node<T>* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	virtual void insertAtEnd(T) = 0;
	virtual T deleteFromHead() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
};
template<class T>
class myLL : public LinkedList<T>
{
public:
	void insertAtEnd(T value)
	{
		Node<T>* newnode = new Node < T >;
		newnode->data = value;
		newnode->next = nullptr;
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			Node<T> *temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	T deleteFromHead()
	{
		if (head == nullptr)
		{
			cout << "LL IS EMPTY" << endl;
			return NULL;
		}
		else
		{
			T removedata = head->data;
			Node<T> *temp = head;
			head = head->next;
			delete[] temp;
			return removedata;
		}
	}
	bool isEmpty()
	{
		return (head == nullptr);
	}
	void display()
	{
		if (!isEmpty())
		{
			Node<T>*curr = head;
			while (curr != nullptr)
			{
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << endl;
		}
	}
};
//Task 2 (include task 1 in it)
template<class T>
class Queue
{
protected:
	myLL<T> obj;
	int count;
public:
	Queue()
	{
		count = 0;
	}
	virtual bool isEmpty() = 0;
	virtual void enqueue(T) = 0;
	virtual T dequeue() = 0;
	virtual void display() = 0;
};
template<class T>
class myQueue : Queue < T >
{
public:
	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return (obj.isEmpty());
	}
	void enqueue(T value)
	{
		count++;
		obj.insertAtEnd(value);
	}
	T dequeue()
	{
		count--;
		return (obj.deleteFromHead());
	}
	void display()
	{
		obj.display();
	}
};
//Task 3 include task 1 and 2
template<typename T>
myQueue<T> reverseQueue(myQueue<T> &obj)
{
	int qsize = obj.size();
	myQueue<T> temp;
	for (int i = 0; i < qsize; i++)
	{
		temp.enqueue(obj.dequeue());
	}
	for (int i = 0; i < qsize; i++)
	{
		for (int j = 0; j < qsize - i; j++)
		{
			if (j == (qsize - i - 1))
			{
				obj.enqueue(temp.dequeue());
			}
			else
			{
				temp.enqueue(temp.dequeue());
			}
		}
	}
	return obj;
}
//Task 4 include all pervious task code
int main()
{
	cout << "\n\n---------- Best of Luck for the Exam ---------\n\n";
	myQueue<char> q1;
	q1.enqueue('D');
	q1.enqueue('S');
	q1.enqueue('A');
	q1.enqueue(' ');
	q1.enqueue('L');
	q1.enqueue('A');
	q1.enqueue('B');
	q1.display();
	myQueue<char> reverseQ1 = reverseQueue(q1);
	reverseQ1.display();
	system("pause");
	return 0;
}