// insertion sort

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
		void insertion_sort(int);
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
	cout.precision(3);
	for(i=0;i<n;++i)
	   cout<<setw(8)<<a[i];
}

// function definition insertion_sort()
void array::insertion_sort(int n)
{
	int i,j,current,pos;
	// sorting
	for(i=1;i<n;++i)
	{
		current = a[i]; // current denotes the element to be arranged
		pos = 0;
		while((pos<i) && (a[pos]<=current))
	        ++pos;
		// if position of element is not appropriate
		if(pos != i)
		{
			// shifting
			for(j=i-1;j>=pos;--j)
			    a[j+1] = a[j];
			// insertion at appropriate position
			a[pos] = current;
		}
	}
}

int main()
{
	array obj;
	float a[SIZE];
	int n;
	cout<<"Enter the number of elements in the array <= "<<SIZE<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" elements for sorting"<<endl<<endl;
	obj.enter(n); // function call
	system("CLS"); // clears the screen
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(n); // function call
	// sorting
	obj.insertion_sort(n); // function call
	cout<<"\n\nArray after sorting is"<<endl<<endl;
	obj.display(n); // function call
	return 0;
}
