#pragma once
#include"singlylinklist.h"
template<class Q>
class QueueWithLinklest
{
	singlylinklist<Q>queueObj;
	Q front;
	Q rear;
public:
	void enqueue(Q data)
	{
		queueObj.AddOnFront(data);
	}
	Q dequeue()
	{
		queueObj.RemoveFromEnd();
	}
	Q getfront()
	{
		return queueObj.Front();
	}
	Q getrear()
	{
		return queueObj.Back();
	}
	void display()
	{
		queueObj.display();
	}



};
