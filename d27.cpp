// merge two linked lists having info of nodes in ascending order 

#include<iostream> 

using namespace std;

class node
{
	public:
	    int info;   // data field
	    node *link; // pointer to the next node	
}*first=NULL,*second=NULL,*third=NULL;

class linked_list
{
	private:
		node *start = NULL;
	public:
		node* create_list(); // function prototype
		void disp_list(node *);
		node* merge(node*,node*);
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

// function definition merge()
node * linked_list::merge(node *first,node *second)
{
	node *ptr = NULL,*three = NULL;
	// check if both lists are empty
	if(first==NULL && second==NULL)
	   return(three);
	// check if first list is empty
	if(first==NULL && second!=NULL)
	   return(second);
	// check if second list is empty
	if(first!=NULL && second==NULL)
	   return(first);
	// when both lists have atleast one node
	if(first->info <= second->info)
	{
		three = first;
		first = first->link;
	}
	else
	{
		 three = second;
		second = second->link;
	}
	ptr = three;
	while(first != NULL && second != NULL)
	{
		if(first->info <= second->info)
	    {
		    ptr->link = first;
		        first = first->link;
	    }
	    else
	    {
		    ptr->link = second;
		       second = second->link;
	    }
	    ptr = ptr->link; 
	}
	// copy the first list if nodes left in it
	if(first != NULL)
	   ptr->link = first;
	// copy the second list if nodes left in it
	if(second != NULL)
	   ptr->link = second;
	return(three);	
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
	linked_list obj1,obj2,obj3;
	cout<<"Enter the data for the first linked list in ascending order"<<endl<<endl;
	first = obj1.create_list(); // function call;
	system("CLS");
	cout<<"\nEnter the data for the second linked list in ascending order"<<endl<<endl;
	second = obj2.create_list(); // function call;
	// echo the data
	system("CLS");
	cout<<"\nFirst linked list is :"<<endl<<endl;
	obj1.disp_list(first); // function call
	cout<<"\nSecond linked list is :"<<endl<<endl;
	obj2.disp_list(second); // function call
	third = obj3.merge(first,second); // function call
	cout<<"\nMerged linked list is :"<<endl<<endl;
	obj3.disp_list(third); // function call
	obj3.del_list(third); // function call
	return 0;
}
