// quick sort

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
		void quick_sort(int,int);
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

// function definition quick_sort()
void array::quick_sort(int lb,int ub)
{
	int i,j;
	float pivot_value,temp;
	
	if(lb >= ub) // base case for recursive function
	   return;
	
	i = lb; // i is used as left to right cursor
	j = ub; // j is used as right to left cursor
	
	pivot_value = a[lb];
	
	// swap elements >= pivot_value on left side
	// with elements <= pivot_value on right side
	while(1)
	{
		do
		{
			// find >= element on left side
			++i;
		}while(a[i]<pivot_value && i<=ub);
		
		while(a[j]>pivot_value && j>lb)
		{
			// find <= element on right side
			--j;
		}
		if(i>=j) // when swap pair not found
		    break;
		
		// swapping of elements using variable temp
	    temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	// place pivot_value at middle position that is j
	a[lb] = a[j];
	 a[j] = pivot_value;
	
	// sort left segment
	quick_sort(lb,j-1); // recursive call to function
	// sort right segment
	quick_sort(j+1,ub); // recursive call to function
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
	obj.quick_sort(0,n-1); // function call
	cout<<"\n\nArray after sorting is"<<endl<<endl;
	obj.display(n); // function call
	return 0;
}
