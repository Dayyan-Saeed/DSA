#include<iostream>
using namespace std;

struct NodeType{
	int value;
	NodeType* next;
};

class TheLinkedList{
protected:
	int TotalSize;
	NodeType *First;

public:
	TheLinkedList()
	{
		First = nullptr;
	}

	void BubbleSort()
	{
		if (First == nullptr)
		{
			return;
		}
		else
		{
			NodeType *current = First;
			NodeType *Temporary = current->next;
			for (int itr = 0; itr < TotalSize - 1; itr++)
			{
				for (int itr_2 = 0; itr_2 < TotalSize - itr - 1; itr_2++)
				{
					if (current->value > Temporary->value)
					{
						Swapping(current, Temporary);
					}
					current = Temporary;
					Temporary = current->next;
				}
				current = First;
				Temporary = current->next;
			}
		}
	}

	void Swapping(NodeType* cur, NodeType* Temporary){
		int temp = cur->value;
		cur->value = Temporary->value;
		Temporary->value = temp;
	}

	int DeletionFromTail(){
		if (First == nullptr){
			cout << "Dear User, The Linked List Is Empty... " << endl;
			return NULL;
		}
		else if (First->next == nullptr){
			int value = First->value;
			delete First;
			First = nullptr;
			TotalSize--;
			return value;
		}
		else{
			NodeType *Temporary = First;
			NodeType *Trail = nullptr;
			while (true){
				if (Temporary->next == nullptr)
					break;
				Trail = Temporary;
				Temporary = Temporary->next;
			}
			int value = Temporary->value;
			delete Temporary;
			Trail->next = nullptr;
			TotalSize--;
			return value;
		}
	}

	void InsertionAtTail(int value){
		NodeType *Temporary = new NodeType;
		Temporary->value = value;
		Temporary->next = nullptr;

		if (First == nullptr){
			First = Temporary;
			TotalSize++;
		}
		else{
			NodeType *temp = First;
			while (true){
				if (temp->next == nullptr)
					break;
				temp = temp->next;
			}
			temp->next = Temporary;
			TotalSize++;
		}
	}

	void Show_LinkedList(){
		if (First == nullptr)
			cout << "Dear User, The Linked List Is Empty... " << endl;
		else{
			NodeType *Temporary;
			Temporary = First;
			while (true){
				cout << Temporary->value << " ";
				Temporary = Temporary->next;

				if (Temporary == nullptr)
					break;
			}
			cout << endl;
		}
	}
};

int main(){

	TheLinkedList list;
	list.InsertionAtTail(2);
	list.InsertionAtTail(5);
	list.InsertionAtTail(1);
	list.InsertionAtTail(3);
	list.InsertionAtTail(1);
	list.InsertionAtTail(2);
	list.InsertionAtTail(5);
	list.InsertionAtTail(2);
	list.InsertionAtTail(4);
	cout << "-------------------------------------------------------" << endl;

	cout <<endl<< "Linked List Values Before Sorting: ";
	list.Show_LinkedList();
	cout<<endl << "-------------------------------------------------------" << endl;

	list.BubbleSort();

	cout <<endl<< "Linked List Values After Sorting : ";
	list.Show_LinkedList();
	cout<<endl << "-------------------------------------------------------" << endl;
	return 0;
}