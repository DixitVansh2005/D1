// insertion in a sorted array
// Array remains sorted after insertion

#include<iostream>
#define S 11

using namespace std;

class array
{
	private:
	   int i,pos,a[S];
	public:
		void enter(int);   // function prototype 
		void display(int); // function prototype
		void insert(int,int);  // function prototype
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

// function definition insert()
void array::insert(int n,int data)
{
	int pos;
	if(data>=a[n-1])
	   a[n]=data;
	else
	{
		pos=0;
		while(a[pos]<=data)
		   ++pos;
	    // backward shifting of elements
	    for(i=n-1;i>=pos;--i)
	       a[i+1] = a[i];
	    // insertion of element
	    a[pos] = data;
    }
}
int main()
{
	array obj; // object declared
	int n,data;
	cout<<"Enter the number of elements in the array <= "<<S-1<<endl<<endl;
	cin>>n;
	cout<<"\nEnter "<<n<<" integers in ascending order"<<endl<<endl;
	obj.enter(n);  // function call
	cout<<"\n\nEnter the element to be inserted "<<endl<<endl;
	cin>>data;
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(n);   // function call
	cout<<"\n\nElement to be inserted is "<<data<<endl<<endl;
	// insertion
	obj.insert(n,data);    // function call
	cout<<"\nArray after insertion is"<<endl<<endl;
	obj.display(n+1); // function call
	return 0;
}
