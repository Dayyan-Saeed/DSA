#include<iostream>
#include<assert.h>
using namespace std;

class MyCircularQueue
{
	int *list;
	int rear;
	int front;
	int maxsize;
	int count;
public:
	MyCircularQueue(int queuesize)
	{
		if (queuesize <= 0)
		{
			maxsize = 500;
		}
		else
		{
			maxsize = queuesize;
		}
		list = new int[maxsize];
		rear = maxsize - 1;
		front = 0;
		count = 0;
	}
	bool emptyqueue() const
	{
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int front_queue()
	{
		return this->list[rear - front];
	}
	bool fullqueue() const
	{
		if (count == maxsize)
		{
			return true;
		}
		else
			return false;
	}
	void enqueue(int value)
	{
		front = 0;
		if (count != maxsize)
		{
			count++;
			rear = (rear + 1) % 100;
			list[rear] = value;
		}
	}
	int dequeue()
	{
		if (count != 0)
		{
			int t = list[front];
			front++;
			count--;
			return t;
		}
	}

	~MyCircularQueue()
	{
		delete[] list;
	}
	int size()
	{
		return count;
	}
};