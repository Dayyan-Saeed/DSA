#include"singlylinklist.h"
#include"StackWithLinklist.h"
#include"QueueWithLinklist.h"
int main()
{
	singlylinklist<int>li;
	li.AddOnFront(26);
	li.AddOnFront(27);
	li.AddOnFront(28);
	li.AddOnFront(29);
	li.AddOnFront(30);
	li.AddOnTail(31);
	li.AddOnFront(29);
	li.AddOnTail(31);
	//li.RemoveFromEnd();
	//li.RemoveFromFront();
	//cout << "\n" << li.Back() << "\n";
	//cout << "\n" << li.Front() << "\n";
	//cout << "\n" << li.getsize() << "\n";
//	li.SearchDuplicates();
	li.removeDuplicates();
	li.display();
	/*StackWithLinklist<int>obj;
	obj.push(37);
	obj.push(38);
	obj.push(39);
	cout << "\n" << obj.pop() << "\n";
	obj.display();*/
	/*QueueWithLinklest<int> qobj;
	qobj.enqueue(23);
	qobj.enqueue(25);
	cout << "\n" << qobj.getrear() << "\n";*/

	


}