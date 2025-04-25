#include "Node.h"
#include <iostream>
using namespace std;

class Tree
{
protected:
	Node*root;
public:
	Tree();
	virtual void insert(int value) = 0;
	virtual void INORDER(Node*p) = 0;
};

Tree::Tree()
{
	root = nullptr;
}