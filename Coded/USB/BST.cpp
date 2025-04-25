#pragma once
#include<iostream>
using namespace std;
struct Node
{
	Node * left;
	Node * right;
	int data;
};
class bst{
protected:
	Node * root;
public:
	bst()
	{
		root = NULL;
	}
	bool isEmpty()
	{
		return (root == NULL);
	}
	void inorder()
	{
		if (!isEmpty())
		{
			displayInorder(root);
		}
		else
		{
			cout << "NILL" << endl;
		}
	}
	void insert(int value)
	{
		insertion(root, value);
	}

	void insertion(Node *&r, int dat){
		if (r == NULL)
		{
			Node * newnode = new Node;
			newnode->data = dat;
			newnode->left = NULL;
			newnode->right = NULL;
			r = newnode;
			return;
		}
		if (dat < r->data)
		{
			insertion(r->left, dat);
		}
		else if (dat > r->data)
		{
			insertion(r->right, dat);
		}
		return;
	}
	void displayInorder(Node * root)
	{
		if (root == NULL)
		{
			return;
		}
		displayInorder(root->left);
		cout << root->data << "  ";
		displayInorder(root->right);
	}
};
int main()
{
	bst obj;
	obj.insert(2);
	obj.insert(10);
	obj.insert(3);
	obj.insert(5);
	obj.insert(4);
	obj.insert(4);
	obj.insert(1);
	cout << "inorder is:";
	obj.inorder();
	cout << endl;
}