#include"Mycircularqueue.h"
//q
template<class T>
T* resqueue(Mycircularqueue<T> &obj)
{
	int a = 0;
	for (int i = obj.numOfelement - 1; i >= 0; i--)
	{
		obj.arr[a++] =obj.arr[i];
		
	}
	return obj.arr;

}
int main()
{
	Mycircularqueue<char> cq(5);
	cq.enqueue('s');
	cq.enqueue('o');
	cq.enqueue('d');
	cq.isPalindrome();
	 resqueue<char>(cq);
		
	cq.display();

	return 0;
}