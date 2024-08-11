// modifying the contents of a node of a linked list 

#include<iostream>
#include<process.h> 

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
		void modify(int,int);
		void del_list();
}obj; // class object declared

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

// function definition modify()
void linked_list::modify(int oldvalue,int newvalue)
{
	node *ptr = start;
	
	// search for desired info (first occurence only)
	while(ptr->info != oldvalue && ptr->link != NULL)
	   ptr = ptr->link;
	   
	// if found then replace the oldvalue by newvalue
	if(ptr->info == oldvalue)
		ptr->info = newvalue;
    else
    {
    	cout<<"\n"<<oldvalue<<" not found in the linked list"<<endl<<endl;
    	obj.del_list();
    	exit(1);
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
	int value,oldvalue,newvalue;
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
	cout<<"\nEnter the value to be modified : ";
	cin>>oldvalue;
	cout<<"\nEnter the new value : ";
	cin>>newvalue;
	obj.modify(oldvalue,newvalue); // function call
	cout<<"\nLinked list after modification is :"<<endl<<endl;
	obj.disp_list(); // function call
	obj.del_list(); // function call
	return 0;
}
