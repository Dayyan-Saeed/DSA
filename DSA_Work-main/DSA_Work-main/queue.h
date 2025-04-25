#pragma once
#include<iostream>
using namespace std;
template<class T>
class queue
{
private:
	T* arr;
	int rear;
	int front;
	int numOfelement;
	int maxsize;
public:
	queue()
	{
		rear = -1;
		front =-1;
	   numOfelement = 0;
		maxsize = 5;
	}
	queue(queue &obj)
	{
		for (int  i = 0; i < obj.numOfelement ; i++)
		{
			arr[i] = obj.arr[i];
		}
		numOfelement = obj.numOfelement;
		rear = obj.rear;
		maxsize = obj.maxsize;
		front = obj.front;
	

	}
	queue(int size)
	{
		arr = new T[size];
		maxsize = size;

	}
	void enqueue(T val)
	{
		if (isfull())
		{
			cout << "queue is full\n";
		}
		else if (isempty())
		{
			rear = 0;
			arr[rear] = val;
			rear++;
		}
		else
		{
			
			arr[rear] = val;
			rear++;
			numOfelement++;
		
		}
	}
	T dequeue()
	{
		front = 0;
		if (isempty())
		{
			cout << "stack is empty\n";
		}
		T temp = arr[front];
		for (int i = 0; i < (numOfelement - 1); i++)
		{
			arr[i] = arr[i + 1];

		}
		rear--;
		numOfelement--;
		front =- 1;
		return temp;
	}
	bool isempty()
	{
		if (rear == -1 && front == -1)
		{
			return true;
		}
		return false;
	}
	bool isfull()
	{
		if (rear == maxsize)
		{
			return true;
		}
		return false;
	}
	// task 2
	void sortQueue()
	{
		
		for (int i = 0; i < numOfelement; i++)
		{
			if (arr[i] > arr[i + 1])
			{
			  T	temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
	void display()
	{
		if (isempty())
		{
			cout << "queue is empty\n";
		}
		else
		{
			for (int i = 0; i < numOfelement; i++)
			{
				cout << "value on index " << i << " : " << arr[i]<<"\n";
			}
		}
	}
	~queue()
	{
		delete[] queue<T>::arr;
		
	}
};