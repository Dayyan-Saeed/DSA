#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*p);
	void PREORDER(Node*p);
	void INORDER2(Node*p);
	void POSTORDER(Node*p);
	void TOTAL_NODES(Node*p, int&n);
public:
	void insert(int value);
	void inorder();
	void preorder();
	void inorder2();
	void postorder();
	int total_nodes();
	bool deleteValue(int value);
};

bool BST::deleteValue(int value)
{
	if (root == nullptr)
		return false;

	//single node case
	else if (root->leftChild == nullptr && root->rightChild == nullptr)
	{
		if (value == root->data)
		{
			delete root;
			root = nullptr;
			return true;
		}

		else
			return false;
	}

	//cases of root that the students might need to write themselves

	else
	{
		Node *t1 = root;		//parent pointer
		Node *t2 = root;		//child pointer

		while (true)
		{
			if (value < t2->data)
			{
				t1 = t2;
				t2 = t2->leftChild;
			}

			else
			{
				t1 = t2;
				t2 = t2->rightChild;
			}

			if (value == t2->data)
			{
				break;
			}
		}

		

		

		if (t2->leftChild != nullptr && t2->rightChild != nullptr)
		{
			Node* temp = t2;
			t1 = temp;	//t1 = temp->rightChild;
			t2 = temp->rightChild;

			while (1)
			{
				if (t2->leftChild == nullptr)
				{
					temp->data = t2->data;
					value = t2->data;
					break;
				}

				t1 = t2;	
				t2 = t2->leftChild;

			}
		}



		//leaf node case
		if (t2->leftChild == nullptr && t2->rightChild == nullptr)
		{
			if (t2->data < t1->data)	//left child
			{
				delete t2;
				t1->leftChild = nullptr;
			}

			else						// right child
			{
				delete t2;
				t1->rightChild = nullptr;
			}

			return true;

		}
		
		//single child, only right child exists:		
		else if (t2->leftChild == nullptr && t2->rightChild != nullptr)
		{
			if (t2->data < t1->data)	//left child
			{
				t1->leftChild = t2->rightChild;
				delete t2;
				t2 = nullptr;
			}

			else						// right child
			{
				t1->rightChild = t2->rightChild;
				delete t2;
				t2 = nullptr;
			}

			return true;
		}

		//single child, only left child exists:		
		else if (t2->leftChild != nullptr && t2->rightChild == nullptr)
		{
			if (t2->data < t1->data)	//left child
			{
				t1->leftChild = t2->leftChild;
				delete t2;
				t2 = nullptr;
			}

			else						// right child
			{
				t1->rightChild = t2->leftChild;
				delete t2;
				t2 = nullptr;
			}

			return true;
		}
	}
}

int BST::total_nodes()
{
	int total = 0;

	if (root == nullptr)
		return total;

	else
	{
		TOTAL_NODES(root, total);
		return total;
	}
}

void BST::TOTAL_NODES(Node*p, int&n)
{
	if (p != nullptr)
	{
		TOTAL_NODES(p->leftChild, n);
		TOTAL_NODES(p->rightChild, n);
		// if (p->leftChild == nullptr && p->rightChild==nullptr) // --> use it to count leaf nodes only
			n++;
	}
}

void BST::postorder()
{
	if (root == nullptr)
		cout << "Tree in empty" << endl;

	else
		POSTORDER(root);
}

void BST::inorder2()
{
	if (root == nullptr)
		cout << "Tree in empty" << endl;

	else
		INORDER2(root);
}

void BST::preorder()
{
	if (root == nullptr)
		cout << "Tree in empty" << endl;

	else
		PREORDER(root);
}

void BST::PREORDER(Node*p)
{
	if (p != nullptr)
	{
		cout << p->data << endl;
		PREORDER(p->leftChild);
		PREORDER(p->rightChild);
	}
}

void BST::POSTORDER(Node*p)
{
	if (p != nullptr)
	{
		POSTORDER(p->leftChild);
		POSTORDER(p->rightChild);
		cout << p->data << endl;
	}
}


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

void BST::INORDER2(Node*p)
{
	if (p != nullptr)
	{
		INORDER2(p->rightChild);
		cout << p->data << endl;
		INORDER2(p->leftChild);
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