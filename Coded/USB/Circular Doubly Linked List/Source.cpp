#include "MyDoublyLinkedList.h"

int main()
{
	MyDoublyLinkedList<int> list;
	list.insertAtHead(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.insertAtTail(4);
	list.insertAtTail(3);
	list.insertAtTail(2);
	list.insertAtTail(1);
	list.display();

	cout << "Size: " << list.size() << endl;
	cout << "Sum of List: " << list.SumOfList() << endl;
	cout << "Product of Prime: " << list.ProductOfPrime() << endl;
	cout << "Even List: ";
	list.displayEvenNum();
	cout << "\n";
	int value = 0;
	cout << "Enter Key: "; cin >> value;
	cout << "Occurance of " << value << " in List: " << list.occuranceOfKey(value) << endl;
	cout << "\nReversed Linked List: " << endl;
	list.reverseLL();
	cout << "\n\n";
	cout << "Is Palidrome: " << list.PalindromeCheck() << endl;
	system("pause");
	return 0;
}