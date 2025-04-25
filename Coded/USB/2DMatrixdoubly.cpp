#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node*right;
	Node *down;
	Node*pre;
	Node*up;
};
class ll
{
	Node*head;
public:
	ll()
	{
		head = NULL;
	}
	void construct2dll(int arr[3][3], int row, int col)
	{
		head = construct(arr, 0, 0, row, col, NULL);
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "Empty" << endl;
		}
		else
		{
			Node*dp = head;
			while (dp != NULL)
			{
				Node*rp = dp;
				while (rp != NULL)
				{
					cout << rp->data << " ";
					rp = rp->right;
				}
				cout << endl;
				dp = dp->down;
			}
		}
	}
private:
	Node * construct(int arr[3][3], int i, int j, int row, int col, Node*curr)
	{
		if (i > row - 1 || j > col - 1)
		{
			return NULL;
		}
		Node*temp = new Node;
		temp->data = arr[i][j];
		temp->pre = curr;
		temp->up = curr;
		temp->right = construct(arr, i, j + 1, row, col, curr);
		temp->down = construct(arr, i + 1, j, row, col, curr);
		return temp;
	}
};
int main()
{
	int arr[3][3] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	ll obj;
	obj.construct2dll(arr, 3, 3);
	obj.display();
	system("pause");
	return 0;
}