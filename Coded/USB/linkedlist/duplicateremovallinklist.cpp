#include<iostream>
using namespace std;

struct Node{
	int Value;
	Node* next;
};

class TheLinkedList{
protected:
	Node *First;

public:
	TheLinkedList()
	{
		First = nullptr;
	}

	void Duplication_Removal(){
		if (First == nullptr || First->next == nullptr) {
			return;
		}
		else {
			Node *t = First;
			Node *current = First;
			while (true){
				if (current->Value == current->next->Value){
					t = current->next->next;
					delete current->next;
					current->next = t;
				}
				else{
					current = current->next;
				}
				if (current->next == nullptr)
					break;
			}
		}
	}

	void Sorted_Insertion(int input){
		Node* newNode = new Node;
		newNode->Value = input;
		newNode->next = nullptr;

		if (First == nullptr)
			First = newNode;
		else if (input <= First->Value){
			newNode->next = First;
			First = newNode;
		}
		else{
			Node *temp = First;
			while (true){
				if (temp->next == nullptr){
					break;
				}
				if (temp->next->Value >= input){
					break;
				}
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	int DeletionFromTail(){
		if (First == nullptr){
			cout << "Linked List Is Empty." << endl;
			return NULL;
		}
		else if (First->next == nullptr){
			int input = First->Value;
			delete First;
			First = nullptr;
			return input;
		}
		else{
			Node *temp = First;
			Node *Trail = nullptr;
			while (true){
				if (temp->next == nullptr)
					break;
				Trail = temp;
				temp = temp->next;
			}
			int input = temp->Value;
			delete temp;
			Trail->next = nullptr;
			return input;
		}
	}

	void Show_LinkedList(){
		if (First == nullptr)
			cout << "Linked List Is Empty." << endl;
		else{
			Node *temp;
			temp = First;
			while (true){
				cout << temp->Value << " ";
				temp = temp->next;

				if (temp == nullptr)
					break;
			}
			cout << endl;
		}
	}
};

int main(){

	TheLinkedList list;
	list.Sorted_Insertion(1);
	list.Sorted_Insertion(2);
	list.Sorted_Insertion(4);
	list.Sorted_Insertion(1);
	list.Sorted_Insertion(2);
	list.Sorted_Insertion(1);
	list.Sorted_Insertion(6);
	cout << "-------------------------------------------------------" << endl;

	cout << endl << "Linked List Values Before Duplication Removal: ";
	list.Show_LinkedList();
	cout << endl << "-------------------------------------------------------" << endl;

	list.Duplication_Removal();
	
	cout << endl << "Linked List Values After Duplication Removal : ";
	list.Show_LinkedList();
	cout << endl << "-------------------------------------------------------" << endl;
	
	return 0;
}