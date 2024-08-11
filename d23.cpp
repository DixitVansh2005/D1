// deletion of a node from a linked list 

#include<iostream>

using namespace std;

class node
{
	public:
	    int info;   // data field
	    node *link; // pointer to the next node	
};

class linked_list
{
	private:
		node *start = NULL;
	public:
		void add_node(int); // function prototype
		void disp_list();
		void del_node(int);
		void del_list();
};

// function definition add_node()
void linked_list::add_node(int data)
{
	node *newptr = NULL; // local variable
	node *ptr;
	// create a new node and initialize it
	newptr = new node;
	
	newptr->info = data;
	newptr->link = NULL;
	if(start==NULL) // if the linked list is empty
	   start = newptr;
	else
	{
		ptr = start;
		// traverse the linked list for last node
		while(ptr->link != NULL)
		   ptr = ptr->link;
		// insert the new node in the end of linked list
		ptr->link = newptr;
	}
}

// function definition disp_list()
void linked_list::disp_list()
{
	node *ptr = start;
    cout<<"->";
    while(ptr)
    {
    	cout<<ptr->info<<"->"; // displays the node
    	ptr = ptr->link;
	}
	cout<<"NULL"<<endl;
}

// function definition del_node()
void linked_list::del_node(int pos)
{
	node *temp,*ptr = NULL;
	int steps = 1;
	
	// search for desired position
	if(pos==1) // if the is to be deleted from the start
	{
		temp = start;
		start = start->link;
		delete(temp);
	}
	else
	{
		ptr = start;
		while(steps < pos-1)
		{
		   ptr = ptr->link;
		   ++steps;
	    }
		// deletion
		temp = ptr->link;
		ptr->link = ptr->link->link;
		delete(temp); // deallocate the memory
	}
}

// function definition del_list()
void linked_list::del_list()
{
	node *ptr;
	while(start != NULL)
	{
		ptr = start;
		start = start->link;
		delete(ptr); // deallocates the memory stored 
	}
}

int main()
{
	linked_list obj;
	int value,pos;
	char choice;
	while(1)
	{
		cout<<"\nDo you wish to insert the node(y/n) ? ";
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
	// echo the data
	cout<<"Linked list is :"<<endl<<endl;
	obj.disp_list(); // function call
	cout<<"\nEnter the position of deletion : ";
	cin>>pos;
	obj.del_node(pos); // function call
	cout<<"\nLinked list after deletion is :"<<endl<<endl;
	obj.disp_list(); // function call
	obj.del_list(); // function call
	return 0;
}
