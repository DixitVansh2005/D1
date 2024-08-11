// create a circular linked list dynamically and traverse it
// new nodes are inserted at the head of the circular linked list

#include<iostream>

using namespace std;

class node
{
	public:
		int info;
	    node *link;
}*head;

class linked_list
{
	private:
		node *start = NULL;
	public:
		void add_node();
		void display();
		void del_list();
};

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
			cout<<"\nEnter the info of the node : ";
			cin>>data;
			fflush(stdin);
			newptr = new node;
			newptr->info = data;
			newptr->link = head->link;
			  head->link = newptr;
		}
		else
		   return;
	}
}

// function definition display()
void linked_list::display()
{
	node *ptr = head->link;
	if(ptr == head) // if the list is empty
	{
		cout<<"empty"<<endl;
		return;
	}
	cout<<"\n->";
	while(ptr != head)
	{
		cout<<ptr->info<<"->";
		ptr = ptr->link;
	}
	cout<<endl;
}

// function definition del_list()
void linked_list::del_list()
{
	node *ptr,*temp;
	temp = head->link;
	while(temp != head)
	{
		ptr = temp;
		temp = temp->link;
		delete(ptr);
	}
	delete(head);
}

int main()
{
	linked_list obj;
	head = new node[sizeof(node)];
	head->link = head;
	obj.add_node();
	system("CLS");
	// echo the data
	cout<<"Circular linked list is :"<<endl;
	obj.display();
	obj.del_list();
	return 0;
}
