#include<iostream>
#include"DoublyCircularLinklink.h"
using namespace std;
int main()
{
	DoublyCircularLinklink obj;
	//obj.insertDataONhead(9);
	//obj.insertDataONhead(8);
	//obj.insertDataONhead(7);
	//obj.insertDataONhead(9);
	obj.insertDataONhead(7);
	obj.insertDataONhead(8);
	obj.insertDataONhead(3);
	obj.insertDataONhead(2);
	obj.insertDataONhead(1);
	
	//cout << obj.Count() << "\n\n\n";
	//cout << obj.GetNth(8) << "\n\n\n";
	//cout << obj.Pop() << "\n\n\n";
	//obj.DeleteList();
	//obj.RemoveDuplicates();
	DoublyCircularLinklink obj2;
	obj2.insertDataONtail(21);
	obj2.insertDataONtail(22);
	obj2.insertDataONtail(23);
	obj2.insertDataONtail(24);
	obj2.insertDataONtail(25);


	//obj.Append(obj2);
//	obj.InsertNth(8, 56);
	//DoublyCircularLinklink obj3;
	//obj3.ShuffleMerge(obj,obj2);
	obj.reverse();
	
	obj.printList();

	
}