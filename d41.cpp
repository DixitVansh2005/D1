// check a given expression for balanced parenthesis using stack

#include<iostream>

using namespace std;

class node
{
	public:
	    char info;
	    node *next;
}*top=NULL;

class linked_list
{
	public:
		void push(char); // function prototype
		void pop();
		int isempty();
		int find_elements();
};

int mismatch = 0;

// function definition push() to insert element
void linked_list::push(char ch)
{
	node *newptr = new node;
	newptr->info = ch;
	newptr->next = top;
	top = newptr;
}

// function definition pop() to delete element
void linked_list::pop()
{
	node *freeptr = NULL;
	if(top!=NULL)
	{
		freeptr = top;
		top = top->next;
		delete(freeptr);
	}
	else
	   ::mismatch++;
}

// function definition isempty()
int linked_list::isempty()
{
	return( (top != NULL) ? 0 : 1);
}

// function definition find_elements()
int linked_list::find_elements()
{
	node *move;
	int total = 0;
	move = top;
	while(move)
	{
		total++;
		move = move->next;
	}
	return(total);
}

int main()
{
	linked_list obj;
	node *temp = NULL;
	char ch;
	cout<<"Enter the expression : ";
	cin>>ch;
	while(ch != '\n')
	{
		if(ch == '(')
		   obj.push(ch); // function call
		else
		{
			if(ch==')')
			   obj.pop(); // function call
		}
		ch = cin.get();
	}
	if(!(obj.isempty())) // function call
	{
		cout<<"\n\nNo matching right paranthesis for ";
		cout<<obj.find_elements()<<" left paranthesis"<<endl;
	}
	else
	{
		if(::mismatch != 0)
		{
			cout<<"\n\nNo matching left paranthesis for ";
			cout<<::mismatch<<" right paranthesis"<<endl;
		}
		else
		    cout<<"\nCorrect Expression"<<endl<<endl;
	}
	return 0;
}
