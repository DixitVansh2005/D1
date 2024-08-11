// deletion of a node from a doubly linked circular list having header node

#include<iostream>
#include<process.h>

using namespace std;

class node
{
	public:
		node *lptr;
		int info;
	    node *rptr;
}*head = NULL,*start = NULL,*last = NULL;

class linked_list
{
	public:
		void create_list();
		void display();
		int del_node(int value);
		void del_list();
};

int total;

// function definition create_list()
void linked_list::create_list()
{
	node *newptr = NULL;
	int data;
	char choice;
	while(1)
	{
		cout<<"\nDo you want to add a node (y/n)? ";
		cin>>choice;
		fflush(stdin);
		if(choice == 'y' || choice == 'Y')
		{
			++total;
			cout<<"\nEnter the info of the node : ";
			cin>>data;
			newptr = new node;
			newptr->info = data;
			
			      newptr->lptr = head->lptr;
			      newptr->rptr = head;
			(head->lptr)->rptr = newptr;
			        head->lptr = newptr;
		}
		else
		   return;
	}
}

// function definition display()
void linked_list::display()
{
	node *move = NULL;
	if(head->rptr == head)
	{
		cout<<" empty"<<endl;
		delete(head);
		exit(1);
	}
	cout<<"\nTraversing in forward direction :"<<endl<<endl;
	move = head->rptr;
	while(move->rptr != head)
	{
	   cout<<move->info<<"<->";
	   move = move->rptr;
	}
	cout<<move->info;
	
	cout<<"\n\nTraversing in backward direction :"<<endl<<endl;
	move = head->lptr;
	while(move->lptr != head)
	{
	   cout<<move->info<<"<->";
	   move = move->lptr;
	}
	cout<<move->info;
}

// function definition del_node()
int linked_list::del_node(int value)
{
	node *move,*temp;
	move = head->rptr;
	while(move->info != value && move != head)
	    move = move->rptr;
	if(move == head)
	{
		cout<<value<<" not found in the doubly circular linked list"<<endl;
		return 0;
	}
	else // if node found
	{
		temp = move;
		(move->lptr)->rptr = move->rptr;
		(move->rptr)->lptr = move->lptr;
		delete(temp);
		return(1);
	}
}

// function definition del_list()
void linked_list::del_list()
{
	node *ptr,*temp;
	temp = head->rptr; 
	while(temp != head)
	{
		ptr = temp;
		temp = temp->rptr;
		delete(ptr);
	}
	delete(head);
	head = NULL;
}

int main()
{
	linked_list obj;
	int flag,value;
	head = new node;
	head->rptr = head->lptr = head;
	head->info = -1;
	obj.create_list(); // function call
	system("CLS");
	if(total)
	{
		cout<<"The doubly linked circular list with header node is :"<<endl<<endl;
	    obj.display(); // function call
	    cout<<"\n\nEnter the info of the node to be deleted"<<endl<<endl;
	    cin>>value;
	    flag = obj.del_node(value); // function call
	    if(flag)
	    {
	    	cout<<"\nThe doubly linked circular list after deletion is "<<endl;
	    	obj.display(); // function call
		}
	    obj.del_list(); // function call
	}
	else
	   cout<<"Linked list is empty"<<endl;
    return 0;
}
