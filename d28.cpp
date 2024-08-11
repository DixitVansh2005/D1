// splitting of a singly linked list into two singly linked list 

#include<iostream> 
#include<process.h>

using namespace std;

class node
{
	public:
	    int info;   // data field
	    node *link; // pointer to the next node	
}*first=NULL,*second=NULL;

class linked_list
{
	private:
		node *start = NULL;
	public:
		node* create_list(); // function prototype
		void disp_list(node *);
		void split(int);
		void del_list(node *);
};

// function definition create_list()
node* linked_list::create_list()
{
	node *newptr = NULL; // local variable
	int value;
	char choice;
	while(1)
	{
		fflush(stdin); // empty the buffer
		cout<<"\nDo you wish to insert the node(y/n) ? ";
		cin>>choice;
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"\nEnter the info of node : ";
			cin>>value;
			if(start == NULL)
			{
				newptr = new node;
				newptr->info = value;
				newptr->link = NULL;
				start = newptr;
			}
			else
			{
				newptr->link = new node;
				newptr = newptr->link;
				newptr->info = value;
				newptr->link = NULL; 
			}
		}
		else
		   break;
	}
	return(start);
}

// function definition disp_list()
void linked_list::disp_list(node *temp)
{
	node *ptr = temp;
    cout<<"->";
    while(ptr)
    {
    	cout<<ptr->info<<"->"; // displays the node
    	ptr = ptr->link;
	}
	cout<<"NULL"<<endl;
}

// function definition split()
void linked_list::split(int value)
{
	node *pred,*ptr = NULL;
	// check if linked list is empty
	if(start == NULL)
	{
		first = NULL;
		second = NULL;
		return;
	}
	if(start->info > value)
	{
		first = NULL;
		second = start;
		return;
	}
	// search for the node of split
	first = start;
	pred = NULL;
	ptr = start;
	while(ptr->info <= value && ptr->link != NULL)
	{
		pred = ptr;
		 ptr = ptr->link;
	}
	// split the linked list
	if(ptr->info <= value)
	   second = NULL;
	else
	{
		pred->link = NULL;
		second = ptr;
	}	
}

// function definition del_list()
void linked_list::del_list(node *ptr)
{
	node *temp;
	while(start != NULL)
	{
		temp = start;
		start = start->link;
		delete(temp); // deallocates the memory stored 
	}
}

int main()
{
	linked_list obj1,obj2;
	int value;
	cout<<"Enter the data for the linked list in ascending order"<<endl<<endl;
	first = obj1.create_list(); // function call;
	system("CLS");
	// echo the data
	cout<<"\nLinked list is :"<<endl<<endl;
	obj1.disp_list(first); // function call
	cout<<"\nEnter the value for splitting the linked list"<<endl<<endl;
	cin>>value;
	obj1.split(value); // function call
	cout<<"\nLinked lists after splitting are :"<<endl<<endl;
	cout<<"First";
	obj1.disp_list(first);  // function call
	cout<<"Second";
	obj2.disp_list(second); // function call
	obj1.del_list(first);   // function call
	obj2.del_list(second);  // function call
	return 0;
}
