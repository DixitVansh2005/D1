// deletion of an element from an array from a specific position

#include<iostream>
#define S 11

using namespace std;

class array
{
	private:
		int i,a[S];
	public:
		void enter(int);   // function prototype
		void display(int); // function prototype
		void del(int,int); // function prototype
};

// function definition enter()
void array::enter(int n)
{
	for(i=0;i<n;++i)
	   cin>>a[i];
}

// function definition display()
void array::display(int n)
{
	for(i=0;i<n;++i)
	   cout<<a[i]<<" ";
}

// function definition del()
void array::del(int n,int pos)
{
	for(i=pos;i<n;++i)
	   a[i-1] = a[i];
	a[n-1] = 0;
}

int main()
{
	array obj;
	int n,pos;
	cout<<"Enter the number of elements in the array <= "<<S-1<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the array elements"<<endl<<endl;
	obj.enter(n); // function call
	cout<<"\nEnter the position of deletion"<<endl<<endl;
	cin>>pos;
	if(pos<1 || pos>n)
	   cout<<"\nInvalid Input"<<endl<<endl;
	else
	{
		// echo the data
		cout<<"\n\nEntered array is"<<endl<<endl;
		obj.display(n); // function call
		cout<<"\n\nPosition of deletion is "<<pos<<endl<<endl;
		// deletion
		obj.del(n,pos); // function call
		cout<<"\nArray after deletion is"<<endl<<endl;
		obj.display(n-1);
	}
	return 0;
}
