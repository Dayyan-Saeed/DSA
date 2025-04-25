#include<iostream>
#include<assert.h>
using namespace std;
class Stack
{
private:
	int *list;
	int stackTop;
	int maxstacksize;
public:
	Stack(int size)
	{
		if (size <= 0)
		{
			maxstacksize = 100;
		}
		else
		{
			maxstacksize = size;
		}
		stackTop = 0;
		list = new int[maxstacksize];
	}
	bool isemptystack() const
	{
		if (stackTop == 0)
		{
			return true;
		}
		else
			return false;
	}
	bool isfullstack() const
	{
		if (stackTop == maxstacksize)
		{
			return true;
		}
		else
			return false;
	}
	void push(int value)
	{
		if (stackTop != maxstacksize)
		{
			list[stackTop] = value;
			stackTop++;
		}
	}
	int size()
	{
		return stackTop;
	}
	int pop()
	{
		int temp = list[stackTop - 1];
		stackTop--;
		return temp;
	}
	int top() const
	{
		assert(stackTop != 0);
		return list[stackTop - 1];
	}
	~Stack()
	{
		delete[] list;
	}
	void display()
	{
		for (int i = 0; i < stackTop; i++)
		{
			cout << list[i];
		}
		cout << endl;
	}
};