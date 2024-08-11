// dividing a singly linked list into two lists having odd and even position elements

#include<iostream> 

using namespace std;

class node
{
	public:
	    int info;   // data field
	    node *link; // pointer to the next node	
}*oddptr=NULL,*evenptr=NULL,*first=NULL,*second=NULL;

class linked_list
{
	private:
		node *start = NULL;
	public:
		node* create_list(); // function prototype
		void disp_list(node *);
		node* divide_list(node *);
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

// function definition divide_list()
node* linked_list::divide_list(node *temp)
{
	node *ptr1,*ptr2;
	int count = 0;
	// check if linked list is empty
	if(temp == NULL)
		return(temp);
	// divide the list into two lists
	oddptr = temp;
	if(temp->link == NULL)
	{
		evenptr = NULL;
		return(evenptr);
	}
	temp = temp->link;
	evenptr = temp;
	temp = temp->link;
	if(temp == NULL)
	{
		oddptr->link = NULL;
		return(evenptr);
	}
	ptr1 = oddptr;
	ptr2 = evenptr;
	while(temp != NULL)
	{
		count++;
		if(count%2 != 0) // if odd node number
		{
			ptr1->link = temp;
			ptr1 = ptr1->link;
		}
		else
		{
			ptr2->link = temp;
			ptr2 = ptr2->link;
		}
		temp = temp->link;
	}
	if(count%2 == 0)
		ptr1->link = NULL;
    else
        ptr2->link = NULL;
	return(evenptr);	
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
	cout<<"Enter the data for the linked list in ascending order"<<endl<<endl;
	first = obj1.create_list(); // function call;
	system("CLS");
	// echo the data
	cout<<"\nLinked list is :"<<endl<<endl;
	obj1.disp_list(first); // function call
	second = obj1.divide_list(first); // function call
	cout<<"\nLinked lists after splitting are :"<<endl<<endl;
	obj1.disp_list(first);  // function call
	obj2.disp_list(second); // function call
	obj1.del_list(first);   // function call
	obj2.del_list(second);  // function call
	return 0;
}
