= // concatenate two arrays 

#include<iostream>
#define S 10
#define T 20

using namespace std;

class array
{
	private :
		int a[S],b[S],c[T],i,m,n;
	public :
		void enter(int *,int);                  // function prototype
		void display(int *,int);                // function prototype 
		void concat(int *,int *,int *,int,int); // function prototype
};

// function definition enter()
void array::enter(int a[S],int size)
{
	for(i=0;i<size;++i)
	   cin>>a[i];
}

// function definition display()
void array::display(int a[S],int size)
{
	for(i=0;i<size;++i)
	   cout<<a[i]<<" ";
}

// function definition concat()
void array::concat(int a[S],int b[S],int c[T],int m,int n)
{
	// concatenation
	for(i=0;i<m;++i)
	   c[i] = a[i]; // copy first array
	for(i=0;i<n;++i)
	   c[m+i] = b[i]; // copy second array
}

int main()
{
	array obj; 
	int a[S],b[S],c[T],m,n;
	cout<<"Enter the number of elements in first array <= "<<S<<endl<<endl;
	cin>>m;
	cout<<"\nEnter the "<<m<<" integers"<<endl<<endl;
	obj.enter(a,m); // function call
	cout<<"\nEnter the number of elements in second array <= "<<S<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" integers"<<endl<<endl;
	obj.enter(b,n); // function call
	// echo the data
	cout<<"\nFirst array is"<<endl<<endl;
	obj.display(a,m); // function call
	cout<<"\n\nSecond array is"<<endl<<endl;
	obj.display(b,n); // function call
	// concatenation
	obj.concat(a,b,c,m,n); // function call
	cout<<"\n\nConcatenated array is"<<endl<<endl;
	obj.display(c,m+n);
	return 0;
}
