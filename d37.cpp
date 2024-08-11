// create and traverse a doubly linked list using header node

#include<iostream>

using namespace std;

class node
{
	public:
		node *lptr;
		int info;
	    node *rptr;
}*start = NULL,*last = NULL;

class linked_list
{
	public:
		void add_node();
		void display();
		void del_list();
};

int total;

// function definition add_node()
void linked_list::add_node()
{
	node *newptr = NULL;
	int data;
	char choice;
	while(1)
	{
		cout<<"\nDo you want to add a node (y/n)? ";
		cin>>choice;
		if(choice == 'y' || choice == 'Y')
		{
			++total;
			cout<<"\nEnter the info of the node : ";
			cin>>data;
			fflush(stdin);
			newptr = new node;
			newptr->info = data;
			newptr->rptr = NULL;
			// insert the node in the end of the linked list
			  last->rptr = newptr;
			newptr->lptr = last;
			        last = newptr;
		}
		else
		   return;
	}
}

// function definition display()
void linked_list::display()
{
	node *move;
	cout<<"\nTraversing in forward direction :"<<endl<<endl;
	move = start->rptr;
	while(move)
	{
	   cout<<move->info<<"<->";
	   move = move->rptr;
	}
	cout<<"NULL";
	
	cout<<"\n\nTraversing in backward direction :"<<endl<<endl;
	move = last;
	while(move->lptr)
	{
	   cout<<move->info<<"<->";
	   move = move->lptr;
	}
	cout<<"NULL";
}

// function definition del_list()
void linked_list::del_list()
{
	node *ptr;
	while(start != NULL)
	{
		ptr = start;
		start = start->rptr;
		delete(ptr);
	}
	last = NULL;
}

int main()
{
	linked_list obj;
	start = new node;
	start->lptr = start->rptr = NULL;
	start->info = -1;
	last = start;
	obj.add_node(); // function call
	system("CLS");
	if(total)
	{
		cout<<"The doubly linked list with header node is :"<<endl<<endl;
	    obj.display(); // function call
	    obj.del_list(); // function call
	}
	else
	   cout<<"Linked list is empty"<<endl;
    return 0;
}
