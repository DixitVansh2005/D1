// to delete all occurences of an integer number
// to shift all the non deleted members to left
// and fill the unused space by 0 (zero)

#include<iostream>
#define S 10

using namespace std;

class array
{
	private :
		int i,a[S];
	public :
		void enter(int *,int);   // function prototype
		void display(int *,int); // function prototype
		int del(int *,int,int); // function prototype
};

// function definition enter()
void array::enter(int a[S],int n)
{
	for(i=0;i<n;++i)
	   cin>>a[i];
}

// function definition display()
void array::display(int a[S],int n)
{
	for(i=0;i<n;++i)
	   cout<<a[i]<<" ";
}

// function definition del()
int array::del(int a[S],int data,int n)
{
	int j,count=0,last=n-1;
	i=0;
	while(i<=last)
	{
		if(a[i]==data)
		{
			++count;
			for(j=i+1;j<=last;++j)
			   a[j-1] = a[j];
			--last;
		}
		else
		   ++i;
	}
	for(j=last+1;j<n;++j)
	   a[j] = 0;
	return(count);
}

int main()
{
	array obj;
	int n,data,flag,a[S];
	cout<<"Enter number of elements <= "<<S<<endl<<endl;
	cin>>n;
	cout<<"\nEnter "<<n<<" elements"<<endl;
	obj.enter(a,n); // function call
	cout<<"\nEnter the element to be deleted"<<endl;
	cin>>data;
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(a,n); // function call
	cout<<"\n\nElement whose all occurences are to be deleted is "<<data<<endl;
	// deletion
	flag = obj.del(a,data,n); // function call
	if(flag)
	{
		cout<<"\nArray after deletion is"<<endl<<endl;
		obj.display(a,n);
	}
	else
	   cout<<"\nDeletion not possible"<<endl<<endl;
	return 0;
}
