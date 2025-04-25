#include <iostream>
using namespace std;

//class node
class node
{
	public:
	//attributes
	int val;
	node*left;
	node*right;
	
	//constructor
	node(int v)
	{
		val=v;
		left=right=NULL;
	}
};

//class BST
class BST
{
	//attributes
	node*root;
	
	//member functions
	public:
	
	//constructor
	BST()
	{
		root=NULL;
	}	
		
	//insert
	void insert(int v)
	{
		root=insrt(root,v);
	}
	
	//insrt
	node*insrt(node*n,int v)
	{
		if(n==NULL)
		return new node(v);
	
		if(v>n->val)
		n->right=insrt(n->right,v);
				
		else if(v<n->val)
		n->left=insrt(n->left,v);
			
		return n;
	}	
	
	//PrintInRange
	void PrintInRange(node*n,int l,int h)
	{
		if(n==NULL)
		return;
		
		PrintInRange(n->left,l,h);
		
		if(n->val>=l && n->val<=h)
		cout<<n->val<<"  ";
		
		PrintInRange(n->right,l,h);	
	}
	
	//Inorder
	void inorder(node*n)
	{
		if(n==NULL)
		return;
		
		inorder(n->left);
		cout<<n->val<<"  ";
		inorder(n->right);		
	}
	
	//getRoot
	node*getRoot()
	{
		return root;
	}
	
};

//main function
int main()
{
	BST b;
	int choice,v;
	int l,h;
	
	while(1)
	{
		//Menu
		cout<<"Press 1 to insert "<<endl;
		cout<<"Press 2 to display in given range "<<endl;
		cout<<"Press 3 to display in inorder "<<endl;
		cout<<"Press 0 to exit "<<endl;
		cout<<"Your choice : ";
		cin>>choice;
		
		//break
		if(choice==0)
		break;
		
		//insert
		else if(choice==1)
		{
			cout<<"Enter the value : ";
			cin>>v;
			
			b.insert(v);
		}
		
		//PrintInRange
		else if(choice==2)
		{
			cout<<"\nEnter the lower limit : ";
			cin>>l;
			
			cout<<"Enter the higher limit : ";
			cin>>h;
			
			cout<<"\nVALUES : ";
			b.PrintInRange(b.getRoot(),l,h);
		}
		
		//INORDER
		else if(choice==3)
		{
			cout<<"\nINORDER TRAVERSAL : ";
			b.inorder(b.getRoot());
		}
		
		cout<<"\n = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n\n";
		 
	}
	
	return 0;
}
