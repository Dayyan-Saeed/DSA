#include <iostream>
using namespace std;

//class node
class node
{
	public:
	//attributes	
	int val;
	node*prev;
	node*next;
	
	//constructor
	node(int v)
	{
		val=v;
		prev=NULL;
		next=NULL;
	}
	
};

//class doublyLinkedList 
class doublyLinkedList
{
	//attributes
	node*head;
	node*lastnode;
	
	//member functions
	public:
		
	//constructor	
	doublyLinkedList()
	{
		head=NULL;
		lastnode=NULL;
	}	
	
	//insert
	void insert(int v)
	{
		//if head is NULL
		if(head==NULL)
		{
			head=new node(v);
			lastnode=head;
		}
		
		//if head is not null
		else
		{
			lastnode->next=new node(v);
			lastnode->next->prev=lastnode;
			
			lastnode=lastnode->next;
		}
	}
	
	//getMax
	int getMax(node*n)
	{
		if(n==NULL)
		return INT_MIN;
		
		int v=getMax(n->next);
		
		if(v>n->val)
		return v;
		
		else
		return n->val;
	}
	
	//getMin
	int getMin(node*n)
	{
		if(n==NULL)
		return INT_MAX;
		
		int v=getMin(n->next);
		
		if(v<n->val)
		return v;
		
		else
		return n->val;
	}
	
	//display
	void display()
	{
		node*displaynode=head;
		
		if(displaynode!=NULL)
		{
			cout<<"\nHEAD --> ";
			while(1)
			{
				cout<<displaynode->val<<" --> ";
				displaynode=displaynode->next;
				
				if(displaynode==NULL)
				break;
			}
			cout<<"NULL"<<endl;
		}
		
		else
		cout<<"EMPTY"<<endl;
	}
	
	//getHead
	node*getHead()
	{
		return head;
	}
};

//main function
int main()
{
	doublyLinkedList dll;
	int choice;
	int v;
	
	while(1)
	{
		//Menu
		cout<<"Press 1 to insert "<<endl;
		cout<<"Press 2 to display "<<endl;
		cout<<"Press 3 to get min value "<<endl;
		cout<<"Press 4 to get max value "<<endl;
		cout<<"Press 0 to break "<<endl;
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
			
			dll.insert(v);
			dll.display();
		}
		
		//display
		else if(choice==2)
		{
			dll.display();
		}
		
		//min value
		else if(choice==3)
		{
			if(dll.getHead()!=NULL)
			cout<<"\nMinimum value : "<<dll.getMin(dll.getHead());
		
			else
			cout<<"\nEMPTY...."<<endl;
		}
		
		//max value
		else if(choice==4)
		{
			if(dll.getHead()!=NULL)
			cout<<"\nMaximum value : "<<dll.getMax(dll.getHead());
			
			else
			cout<<"\nEMPTY...."<<endl;
		}	
		
		cout<<"\n = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n\n";
	}	
	
	return 0;
}
