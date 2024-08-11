// check a string for palindrome using stack and queue

#include<iostream>
#include<iomanip>
#include<process.h>

using namespace std;

class qnode
{
	public:
	    char data;
 	    qnode *link;
}*front = NULL,*rear = NULL;

class stnode
{
	public:
	    char data;
	    stnode *link;
}*top = NULL;

class linked_list
{
	public:
		int  isempty();    // function prototype
		void insert(char);
		char del();
		void push(char);
		char pop();
};

// function definition isempty()
int linked_list::isempty()
{
	return(front == NULL && rear == NULL) ? 1 : 0;
}

// function definition insert()
void linked_list::insert(char ch)
{
	qnode *ptr = new qnode;
	ptr->data = ch;
	ptr->link = NULL;
	if( isempty() ) // if it is the first node to be inserted
	{
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->link = ptr;
		rear = ptr;
	}
}

// function definition del()
char linked_list::del()
{
	qnode *temp; 
	char ch;
	temp = front;
	front = front->link;
	if(front == NULL)
	    rear = NULL;
	ch = temp->data;
	delete(temp);
	return ch;
}

// function definition display()
void linked_list::push(char ch)
{
	stnode *temp = new stnode;
	temp->data = ch;
	temp->link = top;
	top = temp;
}

// function definition pop()
char linked_list::pop()
{
	stnode *temp;
	char ch;
	temp = top;
	top = top->link;
	ch = temp->data;
	delete(temp);
	return(ch);
}

int main()
{
	linked_list obj;
	char ch;
	int flag;
	cout<<"Enter the string :"<<endl<<endl;
	ch = cin.get();
	while(ch != '\n')
	{
		obj.push(ch); // function call
		obj.insert(ch);
		ch = cin.get();
	}
	do
	{
		flag = ( obj.pop() == obj.del() ) ? 1:0;
    }while(flag && !(obj.isempty()) );
	
	if(flag)
	    cout<<"\n\nThe inputted string is a pallindrome"<<endl;
	else
	    cout<<"\n\nThe inputted string is not a pallindrome"<<endl;
	return 0;
}
