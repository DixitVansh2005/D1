// heap sort for ascending order
// in general a heap represented by an array a[] of n elements satisfies the property
// a[cpos] <= a[parpos] for 2<=cpos<=n and parpos=(int)(cpos/2) assuming the array index starts with 1

#include<iostream>
#include<iomanip>
#define SIZE 32
// heap of upto 31 elements can be stored as index of array start from 1

using namespace std;

class array
{
	private :
		int a[SIZE],i;
	public :
		void enter(int); // function prototype
		void display(int);
		void create_heap(int);
		void heap_sort(int);
};

// function definition enter()
void array::enter(int n)
{
	for(i=1;i<=n;++i)
	   cin>>a[i];
}

// function definition display()
void array::display(int n)
{
	for(i=1;i<=n;++i)
	   cout<<setw(6)<<a[i];
}

// function definition create_heap
void array::create_heap(int n)
{
	int parpos,cpos,k,value;
	for(k=2;k<=n;++k)
	{
		// initialize
		 cpos = k;
		value = a[k];
		// now obtain the parent of new key
		parpos = cpos/2;
		// place the new key in existing heap
		while( cpos>1 && value>a[parpos] )
		{
			a[cpos] = a[parpos]; // interchange key
			// now obtain the new parent
			cpos = parpos;
			parpos = cpos/2;
			if(parpos<1)
			    parpos=1;
		}
		// place the new key in it's proper position
		a[cpos] = value;
		// display the current heap
		cout<<"\nk = "<<setw(2)<<k<<" Heap is :";
		display(k); // function call
	}
}

// function definition heap_sort()
void array::heap_sort(int n)
{
	int k,parpos,cpos,temp,value; 
	// perform the sort on array elements
	// total n-1 passes are required for sorting the array
	for(k=n;k>=2;--k)
	{
		// swap the elements
		temp = a[1];
		a[1] = a[k];
		a[k] = temp;
		// initialize the pass
		parpos = 1;
		value = a[1];
		cpos = 2;
		// obtain position of the largest child of new key
		if(cpos+1<k)
		{
			if(a[cpos+1]>a[cpos])
			    ++cpos;
		}
		// now reconstruct new heap
		while((cpos<k) && (a[cpos]>value))
		{
			a[parpos] = a[cpos];
			// now obtain the next left child
			parpos = cpos;
			  cpos = parpos*2;
			// now obtain the position of next largest child
			if(cpos+1 < k)
			{
				if(a[cpos+1]>a[cpos])
				    ++cpos;
				else
				{
					if(cpos>n)
					    cpos = n;
				}
			}
			// copy the element in the proper position
			a[parpos] = value;
		}
		// echo the state of the sort after the pass
		cout<<"k = "<<setw(2)<<k<<" gives : ";
		for(i=1;i<k;++i)
		    cout<<setw(5)<<a[i];
		cout<<endl;
	}
}


int main()
{
	array obj;
	int a[SIZE],n,max;
	char ch;
	cout<<"Enter the number of elements in the array <= "<<SIZE-1<<endl<<endl;
	cin>>n;
	cout<<"\nEnter the "<<n<<" integers for sorting"<<endl<<endl;
	obj.enter(n); // function call
	system("CLS"); // clears the screen
	// echo the data
	cout<<"\nGiven array is"<<endl<<endl;
	obj.display(n); // function call
	fflush(stdin);
	cout<<"\nPress enter key to continue...";
	ch = cin.get();
	system("CLS");
	// sorting
	cout<<"\nTrace of heap is given below"<<endl;
	obj.create_heap(n); // function call
	fflush(stdin);
	cout<<"\nPress enter key to continue...";
	ch = cin.get();
	system("CLS");
	cout<<"\nTrace of heap sort is given below"<<endl;
	obj.heap_sort(n); // function call
	cout<<"\n\nHeap sorted array is"<<endl<<endl;
	obj.display(n); // function call
	return 0;

