// queue insert, delete (circular linked list implementation)

#include<iostream>
#include<iomanip>
#include<process.h>

using namespace std;

class node
{
	public:
	    int info;
 	    node *link;
}*rear = NULL;

class linked_list
{
	public:
		void initialize();    // function prototype
		node *getnode();
		void addnode(int);
		void display();
		void deletenode();
};

// function definition initialize()
void linked_list::initialize()
{
	rear = NULL;
}

// function definition getnode()
node *linked_list::getnode()
{
	node *newptr = new node;
	return(newptr);
}

// function definition addnode()
void linked_list::addnode(int value)
{
	node *ptr = getnode(); // function call
	ptr->info = value;
	if(rear == NULL)
	    rear = ptr;
	else
	    ptr->link = rear->link;
	rear->link = ptr;
	rear = ptr;
}

// function definition display()
void linked_list::display()
{
	node *temp = rear;
	cout<<"\nRear ->";
	if(rear!=NULL)
	{
		do
		{
			cout<<temp->info<<"->";
			temp = temp->link;
		}while(temp != rear);
    }
    else
		cout<<"NULL"<<endl;
}

// function definition deletenode()
void linked_list::deletenode()
{
	node *ptr;
	if(rear==NULL)
	{
		cout<<"\nQueue is empty"<<endl;
		exit(0);
	}
	else
	{
		ptr = rear->link;
		if(rear == ptr)
		{
			delete(ptr);
			rear = NULL;
		}
		else
		{
			rear->link = ptr->link;
			delete(ptr);
		}
	}
}

int main()
{
	linked_list obj;
	int data;
	char ch,choice;
	obj.initialize(); // function call
	do
	{
		fflush(stdin);
		system("CLS");
		cout<<"\nEnter : i(insert), d(delete), q(Quit) : ";
		cin>>choice;
		switch(choice)
		{
			case 'i' :
			case 'I' :
				        cout<<"\nEnter the data : ";
				        cin>>data;
				        obj.addnode(data); // function call
				        break;
			case 'd' :
			case 'D' :
				        obj.deletenode(); // function call
	                    break;
			case 'q' :
			case 'Q' :
				        while(rear)
				            obj.deletenode(); // function call
				        exit(0);
			default :
				        cout<<"\nWrong key pressed"<<endl;
				        fflush(stdin);
				        cout<<"\nPress enter key to continue..."<<endl;
				        ch = cin.get();
				        continue;
		}
		cout<<"\nQueue elements are :"<<endl;
		obj.display(); // function call
		fflush(stdin);
		cout<<"\nPress enter key to continue..."<<endl;
		ch = cin.get();
	}while(1);
	return 0;
}
