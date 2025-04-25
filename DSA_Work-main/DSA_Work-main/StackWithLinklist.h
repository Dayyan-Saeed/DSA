#pragma once
#include"singlylinklist.h"
template<class S>
class StackWithLinklist
{
	singlylinklist<S>stackObj;
public:
	void push(S data)
	{
		stackObj.AddOnTail(data);
	}
	S pop()
	{
		S var = stackObj.Back();
		stackObj.RemoveFromEnd();
		return var;
	}
	S peek()
	{
		S var = stackObj.Back();
		stackObj.RemoveFromEnd();
		return var;

	}
	void display()
	{
		stackObj.display();
	}
};
