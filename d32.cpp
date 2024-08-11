// store and display a polynomial using a linked list
// terms of polynomial are entered in descending order of power

#include<iostream>

using namespace std;

class node
{
	public:
		int coeff;
		int power;
	    node *link;
}*start = NULL;

class linked_list
{
	public:
		void create_list(); // function call
		void display();
		void del_list();
};

// function definition create_list()
void linked_list::create_list()
{
	node *newptr = NULL;
	int coeff,power;
	char choice;
	while(1)
	{
		cout<<"\nDo you want to add a node (y/n)? ";
		cin>>choice;
		fflush(stdin);
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"\nEnter the coefficient and power : ";
			cin>>coeff>>power;
			if(start == NULL)
			{
				       newptr = new node[sizeof(node)];
			    newptr->coeff = coeff;
			    newptr->power = power;
			     newptr->link = NULL;
			            start = newptr;
		    }
			else
			{
				 newptr->link = new node[sizeof(node)];
				       newptr = newptr->link;
			    newptr->coeff = coeff;
			    newptr->power = power;
			     newptr->link = NULL;    
			}
		}
		else
		   return;
	}
}

// function definition display()
void linked_list::display()
{
	node *ptr = start;
	while(ptr)
	{
	   if(ptr->power == 0) 
	       cout<<ptr->coeff;
	   else if(ptr->coeff == 1 && ptr->power == 1)
	       cout<<"x";
	   else if(ptr->coeff == 1)
	       cout<<"x^"<<ptr->power;
	   else if(ptr->power == 1)
	       cout<<ptr->coeff<<"x";
	   else
	       cout<<ptr->coeff<<"x^"<<ptr->power;

	   ptr = ptr->link;
	   if(ptr->coeff > 0)
	      cout<<"+";
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
		delete(ptr);
	}
}

int main()
{
	linked_list obj;
	cout<<"Enter terms of polynomials in descending order of power"<<endl;
	obj.create_list(); // function call
	system("CLS");
	if(start != NULL)
	{
		cout<<"Entered polynomial is"<<endl<<endl;
		obj.display(); // function call
		obj.del_list(); // function call
	}
	else
	   cout<<"Linked list is empty"<<endl;
	return 0;
}
