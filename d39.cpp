// PUSH and POP operations on a stack (array implementation)

#include<iostream>
#include<process.h>
#define SIZE 5

using namespace std;

class array
{
	private :
		int s[SIZE];
	public:
		void PUSH(int); // function prototype
		void POP();
		void display();
};

int top = -1;

// function definition PUSH() to insert element
void array::PUSH(int data)
{
	if(top == SIZE-1)
	{
		cout<<"Stack overflow"<<endl;
		exit(1);
	}
	else
	{
		s[++top] = data;
		if(top == SIZE-1)
		   cout<<"\nNo element will be inserted next time"<<endl<<endl;
	}
}

// function definition POP() to delete element
void array::POP()
{
	if(top<0)
	{
		cout<<"\nStack underflow"<<endl;
		exit(1);
	}
	else
	{
		cout<<"\nPopped element : "<<s[top--];
		if(top<0)
		   cout<<"\nNo element left in the stack now"<<endl;
	}
}

// function definition display()
void array::display()
{
	int i;
	cout<<s[top]<<"<-----Top"<<endl;
	for(i=top-1;i>=0;--i)
	   cout<<s[i]<<endl;
}

int main()
{
	array obj;
	int s[SIZE],data;
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
				       obj.PUSH(data); // function call
				       break;
			case 'd':
			case 'D':
				       obj.POP(); // function call
				       break;
			case 'q':
			case 'Q':
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
			cout<<"\n\nStack after the operation performed :"<<endl<<endl;
			obj.display(); // function call
			fflush(stdin);
			cout<<"\nPress enter key to continue..."<<endl;
			ch = cin.get();
		}
	}while(1);
	return 0;
}
