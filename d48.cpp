// linear search

#include<iostream>
#include<iomanip>
#define SIZE 20

using namespace std;

class array
{
	private :
		int i;
		float a[SIZE];
	public :
		void enter(int); // function prototype
		void display(int);
		int linear_search(int,float);
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
	cout.precision(6);
	for(i=0;i<n;++i)
	   cout<<setw(8)<<a[i];
}

// function definition linear_search()
int array::linear_search(int n,float data)
{
	i=0;
	while(i<n)
	{
		if(a[i] == data)
		   return(i);
		++i;
	}
	return(-1); // when entire array has been exhausted
}

int main()
{
	array obj;
	float a[SIZE],data;
	int n,position;
	cout<<"Enter the number of elements in the array <= "<<SIZE<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" elements"<<endl<<endl;
	obj.enter(n); // function call
	cout<<"\nEnter the element to be searched : ";
	cin>>data;
	system("CLS"); // clears the screen
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(n); // function call
	cout<<"\n\nElement to be searched is "<<data<<endl<<endl; 
	position = obj.linear_search(n,data);
	if(position == -1)
	   cout<<"\n"<<data<<" not found in the entered array"<<endl<<endl;
	else
	   cout<<"\n"<<data<<" found at position "<<position+1<<endl<<endl;
	return 0;
}
