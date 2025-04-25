#include <iostream>
using namespace std;

class Node
{
public:
	char info;
	Node *link;
	Node(int info)
	{
		this->info = info;
		this->link = NULL;
	}
};

Node* reverse(Node* head)
{
	if (head == NULL)
		return head;

	if (head->link == NULL)
	{
		return head;
	}

	Node* prev = NULL;
	Node* cur = head;
	Node* nextnd = head->link;

	while (cur->link != NULL)
	{
		cur->link = prev;
		prev = cur;
		cur = nextnd;
		nextnd = nextnd->link;

		if (nextnd == NULL)
		{
			cur->link = prev;
			prev = cur;
			break;
		}
	}
	head = prev;
	return head;
}

bool isPalindrome(Node *head)
{
	if (head == NULL || head->link == NULL)
		return true;

	int mid = 0;
	Node* temporary = head;
	while (temporary != NULL)
	{
		mid++;
		temporary = temporary->link;
	}
	mid = mid / 2;
	temporary = head;
	while (mid--)
	{
		temporary = temporary->link;
	}

	Node* head2 = reverse(temporary);

	while (head2 != NULL && head != NULL)
	{
		if (head->info == head2->info)
		{
			head = head->link;
			head2 = head2->link;
		}
		else
			return false;

	}
	return true;
}

Node *takeinput(char* info)
{
	Node *head = NULL, *tail = NULL;
	int itr = 0;
	while (info[itr] != '\0')
	{
		Node *newnode = new Node(info[itr]);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->link = newnode;
			tail = newnode;
		}
		cout << info[itr];
		itr++;
	}
	return head;
}

int main()
{
	cout << "Dear User, Your Input is: ";
	Node *head = takeinput("madam");
	bool check = isPalindrome(head);

	if (check)
	{
		cout << endl << "Linked List Is Palindrome..." << endl;
	}
	else
	{
		cout << endl << "Linked List Is Not Palindrome..." << endl;
	}

	cout << endl;

	return 0;
}