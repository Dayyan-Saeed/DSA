#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*p);
public:
	void insert(int value);
	void inorder();
};

void BST::inorder()
{
	if (root == nullptr)
		cout << "Tree in empty" << endl;

	else
		INORDER(root);
}

void BST::INORDER(Node*p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << endl;
		INORDER(p->rightChild);
	}
}


void BST::insert(int value)
{
	//Node create:
	Node*nn = new Node;
	nn->data = value;
	nn->leftChild = nullptr;
	nn->rightChild = nullptr;

	if (root == nullptr) //empty tree case
		root = nn;

	else
	{
		Node*temp = root;
		while (1)
		{
			if (value < temp->data)	//left child 
			{
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = nn;
					break;
				}

				else
					temp = temp->leftChild;
			}

			else     //right child case
			{
				if (temp->rightChild == nullptr)
				{
					temp->rightChild = nn;
					break;
				}

				else
					temp = temp->rightChild;
			}
		}
	}

}