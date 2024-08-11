// deletion of a specific element from an unsorted array
// only first occurence of element is deleted 

#include<iostream>
#include<stdlib.h>
#define S 10

using namespace std;

class array
{
	private :
	    int i,a[S];
	public :
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
void array::del(int n,int data)
{
	int pos;
	// deletion
	for(i=0;i<n;++i)
	{
		if(a[i]==data)
		{
			for(pos=i+1;pos<n;++pos)
			   a[pos-1] = a[pos];
			a[n-1] = 0;
			return;
		}
	}
	cout<<"\n"<<data<<" not found in the array"<<endl<<endl;
	exit(0);	
}

int main()
{
	array obj;
	int n,data;
	cout<<"Enter the number of elements in the array <= "<<S<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" elements"<<endl<<endl;
	obj.enter(n); // function call
	cout<<"\nEnter the element to be deleted"<<endl<<endl;
	cin>>data;
	// echo the data
	cout<<"\nEntered array is"<<endl<<endl;
	obj.display(n); // function call
	cout<<"\n\nElement to be deleted is "<<data<<endl<<endl;
	// deletion
	obj.del(n,data); // function call
	cout<<"\nArray after deletion is"<<endl<<endl;
	obj.display(n-1); // function call
	return 0;
}
