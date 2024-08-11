// delete a node from the desired position in a doubly linked list

#include<iostream>
#include<process.h>

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
		void del_node();
		void del_list();
};

int total; // global variable total for counting number of nodes

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
}

// function definition del_node()
void linked_list::del_node()
{
	int position,steps;
	node *move;
	cout<<"\n\nEnter the position of deletion of node <= "<<total<<endl<<endl;
	cin>>position;
	if(position<1 || position>total)
	{
		cout<<"\nInvalid position inputted"<<endl;
		del_list();
		exit(1);
	}
	if(position == 1)
	{
		if(start == last) // if there is only single node
		{
			delete(start); // deallocates the memory
			start = last = NULL;
		}
		else
		{
			// when doubly linked list has two or more nodes
			move = start;
			start = start->rptr;
			start->lptr = NULL;
			delete(move);
		}
	}
	else
	{
		// search for the node to be deleted
		steps = 1;
		move = start;
		while(steps<position)
		{
			move = move->rptr;
			steps++;
		}
		// if the right most node is to be deleted
		if(move == last)
		{
			last = last->lptr;
			last->rptr = NULL;
		}
		else
		{
			(move->lptr)->rptr = move->rptr;
			(move->rptr)->lptr = move->lptr;
		}
		delete(move);
	}
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
	obj.add_node(); // function call
	system("CLS");
	cout<<"The doubly linked list is :"<<endl<<endl;
	obj.display(); // function call
	if(total>0)
	{
		obj.del_node();
		cout<<"\nThe doubly linked list after deletion is :"<<endl;
	    obj.display(); // function call
	    obj.del_list(); // function call
    }
    else
       cout<<"\n\nLinked list is empty"<<endl<<endl;
	return 0;
}
