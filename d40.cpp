// PUSH and POP operations on a stack (linked list implementation)

#include<iostream>
#include<process.h>

using namespace std;

class node
{
	public:
	    int info;
	    node *next;
}*top=NULL;

class linked_list
{
	public:
		void PUSH(int); // function prototype
		void POP();
		void display();
};

// function definition PUSH() to insert element
void linked_list::PUSH(int data)
{
	node *newptr = new node;
	if(newptr)
	{
		newptr->info = data;
		newptr->next = top;
		         top = newptr;
	}
	else
	{
		cout<<"\nCannot create new node"<<endl<<endl;
		exit(1);
	}
}

// function definition POP() to delete element
void linked_list::POP()
{
	node *freeptr = NULL;
	if(!top)
	{
		cout<<"\nEmpty stack, Underflow"<<endl;
		exit(1);
	}
	else
	{
		freeptr = top;
		cout<<"\nPopped element : "<<freeptr->info;
		top = top->next;
		delete(freeptr);
		if(!top)
		   cout<<"\nNo element left in the stack now"<<endl<<endl;
	}
}

// function definition display()
void linked_list::display()
{
	node *temp = top;
	cout<<"\nTop";
	while(temp)
	{
		cout<<"----->"<<temp->info;
		temp = temp->next;
	}
	cout<<"----->NULL"<<endl<<endl;
}

int main()
{
	linked_list obj;
	node *temp = NULL;
	int data;
	char ch,choice;
	do
	{
		system("CLS");
		fflush(stdin);
		cout<<"\nEnter :i (push), d (pop), q (Quit) : ";
		cin>>choice;
		switch(choice)
		{
			case 'i':
			case 'I':
				       cout<<"\nEnter the data : ";
				       cin>>data;
				       obj.PUSH(data);
				       break;
			case 'd':
			case 'D':
				       obj.POP();
				       break;
			case 'q':
			case 'Q':
				       // first delete all nodes then quit
				       while(top)
				       {
				       	   temp = top;
				       	   top = top->next;
				       	   delete(temp);
					   }
			           exit(0);	
			default :
			           cout<<"\nWrong key pressed ..."<<endl;
			           fflush(stdin);
			           cout<<"\nPress enter key to continue..."<<endl;
			           ch = cin.get();
					   continue;       
		}
		// display the stack after the operation
		if(top>=0)
		{
			cout<<"\n\nLinked list implementation of stack is :"<<endl<<endl;
			obj.display();
			fflush(stdin);
			cout<<"\nPress enter key to continue..."<<endl;
			ch = cin.get();
		}
	}while(1);
	return 0;
}
