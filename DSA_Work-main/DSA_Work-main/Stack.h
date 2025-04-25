//important note: task 1,2,3 and 5 is in this file
#include<iostream>
using namespace std;
template<typename T>
class Stack
{
private:
	T* array;
	int size;
	int current;
public:
	Stack()
	{
		Stack<T>::array = nullptr;
		Stack<T>::size = 1;
		Stack<T>::current = 0;

	}
	Stack(int siz)
	{
		Stack<T>::size = siz;
	}
	Stack(Stack& obj)
	{
		for (int i = 0; i < Stack<T>::obj.current; i++)
		{
			Stack<T>::array[i] = Stack<T>::obj.array[i];

		}
		Stack<T>::current = Stack<T>::obj.current;
		Stack<T>::size = obj.size;
		Stack<T>::current = obj.current;

	}
	//task 5
	void AscendingSort()
	{
		T max = Stack<T>::array[0];
		for (int i = 0; i < Stack<T>::current; i++)
		{
			if (Stack<T>::array[i]>max)
			{
				T temp = Stack<T>::array[i];
				Stack<T>::array[i] = max;
				max = temp;
			}
		 }
	}
	bool isfull()
	{

		if (Stack<T>::current == size)
		{

			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (Stack<T>::current <= 0)
		{
			return true;
		}
		return false;
	}
	T Top()
	{
		return Stack<T>::array[Stack<T>::current];
	}
	int Size()
	{
		return Stack<T>::size;
	}
	void push(T element)
	{
		if (Stack<T>::array == nullptr)
		{
			Stack<T>::array = new T[size];
		}
		if (isfull())
		{
			Stack<T>::size++;
			T* newarray = new T[size];
			for (int i = 0; i < Stack<T>::current; i++)
			{
				newarray[i] = Stack<T>::array[i];

			}
			delete[]Stack<T>::array;
			Stack<T>::array = newarray;


		}

		Stack<T>::array[Stack<T>::current++] = element;
	}
	T pop()
	{
		Stack<T>::current--;
		return Stack<T>::array[current];

	}
	void display()
	{
		for (int i = 0; i < Stack<T>::current; i++)
		{
			cout << Stack<T>::array[i] << "\n";
		}
		

	}
	~Stack()
	{
		delete[]Stack<T>::array;
	}
 friend	void ShowStack(Stack<T> Obj);
};
template<typename H>
void ShowStack(Stack<H> Obj)
{
	for (int i = 0; i < Stack<T>::Obj.current; i++)
	{
		cout << Stack<T>::Obj.array[i] << "\n";
	}
}
