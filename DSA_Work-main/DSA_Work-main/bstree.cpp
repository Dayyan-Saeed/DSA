#include<iostream>
#include"bstree.h"
using namespace std;
int main()
{
	bstree obj;
	obj.insertNode(70);
	obj.insertNode(40);
	obj.insertNode(80);
	obj.insertNode(45);
	obj.insertNode(35);
	obj.insertNode(75);
	obj.insertNode(85);
	obj.insertNode(81);
	obj.insertNode(74);
	obj.find_largest_smallest(3);
	obj.deleteBetweenRange(35, 45);
	cout << "\n";
	obj.inorder();
	
	
	/*while (true)
	{
		int option = 0;
		int s = 0;
		
		cout << "enter 0 for search\n";
		cout << "enter 1 for inorder print\n";
		cout << "enter 2 for preorder print\n";
		cout << "enter 3 for postorder print\n";
		cout << "enter 4 for find height\n";
		cout << "enter 5 for find total number of leaves\n";
		cout << "enter 6 for mirror the tree\n";
		cout << "enter 7 for delete a number\n";
		cout << "enter 8 for exit\n";
		cin >> option;
		if (option == 8)
		{
			cout << "exit successful\n";
			break;
		}
		switch (option)
		{
		case 0:
			
			cout << "enter number for search\n";
			cin >> s;
			obj.BSTsearching(s);
			cout << "\n\n";
			break;
		case 1:
			cout << "\n\n";
			obj.inorder();
			cout << "\n\n";
			break;
		case 2:
			cout << "\n\n";
			obj.preorder();
			cout << "\n\n";
			break;
		case 3:
			cout << "\n\n";
			obj.postorder();
			break;
		case 4:
			
			cout << "\n\n";
			
			cout << "height of BST is: " << obj.BSTFindHeight() << "\n";
			cout << "\n\n";
			break;
		case 5:
			cout << "\n\n";
			cout << "number of leaves is: " << obj.TotalLeaves();
			cout << "\n\n";
			break;
		case 6:
			cout << "\n\n";
			obj.BSTmirror();
			cout << "mirror is done now print\n";
			cout << "\n\n";
			break;
		case 7:
			cout << "enter number you want to delete\n";
			cin >> s;
			obj.deleteBST(s);
			cout << "delete successful\n";
			break;
		default:
			cout << "please enter correct option\n";
			cout << "\n\n";
			break;
		}
	}*/

	
}