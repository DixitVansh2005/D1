// counting sort

#include<iostream>
#include<iomanip>
#define SIZE 20

using namespace std;

class array
{
	private :
		int a[SIZE],i;
	public :
		void enter(int); // function prototype
		void display(int);
		void counting_sort(int);
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
	   cout<<setw(6)<<a[i];
}

// function definition counting_sort()
void array::counting_sort(int n)
{
	int largest(int a[],int n); // function prototype
	int output[n];
	int max = largest(a,n);
	int count[max+1]; 
	for(i=0;i<=max;++i)
	   count[i] = 0; // initialize the count array with all zeros
	for(i=0;i<n;++i) 
	   count[a[i]]++; // store the count of each element
	for(i=1;i<=max;++i)
	   count[i] += count[i-1]; // find the cumulative frequency
	   
	// find the index of each element of the original array in count array
	// and place the elements in output array
	for(i=n-1;i>=0;--i)
	{
		output[count[a[i]]-1] = a[i];
		count[a[i]]--; // decrease count for same numbers
	}
	for(i=0;i<n;++i) 
	   a[i] = output[i];
}

// function definition largest()
int largest(int a[],int n)
{
	int max = a[0],i;
	for(i=1;i<n;++i)
	{
		if(a[i]>max)
		   max = a[i];
	}
	return max; // return largest element from the array
}

int main()
{
	array obj;
	int a[SIZE],n,max;
	cout<<"Enter the number of elements in the array <= "<<SIZE<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" integers >=0 for sorting"<<endl<<endl;
	obj.enter(n); // function call
	system("CLS"); // clears the screen
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(n); // function call
	// sorting
	obj.counting_sort(n); // function call
	cout<<"\n\nCount sorted array is"<<endl<<endl;
	obj.display(n); // function call
	return 0;
}
