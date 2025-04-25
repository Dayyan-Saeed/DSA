#include"Stack.h"
int main()
{
	int re = 0;
	cout << "saad\n";
	Stack<int> obj(10);
	obj.push(7);
	obj.push(3);
	obj.AscendingSort();
	//re=obj.pop();
	cout << "pop element = " << re << "\n";

	obj.display();
	
}