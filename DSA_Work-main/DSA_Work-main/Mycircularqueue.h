#pragma once
// q1 and q3
#include<iostream>
using namespace std;
template<class T>
class Mycircularqueue
{
	T* arr;
	int rear;
	int front;
	int numOfelement;
	int maxsize;
public:
	Mycircularqueue()
	{
		arr = nullptr;
		rear = 0;
		front = 0;
		numOfelement = 0;
		maxsize = 0;
		
	}
	Mycircularqueue(int size)
	{
		maxsize = size;
		arr = new T[maxsize];

	}
	Mycircularqueue(Mycircularqueue& obj)
	{
		
		
		for (int i = 0; i < obj.numOfelement; i++)
		{
			arr[i] = obj.arr[i];
		}
		numOfelement = obj.numOfelement;
		rear = obj.rear;
		maxsize = obj.maxsize;
		front = obj.front;


	}
	void enqueue(T data)
	{
		if (isfull())
		{
			cout << "circular queue is full your data can be overwritten\n";
		}
		Mycircularqueue<T>::rear = Mycircularqueue<T>::rear % Mycircularqueue<T>::maxsize;
		Mycircularqueue<T>::arr[Mycircularqueue<T>::rear++] = data;
		Mycircularqueue<T>::numOfelement++;

	}
	T dequeue()
	{  
		if (!isempty())
		{
			Mycircularqueue<T>::front = Mycircularqueue<T>::front % Mycircularqueue<T>::maxsize;
			Mycircularqueue<T>::numOfelement--;
			return Mycircularqueue<T>::arr[Mycircularqueue<T>::front++];
		}
		else
		{
			cout << "circular queue is empty\n";
		}
	}
	bool isempty()
	{
		if (numOfelement==0)
		{
			return true;
		}
		return false;
	}
	bool isfull()
	{
		if (numOfelement == maxsize)
		{
			return true;
		}
		return false;
	}
	void isPalindrome()
	{
		T* arry = new T[numOfelement];
		int a = 0;
		arry[numOfelement] ; //mean end of array;
		for (int i = numOfelement-1; i >= 0; i--)
		{
			arry[a++] = arr[i];
			//cout << arr[i];
		}
		bool* ptr = new bool[numOfelement];
		int sum = 0;
		for (int i = 0; arr[i]!=  '\0'; i++)
		{
			if (arry[i]==arr[i])
			{
				ptr[i] = 1;
			}
			sum = sum + ptr[i];
		}
		
		if (sum==0)
		{
			cout << "isPalindrome\n";
		}
		else
		{
			cout << "not Palindrome\n";
		}
	}
	void display()
	{
		if (!isempty())
		{

			for (int i = 0; i < numOfelement; i++)
			{
				cout << arr[i] << "\n";
			}
		}
		else
		{
			cout << "circular queue is empty\n";
		}

	}
	friend	void resqueue(Mycircularqueue<T> obj);

	
};

