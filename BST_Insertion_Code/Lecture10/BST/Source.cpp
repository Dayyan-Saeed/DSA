#include "BST.h"

int main()
{
	BST bst;
	bst.insert(100);
	bst.insert(42);
	bst.insert(152);
	bst.insert(125);
	bst.insert(135);
	bst.insert(11);
	bst.insert(15);
	bst.insert(90);
	bst.insert(999);

	bst.inorder();

	return 0;
}