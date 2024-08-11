// sorting a singly linked list 

#include<iostream> 

using namespace std;

class node
{
	public:
	    int info;   // data field
	    node *link; // pointer to the next node	
}*first=NULL;

class linked_list
{
	private:
		node *start = NULL;
	public:
		node *create_list(); // function prototype
		void disp_list(node *);
		void sort();
		void del_list(node *);
};

// function definition create_list()
node *linked_list::create_list()
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
    cout<<"->";
    while(temp)
    {
    	cout<<temp->info<<"->"; // displays the node
    	temp = temp->link;
	}
	cout<<"NULL"<<endl;
}

// function definition sort()
void linked_list::sort()
{
	node *ptr,*current;
	int tempval;
	// check if linked list is empty or has only one node
	if(start == NULL || start->link == NULL)
		return;
	// sorting
	ptr = start;
	while(ptr->link != NULL)
	{
		current = ptr->link;
		while(current != NULL)
		{
			if(current->info < ptr->info)
			{
				      tempval = current->info;
				current->info = ptr->info;
				    ptr->info = tempval; 
			}
			current = current->link;
		}
		ptr = ptr->link;
	}	
}

// function definition del_list()
void linked_list::del_list(node *temp)
{
	while(start != NULL)
	{
		temp = start;
		start = start->link;
		delete(temp); // deallocates the memory stored 
	}
}

int main()
{
	linked_list obj;
	cout<<"Enter the data for the linked list"<<endl<<endl;
	first = obj.create_list(); // function call;
	system("CLS");
	// echo the data
	cout<<"\nLinked list is :"<<endl<<endl;
	obj.disp_list(first); // function call
	obj.sort(); // function call
	cout<<"\nLinked list after sorting is :"<<endl<<endl;
	obj.disp_list(first);  // function call
	obj.del_list(first);   // function call
	return 0;
}
