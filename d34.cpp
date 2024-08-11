// insertion in a doubly linked list in the beginning or at end

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
		void add_node(int);
		void display();
		void insert_beginning(int);
		void insert_end(int);
		void del_list();
};

// function definition add_node()
void linked_list::add_node(int data)
{
	node *newptr = NULL;
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
	cout<<"NULL"<<endl;
}

// function definition insert_beginning()
void linked_list::insert_beginning(int data)
{
	node *newptr = NULL;
	// create a new node and initialize it
	newptr = new node;
	
	newptr->info = data;
	newptr->lptr = NULL;
	newptr->rptr = start;
	// make new node as the first node of the doubly linked list
	if(last == NULL) // if the linked list is empty
	   start = last = newptr;
	else
	{
		start->lptr = newptr;
		start = newptr;
	}
}

// function definition insert_end()
void linked_list::insert_end(int data)
{
	node *newptr = NULL;
	// create a node and initialize it
	newptr = new node;
	newptr->info = data;
	newptr->rptr = NULL;
	// make new node as the first node of the doubly linked list
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
	int value,option;
	char choice;
	while(1)
	{
		cout<<"\nDo you want to insert a node(y/n)? : ";
		cin>>choice;
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"\nEnter the info of node : ";
			cin>>value;
			obj.add_node(value); // function call
			fflush(stdin);
		}
		else
		   break;
	}
	system("CLS");
	cout<<"The doubly linked list is :"<<endl<<endl;
	obj.display(); // function call
	cout<<"\nEnter 1 for insertion in beginning or 2 for insertion in end"<<endl<<endl;
	cout<<"\nEnter your option (1 or 2) : ";
	cin>>option;
	switch(option)
	{
		case 1 :
			    cout<<"\nEnter the info of the node to be inserted"<<endl<<endl;
			    cin>>value;
			    obj.insert_beginning(value); // function call
			    cout<<"\nThe doubly linked list after insertion is"<<endl<<endl;
			    obj.display(); // function call
			    break;
		case 2 :
			    cout<<"\nEnter the info of the node to be inserted"<<endl<<endl;
			    cin>>value;
			    obj.insert_end(value); // function call
			    cout<<"\nThe doubly linked list after insertion is"<<endl<<endl;
			    obj.display(); // function call
			    break;
		default:
			    cout<<"\n\nWrong choice"<<endl<<endl;
			    break;
	}
	obj.del_list(); // function call
	return 0;
}
