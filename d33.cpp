// create and traverse a doubly linked list in both directions

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
		void create_list();
		void display();
		void del_list();
};

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
			cout<<"\nEnter the info of the node : ";
			cin>>data;
			newptr = new node;
			newptr->info = data;
			newptr->rptr = NULL;
			if(last == NULL) // if the linked list is empty
			{
				newptr->lptr = NULL;
				start = last = newptr;
			}
			else
			{
				// insert the node in the end of the linked list
				last->rptr = newptr;
				newptr->lptr = last;
				last = newptr;
			}
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
	move = start;
	while(move)
	{
	   cout<<move->info<<"<->";
	   move = move->rptr;
	}
	cout<<"NULL";
	
	cout<<"\n\nTraversing in backward direction :"<<endl<<endl;
	move = last;
	while(move)
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
	obj.create_list(); // function call
	system("CLS");
	if(start == NULL && last == NULL)
	   cout<<"Linked list is empty"<<endl;
	else
	{
	   cout<<"The doubly linked list is :"<<endl<<endl;
	   obj.display(); // function call
	   obj.del_list(); // function call
    }
	return 0;
}
