#include<iostream>
using namespace std;

struct Node{
	int Value;
	Node* next;
};

class TheLinkedList{
protected:
	int TotalSize;
	Node *First;

public:
	TheLinkedList()
	{
		TotalSize = 0;
	}

	int DeletionOfMiddleVal()
	{
		if (First == nullptr)
		{
			cout << "Dear User, The Linked List Is Empty." << endl;
			return NULL;
		}
		int mid = 0;
		if (TotalSize % 2 == 0)
		{
			mid = TotalSize / 2;
		}
		else
		{
			mid = (TotalSize / 2) + 1;
		}
		
		if (First->next == nullptr)
		{
			int Input = First->Value;
			delete First;
			First = nullptr;
			return Input;
		}

		Node *Temporary = First;
		Node *Trail = First;
		while (true)
		{
			if (mid <= 1)
				break;
			Trail = Temporary;
			Temporary = Temporary->next;
			mid--;
		}
		if (Temporary == First)
		{
			int Input = First->Value;
			First = Temporary->next;
			delete Temporary;
			Temporary = nullptr;
			Trail = nullptr;
			return Input;
		}
		else
		{
			int Input = Temporary->Value;
			Trail->next = Temporary->next;
			delete Temporary;
			Temporary = nullptr;
			return Input;
		}
	}

	int DeletionFromTail(){
		if (First == nullptr){
			cout << "Dear User, The Linked List Is Empty." << endl;
			return NULL;
		}
		else if (First->next == nullptr){
			int Input = First->Value;
			delete First;
			First = nullptr;
			TotalSize--;
			return Input;
		}
		else{
			Node *Temporary = First;
			Node *Trail = nullptr;
			while (true){
				if (Temporary->next == nullptr)
					break;
				Trail = Temporary;
				Temporary = Temporary->next;
			}
			int Input = Temporary->Value;
			delete Temporary;
			Trail->next = nullptr;
			TotalSize--;
			return Input;
		}
	}

	void InsertionAtTail(int Input){
		Node *Temporary = new Node;
		Temporary->Value = Input;
		Temporary->next = nullptr;

		if (First == nullptr){
			First = Temporary;
			TotalSize++;
		}
		else{
			Node *t = First;
			while (1){
				if (t->next == nullptr)
					break;
				t = t->next;
			}
			t->next = Temporary;
			TotalSize++;
		}
	}

	void Show_LinkedList()
	{
		if (First == nullptr)
		{
			cout << "Linked List Is Empty." << endl;
		}
		else
		{
			Node *Temporary;
			Temporary = First;
			while (true)
			{
				cout << Temporary->Value << " ";
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
	list.InsertionAtTail(10);
	list.InsertionAtTail(20);
	list.InsertionAtTail(30);
	list.InsertionAtTail(40);
	list.InsertionAtTail(50);

	cout << "-------------------------------------------------------" << endl;

	cout << endl << "Linked List Values Before Mid Deletion: ";
	list.Show_LinkedList();
	cout << endl << "-------------------------------------------------------" << endl;

	list.DeletionOfMiddleVal();

	cout << endl << "Linked List Values After Mid Deletion : ";
	list.Show_LinkedList();
	cout << endl << "-------------------------------------------------------" << endl;

	return 0;
}