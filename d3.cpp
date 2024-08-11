// insertion in an array

#include<iostream>
#define S 11

using namespace std;

class array
{
	private:
	   int i;
	   float a[S];
	public:
		void enter(int);   // function prototype 
		void display(int); // function prototype
		void insert(int);  // function prototype
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
void array::insert(int n)
{
	int data,pos;
	cout<<"\n\nEnter the element to be inserted "<<endl<<endl;
	cin>>data;
	cout<<"\n\nEnter the position of insertion <= "<<n+1<<endl<<endl;
	cin>>pos;
	cout<<"\nElement to be inserted is "<<data<<endl<<endl;
	cout<<"\nPosition of insertion is "<<pos<<endl<<endl;
	// backward shifting of elements
	for(i=n-1;i>=pos-1;--i)
	   a[i+1] = a[i];
	// insertion of element
	a[pos-1] = data;
}

int main()
{
	array obj; // object declared
	int n;
	system("CLS"); // clears screen in dev c++
	cout<<"Enter the number of elements in the array <= "<<S-1<<endl<<endl;
	cin>>n;
	cout<<"\nEnter "<<n<<" elements"<<endl<<endl;
	obj.enter(n);  // function call
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(n);   // function call
	obj.insert(n);    // function call
	obj.display(n+1); // function call
	return 0;
}
