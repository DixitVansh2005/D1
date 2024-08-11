// concatenation of two singly linked list 

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
		void concatenate();
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
		cout<<"\nDo you wish to insert the node(y/n) ? ";
		cin>>choice;
		fflush(stdin); // empty the buffer
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

// function definition concatenate()
void linked_list::concatenate()
{
	node *ptr = NULL;
	third = first;
	
	if(first==NULL)
	{
		third = second;
		return;
	}
	if(second==NULL)
	   return;
	ptr = first;
	while(ptr->link)
	   ptr = ptr->link;
	ptr->link = second;
}

// function definition del_list()
void linked_list::del_list(node *ptr)
{
	node *temp;
	while(ptr != NULL)
	{
		temp = ptr;
		 ptr = ptr->link;
		delete(temp); // deallocates the memory stored 
	}
}

int main()
{
	linked_list obj1,obj2,obj3; 
	cout<<"Enter the data for the first linked list"<<endl<<endl;
	first = obj1.create_list(); // function call
	cout<<"\nEnter the data for the second linked list"<<endl<<endl;
	second = obj2.create_list(); // function call
	// echo the data
	system("CLS");
	cout<<"\nFirst linked list is :"<<endl<<endl;
	obj1.disp_list(first); // function call
	cout<<"\nSecond linked list is :"<<endl<<endl;
	obj2.disp_list(second); // function call
	obj3.concatenate(); // function call
	cout<<"\nConcatenated linked list is :"<<endl<<endl;
	obj3.disp_list(third); // function call
	obj3.del_list(third); // function call
	return 0;
}
