// merging of two arrays given in ascending order
// merged array is also in ascending order

#include<iostream>
#define S 10
#define T 20

using namespace std;

class array
{
	private :
		int i,j,k,a[S],b[S],c[T];
	public :
		void enter(int *,int);                 // function prototype
		void display(int *,int);               // function prototype
		void merge(int *,int *,int *,int,int); // function prototype
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

// function definition merge()
void array::merge(int a[S],int b[S],int c[S],int m,int n)
{
	// merging
	i=j=k=0;
	while((i<m) && (j<n))
	{
		if(a[i]<=b[j])
		   c[k++]=a[i++];
		else
		   c[k++]=b[j++];
	}
	if(i==m) // first array has been copied
	{
		// copy the remaining elements of second array
	    while(j<n)
	       c[k++]=b[j++];
    }
    else // second array has been copied
    {
    	// copy the remaining elements of first array
	    while(i<m)
	       c[k++]=a[i++];
	}
}

int main()
{
	array obj;
	int a[S],b[S],c[T],m,n;
	cout<<"Enter the number of elements in the first array <= "<<S<<endl<<endl;
	cin>>m;
	cout<<"\nEnter the "<<m<<" elements in ascending order"<<endl<<endl;
	obj.enter(a,m); // function call
	cout<<"\nEnter the number of elements in the second array <= "<<S<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" elements in ascending order"<<endl<<endl;
	obj.enter(b,n); // function call
	// echo the data
	cout<<"\nFirst array is"<<endl<<endl;
	obj.display(a,m); // function call
	cout<<"\n\nSecond array is"<<endl<<endl;
	obj.display(b,n); // function call
	
	// merging
	obj.merge(a,b,c,m,n); // function call
	cout<<"\n\nArray after merging is"<<endl<<endl;
	obj.display(c,m+n); // function call
	return 0;
}
