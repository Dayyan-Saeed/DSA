void removenthnodefromtail(int t)
{
	if (!isEmpty())
	{
		if (t == count)
		{
			deleteFromHead();
		}
		else if (t <= count)
		{
			int size = count - t - 1;
			Node<T>*curr = head;
			for (int i = 0; i < size; i++)
			{
				curr = curr->next;
			}
			Node<T>*temp = curr->next;
			curr->next = curr->next->next;
			delete[] temp;
		}
	}
	else
	{
		cout << "LL IS EMPTY" << endl;
	}
}
void reverselinklist()
{
	if (head == nullptr)
	{
		cout << "LL IS EMPTY" << endl;
	}
	else if (count == 1)
	{
		return;
	}
	else
	{
		Node<T>*pre = nullptr;
		Node<T>*curr = head;
		Node<T>*nextnode;
		while (curr != nullptr)
		{
			nextnode = curr->next;
			curr->next = pre;

			pre = curr;
			curr = nextnode;
		}
		head = pre;
	}
}
using namespace std;
template<class T>
struct Node
{
	T data;
	Node<T> *next;
};
template<class T>
class MyLL
{
	Node<T>* head;
	int count;
public:
	MyLL()
	{
		head = nullptr;
		count = 0;
	}
	void insertAtEnd(T value)
	{
		count++;
		Node<T>* newnode = new Node < T >;
		newnode->data = value;
		newnode->next = nullptr;
		if (head == nullptr)
		{
			head = newnode;
			newnode = nullptr;
		}
		else
		{
			Node<T> *temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode = nullptr;
			//newnode = nullptr;
		}
	}
	void insertAtFront(T value)
	{
		count++;

		Node<T>* newnode = new Node < T >;
		newnode->data = value;
		newnode->next = nullptr;
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
			newnode = nullptr;
		}
	}
	T deleteFromHead()
	{
		count--;

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
	T deleteFromTail()
	{
		count--;
		if (head == nullptr)
		{
			cout << "LL IS EMPTY" << endl;
			return NULL;
		}
		else if (head->next == nullptr)
		{
			T removedata = head->data;
			delete head;
			head = nullptr;
			return removedata;
		}
		else
		{
			Node<T>*curr = head;
			while (curr->next->next != nullptr)
			{
				curr = curr->next;
			}
			T removedata = curr->next->data;
			delete[] curr->next;
			curr->next = nullptr;
			curr = nullptr;
			return removedata;
		}
	}
	bool isEmpty()
	{
		return (head == nullptr);
	}
	int size()
	{
		return count;
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
template<class T>
MyLL<T> sum2LinkList(MyLL<T> &obj1, MyLL<T> &obj2)
{
	MyLL<T> obj3;
	int num1 = 0, num2 = 0, carr = 0, rem = 0;
	if (obj1.size() > obj2.size())
	{
		int size = obj1.size();
		while (size != 0)
		{
			num1 = obj1.deleteFromHead();
			if (!obj2.isEmpty())
			{
				num2 = obj2.deleteFromHead();
			}
			else
			{
				num2 = 0;
			}
			int sum = num1 + num2 + carr;
			if (sum > 9)
			{
				rem = sum % 10;
				carr = sum / 10;
				obj3.insertAtEnd(rem);
			}
			else
			{
				obj3.insertAtEnd(sum);
				carr = 0;
			}
			size--;
		}
	}
	else
	{
		int size = obj2.size();
		while (size != 0)
		{
			num1 = obj2.deleteFromHead();
			if (!obj1.isEmpty())
			{
				num2 = obj1.deleteFromHead();
			}
			else
			{
				num2 = 0;
			}
			int sum = num1 + num2 + carr;
			if (sum > 9)
			{
				rem = sum % 10;
				carr = sum / 10;
				obj3.insertAtEnd(rem);
			}
			else
			{
				obj3.insertAtEnd(sum);
				carr = 0;
			}
			size--;
		}
	}
	return obj3;
}
int main()
{
	MyLL <int>obj1, obj2;
	obj1.insertAtEnd(2);
	obj1.insertAtEnd(4);
	obj1.insertAtEnd(7);
	obj1.insertAtEnd(1);
	obj2.insertAtEnd(9);
	obj2.insertAtEnd(4);
	obj2.insertAtEnd(5);
	cout << "Obj1: ";
	obj1.display();
	cout << "Obj2: ";
	obj2.display();

	MyLL<int>obj3 = sum2LinkList(obj1, obj2);
	cout << "Obj3: Obj1+Obj2 :";
	obj3.display();
	system("pause");
	return 0;
}
[1:01 AM, 5 / 21 / 2022] Amir Ucp : question 4