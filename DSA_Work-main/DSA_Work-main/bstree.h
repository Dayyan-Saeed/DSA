#pragma once
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

class bstree
{
private:
	node* root;
	void nodewithnochild(int data)
	{
		node* curr = root;
		node* parrent = root;
		node* G_parrent = root;
		while (curr != nullptr)
		{

			if (curr->data == data)
			{
				break;
			}
			G_parrent = parrent;
			parrent = curr;

			if (data > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}

		}
		if (curr!=nullptr)
		{
			if (curr->left == nullptr && curr->right == nullptr)
			{
				if (parrent->left->data == curr->data)
				{
					parrent->left = nullptr;
				}
				else
				{
					parrent->right = nullptr;
				}
			}

		}

	}
	void mirror(node* perm=nullptr)
	{
		if (perm == nullptr)
		{
			return;
		}
		mirror(perm->left);
		mirror(perm->right);
		node* temp = perm->right;
		perm->right = perm->left;
		perm->left = temp;
	}

	int leavesCount(node * temp)
	{
		if (temp == nullptr)
		{
			return 0;
		}
		if ((temp->left == nullptr) && (temp->left == nullptr))
		{
			return 1;

		}
		else
		{
			return leavesCount(temp->left) + leavesCount(temp->right);
		}
		

	}

	void del_node_With_one_Child(node* curr ,node* parrent)
	{
		 if (curr->right == nullptr)
		{
			 if (parrent->right == curr)
			 {
				 parrent->right = curr->left;
			 }
			 else
			 {
				 parrent->left = curr->left;
			 }
		}
		 else if(curr->left==nullptr)
		 {
			 if (parrent->left == curr)
			 {
				 parrent->left = curr->right;
			 }
			 else
			 {
				 parrent->right = curr->right;
			 }

		 }
	}

	int Height(node* temp)
	{
		int lheight = 0;
		int rheight = 0;
		if (temp == nullptr)
		{
			return -1;
		}
		lheight = Height(temp->left);
		rheight = Height(temp->right);
		if (lheight > rheight)
		{
			return lheight + 1;
		}
		else
		{
			return rheight + 1;

		}


	}
	void in_order(node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		in_order(temp->left);
		std::cout << temp->data << " ";
		in_order(temp->right);

	}
	void pre_Order(node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		std::cout << temp->data << " ";
		pre_Order(temp->left);
		pre_Order(temp->right);


	}
	void post_Order(node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		
		post_Order(temp->left);
		post_Order(temp->right);
		std::cout << temp->data << " ";


	}

public:
	bstree()
	{
		root = nullptr;
	}
	void insertNode(int data)
	{
		node* temp = new node;
		temp->data = data;
		temp->left = nullptr;
		temp->right = nullptr;
		if (root == nullptr)
		{
			root = temp;
		}
		else
		{
			node* curr = root;
			node* motherNode = root;

			while (curr != nullptr)
			{
				motherNode = curr;

				if (data > curr->data)
				{
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			if (data > motherNode->data)
			{
				motherNode->right = temp;
			}
			else
			{
				motherNode->left = temp;
			}
		}
	}
	
	void inorder()
	{
		node* temp = root;
		in_order(temp);
	}
	void preorder()
	{
		node* temp = root;
		pre_Order(temp);
	}
	void postorder()
	{
		node* temp = root;
		post_Order(temp);
	}
	void deleteBST(int data)
	{
		if ((data==root->data)&&(root->right==nullptr&&root->left==nullptr))
		{
			root = nullptr;
		}
		if (root == nullptr)
		{
			return;
		}
		node* curr = root;
		node* parrent = root;
		node* G_parrent = root;
		while (curr!=nullptr)
		{
		
			if (curr->data==data)
			{
				break;
			}
			G_parrent = parrent;
			parrent = curr;

			if (data>curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}

		}
		if (curr != nullptr)
		{
			if (curr->left == nullptr && curr->right == nullptr)
			{
				nodewithnochild(data);

			}
			else if (curr->left == nullptr || curr->right == nullptr)
			{
				del_node_With_one_Child(curr, parrent);
			}
			else if (curr->left != nullptr && curr->right != nullptr)
			{
				node* leftMax = curr->left;
				node* PleftMax = nullptr;
				node* mytemp = curr->left;
				
				while (mytemp != nullptr)
				{
					PleftMax = leftMax;
					leftMax = mytemp;
					mytemp = mytemp->right;
				}
				if (leftMax->left != nullptr||leftMax->right!=nullptr)
				{
					mytemp = leftMax;
					del_node_With_one_Child(leftMax, PleftMax);
					mytemp->right = curr->right;
					if (parrent->left== curr)
					{
						parrent->left = mytemp;
					}
					else
					{
						parrent->right = mytemp;
					}

				}
				else
				{
					node* temp = leftMax;
					nodewithnochild(leftMax->data);
					temp->right = curr->right;
					if (parrent->left == curr)
					{
						parrent->left = temp;
					}
					else
					{
						parrent->right = temp;
					}
					if (data==root->data)
					{
						leftMax->left = root->left;
						root = leftMax;
					}
					
					
				}


			}
			

		}
	}
	void BSTsearching(int data)
	{
		node* curr = root;
		while (curr != nullptr)
		{

			if (curr->data == data)
			{
				std::cout << "found\n";
				return;
			}
			

			if (data > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}

		}
		std::cout << "not found\n";
		return;

	}
	int BSTFindHeight()
	{
		int h = Height(root);
		return h+1;
	}
	int TotalLeaves()
	{
		int leaves = leavesCount(root);
		return leaves;
	}
	
	void BSTmirror()
	{
		mirror(root);
	}
	void find_largest_smallest(int k)
	{
		int largest = 0;
		int smallest = 0;
		if (k == 1)
		{
			largest = root->data;
			smallest = root->data;


		}
		else if (k == 2)
		{
			smallest = root->left->data;
			largest= root->right->data;
		}
		else if (k == 3)
		{
			smallest = root->left->left->data;
			largest = root->right->right->data;
		}
		cout << "smallest = " << smallest << "\n";
		cout << "largest = " << largest << "\n";

	}
	void deleteBetweenRange(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			deleteBST(i);
		}
	}

};

