#include "MyDoublyLinkedList.h"
void menu();
int main()
{
	MyDoublyLinkedList<int> list;
	int choice = 0;
	while (choice != 13)
	{
		menu();
		cout << "\t\t\t Enter Choice: "; cin >> choice;
		switch (choice)
		{
		case 1:
		{ 
				  int value = 0;
				  cout << "\t\t\t Enter Value You want to Insert: "; cin >> value;
				  list.insertAtFront(value);
				  break;
		}
		case 2:
		{
				  int value = 0;
				  cout << "\t\t\t Enter Value You want to Insert: "; cin >> value;
				  list.insertAtEnd(value);
				  break;
		}
		case 3:
		{
				  int value = 0, pos = 0;
				  cout << "\t\t\t Enter Position at which You want to Insert the Value: "; cin >> pos;
				  cout << "\t\t\t Enter Value You want to Insert: "; cin >> value;
				  list.insertAt(pos, value);
				  break;
		}
		case 4:
		{
				  list.removeFromFront();
				  break;
		}
		case 5:
		{
				  list.removeFromEnd();
				  break;
		}
		case 6:
		{
				  int value = 0;
				  cout << "\t\t\t Enter Value You want to Search: "; cin >> value;
				  bool flag = false;
				  flag = list.search(value);
				  if (flag)
					  cout << "\t\t\t Value Found!" << endl;
				  else
					  cout << "\t\t\t Value Not Found." << endl;
				  break;
		}
		case 7:
		{
				  list.reverseList();
				  break;
		}
		case 8:
		{
				  list.getTotalSum();
				  break;
		}
		case 9:
		{
				  list.swapHeadAndTail();
				  break;
		}
		case 10:
		{
				   list.removeDuplicates();
				   break;
		}
		case 11:
		{
				   MyDoublyLinkedList<int> list2;
				   // Inserting Random Values
				   list2.insertAtFront(2);
				   list2.insertAtEnd(4);
				   list2.insertAtEnd(6);
				   list2.insertAtEnd(8);
				   list2.insertAt(0, 0);
				   list.shuffleMerge(list2);
				   break;

		}
		case 12:
		{
				   list.display();
				   break;
		}
		case 13:
		{
				   cout << "\t\t\t ----------------------------------------------" << endl;
				   cout << "\t\t\t Exiting Program.. Thanks for Checking it out!" << endl;
				   cout << "\t\t\t ----------------------------------------------" << endl;
				   break;
		}
		default:
		{
				   cout << "\t\t\t Invalid Choice!" << endl;
				   break;
		}
		}
	}
	system("pause");
	return 0;
}

void menu()
{
	cout << "\t\t\t--------------------------------------------------------------------------" << endl;
	cout << "\t\t\t 1. Insert At Front\t2. Insert At End\t3. Insert At Position" << endl;
	cout << "\t\t\t 4. Remove From Front\t5. Remove From End\t6. Search Value" << endl;
	cout << "\t\t\t 7. Reverse List\t8. Total Sum\t\t9. Swap Head and Tail" << endl;
	cout << "\t\t\t 10. Remove Duplicates\t11. Shuffle Merge Lists" << endl;
	cout << "\t\t\t 12. Display List\t13. Exit Program" << endl;
	cout << "\t\t\t--------------------------------------------------------------------------" << endl;
}