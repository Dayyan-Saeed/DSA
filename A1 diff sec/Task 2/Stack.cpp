#include "Stack.h"

Stack::Stack(const int size)
{
	maxSize = size;
	currSize = 0;

	arr = new char[maxSize];
}

void Stack::push(const char x)
{
	if(!full())
		arr[currSize++] = x;
}

char Stack::pop()
{
	if (!empty())
	{
		currSize--;
		return arr[currSize];
	}
}

bool Stack::full() const
{
	if (maxSize == currSize)
		return true;
	return false;
}

bool Stack::empty() const
{
	if (currSize == 0)
		return true;
	return false;
}

Stack::~Stack()
{
	delete[] arr;
	arr = nullptr;

	maxSize = currSize = 0;
}