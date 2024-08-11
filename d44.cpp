// queue insert, delete (circular array implementation)

#include<iostream>
#include<iomanip>
#include<process.h>
#define SIZE 4

using namespace std;

class array
{
	private:
		int Q[SIZE];
	public:
		void insert(int); // function prototype
		void del();
		void display();
};

int front = -1,rear = -1;

// function definition insert()
void array::insert(int data)
{
	if(rear == SIZE-1)
	   rear = 0;
	else
	   ++(rear);
	if(front == rear)
	{
		cout<<"\nQueue overflow"<<endl;
		exit(1);
	}
	Q[rear] = data;
	if(front == -1)
	   ++front;
}

// function definition del()
void array::del()
{
	if(front<0)
	{
		cout<<"\nQueue underflow"<<endl<<endl;
		exit(1);
	}
	cout<<"\nDeleted element : "<<Q[front];
	if(front == rear)
	   front = rear = -1;
	else
	{
		if(front == SIZE-1)
		   front = 0;
		else
	       ++front;
    }
}

// function definition display()
void array::display()
{
	int position;
	if(front <= rear)
	{
		for(position = front; position <= rear; ++position)
		   cout<<Q[position]<<setw(8);
	}
	else
	{
		for(position = front; position<SIZE ; ++position)
		   cout<<Q[position]<<setw(8);
		for(position = 0 ; position<=rear ; ++position)
		   cout<<Q[position]<<setw(8);
	}
	cout<<"\n\nFront = "<<front<<" Rear = "<<rear<<endl;
}

int main()
{
	array obj;
	int Q[SIZE],data;
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
				        obj.del(); // function call
				        break;
			case 'q' :
			case 'Q' :
				        exit(0);
			default :
				        cout<<"\nWrong key pressed"<<endl;
				        fflush(stdin);
				        cout<<"\nPress enter key to continue..."<<endl;
				        ch = cin.get();
				        continue;
		}
		cout<<"\nTotal size of the queue is "<<SIZE<<endl;
		cout<<"\nQueue after the operation performed is :"<<endl<<endl;
		obj.display(); // function call
		fflush(stdin);
		cout<<"\nPress enter key to continue..."<<endl;
		ch = cin.get();
	}while(1);
	return 0;
}
