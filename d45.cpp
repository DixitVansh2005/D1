// queue insert, delete (linked list implementation)

#include<iostream>
#include<iomanip>
#include<process.h>

using namespace std;

class node
{
	public:
	    int info;
 	    node *link;
}*front = NULL,*rear = NULL;

class linked_list
{
	public:
		int isempty();    // function prototype
		void insert(int); 
		int del();
		void display();
		void del_list();
};

// function definition isempty()
int linked_list::isempty()
{
	return( (front==NULL && rear==NULL) ? 1 : 0);
}

// function definition insert()
void linked_list::insert(int data)
{
	node *newptr = new node;
	newptr->info = data;
	newptr->link = NULL;
	if( isempty() ) // function call
	   front = rear = newptr;
	else
	{
		rear->link = newptr;
		rear = newptr;
	}
}

// function definition del()
int linked_list::del()
{
	node *temp;
	if(!front)
	{
		cout<<"\nQueue underflow"<<endl;
		return(1);
	}
	else
	{
		temp = front;
		front = front->link;
		if(!front)
		   rear = NULL;
		cout<<"\nDeleted element : "<<temp->info;
		return 0;
	}
}

// function definition display()
void linked_list::display()
{
	node *ptr;
	if(front)
	{
		ptr = front;
		while(ptr)
		{
			cout<<"----->"<<ptr->info;
			ptr = ptr->link;
		}
		cout<<endl;
	}
	else
	   cout<<"is empty"<<endl;
}

// function definition del_list()
void linked_list::del_list()
{
	node *temp;
	while(front)
	{
		temp = front;
		front = front->link;
		delete(temp);
	}
}

int main()
{
	linked_list obj;
	int data;
	char ch,choice;
	do
	{
		system("CLS");
		cout<<"\nEnter : i(insert), d(delete), q(Quit) : ";
		cin>>choice;
		switch(choice)
		{
			case 'i' :
			case 'I' :
				        cout<<"\nEnter the data : ";
				        cin>>data;
				        obj.insert(data); // function call
				        break;
			case 'd' :
			case 'D' :
				        if( obj.del() ) // function call
				           exit(1);
	                    break;
			case 'q' :
			case 'Q' :
				        obj.del_list(); // function call
				        exit(0);
			default :
				        cout<<"\nWrong key pressed"<<endl;
				        fflush(stdin);
				        cout<<"\nPress enter key to continue..."<<endl;
				        ch = cin.get();
				        continue;
		}
		cout<<"\nQueue after the operation performed is :"<<endl<<endl;
		obj.display(); // function call
		fflush(stdin);
		cout<<"\nPress enter key to continue..."<<endl;
		ch = cin.get();
	}while(1);
	return 0;
}
