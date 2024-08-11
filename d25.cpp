// reversal of a linked list 

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
		void add_node(); // function prototype
		void disp_list();
		void reverse();
		void del_list();
};

// function definition add_node()
void linked_list::add_node()
{
	node *newptr = NULL; // local variable
	int data;
	char choice;
	while(1)
	{
	    cout<<"\nDo you wish to insert a node (y/n)? ";
	    cin>>choice;
	    if(choice == 'y' || choice == 'Y')
	    {
	    	cout<<"\nEnter the info of the node :";
	    	cin>>data;
	    	fflush(stdin);
	        if(start == NULL) // if the linked list is empty
	        {
	            newptr = new node;
		        newptr->info = data;
        	    newptr->link = NULL;
        	    start = newptr;
	        }
	        else
	        {
	        	newptr->link = new node;
	        	newptr = newptr->link;
				newptr->info = data;
				newptr->link = NULL; 
	        }
	    }
	    else
	       return;
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

// function definition reverse()
void linked_list::reverse()
{
	node *nextptr,*current,*previous;
	
	// check whether the linked list is empty or only one node
	if(start == NULL || start->link == NULL)
	   return;
	   
	// reverse the nodes by swapping the values
	previous = NULL;
	current = start;
    while(current)
    {
    	      nextptr = current->link;
    	current->link = previous;
    	     previous = current;
    	      current = nextptr;
    }
    start = previous;
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
	obj.add_node(); // function call
	system("CLS");
	// echo the data
	cout<<"Linked list is :"<<endl<<endl;
	obj.disp_list(); // function call
	obj.reverse(); // function call
	cout<<"\nLinked list after reversal is :"<<endl<<endl;
	obj.disp_list(); // function call
	obj.del_list(); // function call
	return 0;
}
