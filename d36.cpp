// searching for an element when the doubly linked list is sorted

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
		void add_node();
		void display();
		void search_info_ordered(int);
		void del_list();
};

int total;

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

// function definition search_info_ordered()
void linked_list::search_info_ordered(int data)
{
	int position = 1;
	node *move;
	if(start == NULL) // if linked list is empty
	{
		cout<<"\nUnsuccessful search"<<endl;
		cout<<"\n"<<data<<" not found in the doubly linked list"<<endl;
	}
	else
	{
		move = start;
		while(move->info < data && position < total)
		{
			++position;
			move = move->rptr;
		}
		if(move->info == data)
		{
           cout<<"\nSuccessful search"<<endl;
		   cout<<"\n"<<data<<" found at position "<<position<<endl<<endl;
	    }
		else
	    {
		cout<<"\nUnsuccessful search"<<endl;
		cout<<"\n"<<data<<" not found in the doubly linked list"<<endl;
	    }
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
	int data;
	obj.add_node(); // function call
	system("CLS");
	if(total)
	{
		cout<<"The doubly linked list is :"<<endl<<endl;
	    obj.display(); // function call
	    cout<<"\n\nEnter the data to be searched : ";
	    cin>>data;
	    obj.search_info_ordered(data);
	    obj.del_list(); // function call
	}
	else
	   cout<<"Linked list is empty"<<endl;
    return 0;
}
