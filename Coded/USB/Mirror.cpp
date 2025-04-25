#include <iostream>
using namespace std;
struct Node
{
	Node* left;
	Node* right;
	int info;
};
class BST
{
public:
	Node* root;
	BST()
	{
		this->root = NULL;
	}
	void insert(Node* &n, int key)
	{
		if (n == NULL)
		{
			Node* temp = new Node();
			temp->info = key;
			temp->left = NULL;
			temp->right = NULL;
			n = temp;
			return;
		}
		else if (key<n->info)
		{
			insert(n->left, key);
		}
		else if (key>n->info)
		{
			insert(n->right, key);
		}
		else
		{
			cout << "Duplicate values are not allowed." << endl;
			return;
		}
	}
	void display(Node* n)
	{
		if (n == NULL)
		{
			return;
		}
		else
		{
			display(n->left);
			cout << n->info << " ";
			display(n->right);
		}
	}
	void mirror(Node* n)
	{
		if (n == NULL)
		{
			return;
		}
		else
		{
			mirror(n->left);
			mirror(n->right);
			Node* temp;
			temp = n->left;
			n->left = n->right;
			n->right = temp;
		}
	}

};

int main()
{
	BST B1;
	B1.insert(B1.root, 1);
	B1.insert(B1.root, 2);
	B1.insert(B1.root, 3);
	B1.insert(B1.root, 4);
	B1.insert(B1.root, 5);
	B1.display(B1.root);
	cout << endl;
	B1.mirror(B1.root);
	B1.display(B1.root);
	cout << endl;

	system("Pause");
	return 0;
}