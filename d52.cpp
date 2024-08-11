// selection sort

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
		void selection_sort(int);
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

// function definition selection_sort()
void array::selection_sort(int n)
{
	float temp;
	int i,pass,min_index;
	for(pass=0;pass<n-1;++pass)
	{
		min_index = pass;
		for(i=pass+1;i<n;++i)
		{
			if(a[i]<a[min_index])
			    min_index = i;
		}
		// if assumption is not appropriate
		if(pass != min_index)
		{
			// swap the elements
			        temp = a[pass];
			     a[pass] = a[min_index];
			a[min_index] = temp;
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
	obj.selection_sort(n); // function call
	cout<<"\n\nArray after sorting is"<<endl<<endl;
	obj.display(n); // function call
	return 0;
}
