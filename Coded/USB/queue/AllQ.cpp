#include<iostream>
using namespace std;
template<class Type>
class MyCircularQueue
{
	Type* arr;
	int front;
	int rear;
	int maxSize;
	int count;
public:
	MyCircularQueue()
	{
		rear = 0;
		front = 0;
		count = 0;
		maxSize = 0;
	}
	MyCircularQueue(const MyCircularQueue& obj)
	{
		rear = obj.rear;
		front = obj.front;
		maxSize = obj.maxSize;
		count = obj.count;
		arr = new Type[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	bool empty() const
	{
		if (count == 0)
		{
			return true;
		}
		else
			return false;
	}
	Type frontfun()
	{
		return this->arr[front];
	}
	bool full() const
	{
		if (count == maxSize)
		{
			return true;
		}
		else
			return false;
	}
	void enqueue(Type value)
	{
		if (!full())
		{
			arr[rear] = value;
			rear = (rear + 1) % maxSize;
			count++;
			
		}
		else
			cout << "Cannot add to a full queue." << endl;
	}
	Type dequeue()
	{
		if (!empty())
		{
			int temp = front;
			count--;
			front = (front + 1) % maxSize;
			return arr[temp];
		}
		else
			cout << "Cannot remove from an empty queue" << endl;
	}
	void initilize(int size)
	{
		if (size <= 0)
		{
			maxSize = 100;
		}
		else
			maxSize = size;
		front = 0;
		rear = 0;
		count = 0;
		arr = new Type[maxSize];
	}
	~MyCircularQueue()
	{
		delete[] arr;
	}
	const int get_size() const
	{
		return count;
	}
	void sorting()
	{
		if (!empty())
		{
			for (int i = front, k = 0; k < count; k++)
			{
				for (int j = (i + 1) % maxSize, m = k + 1; m < count; m++)
				{
					if (arr[j] < arr[i])
					{
						Type temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
					j = (j + 1) % maxSize;
				}
				i = (i + 1) % maxSize;
			}
		}
	}
	void display()
	{
		for (int i = front, j = 0; j < count; j++)
		{
			cout << arr[i] << " ";
			i = (i + 1) % maxSize;
		}
		cout << endl;
	}
};

template<class Type>
MyCircularQueue <Type>reverseQueue(MyCircularQueue <Type> &obj)
{
	Type *arr = new Type[obj.get_size()];
	int size = obj.get_size(); 
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.dequeue();
	}
	for (int i = size-1; i >= 0; i--)
	{
		obj.enqueue(arr[i]);
	}
	return obj;
}

template<class Type>
void showCircularQueue(MyCircularQueue<Type>& obj)
{
	int size = obj.get_size();
	cout << "Queue: ";
	for (int i = 0; i < size; i++)
	{
		cout << obj.frontfun() << " ";
		Type temp = obj.dequeue();
	}
	cout << endl;
}
int main()
{
	MyCircularQueue<int>q;
	q.initilize(3);

	q.enqueue(3);
	q.display();
	//showCircularQueue(q);

	q.enqueue(55);
	q.enqueue(12);
	int temp = q.dequeue();
	q.display();
	//int temp=q.dequeue();
	//temp = q.dequeue();
	// q.enqueue(123); 
	//showCircularQueue(q);
	reverseQueue(q);

	q.display();
	//	int temp = q.dequeue();
	showCircularQueue(q);
	system("pause");
	return 0;
}