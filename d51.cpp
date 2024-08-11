// bubble sort

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
		void bubble_sort(int);
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
	   cout<<setw(8)<<setprecision(6)<<a[i];
}

// function definition bubble_sort()
void array::bubble_sort(int n)
{
	float temp;
	int i,last,pass,exchs;
	last = n-1;
	for(pass=0;pass<n-1;++pass)
	{
		exchs = 0;
		for(i=0;i<last;++i)
		{
			if(a[i]>a[i+1])
			{
				++exchs;
				  temp = a[i];
				  a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
		--last;
		cout<<"\n\nPass number : "<<pass+1<<" No. of exchanges : "<<exchs<<endl;
		if(exchs == 0)
		   return;
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
	obj.bubble_sort(n); // function call
	cout<<"\n\nArray after sorting is"<<endl<<endl;
	obj.display(n); // function call
	return 0;
}
