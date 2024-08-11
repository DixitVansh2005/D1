// merge sort

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
		void merge_sort(int,int);
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

// function definition merge_sort()
void array::merge_sort(int lb,int ub)
{
	void merge(float a[],int,int,int); // function prototype
	int middle;
	
	if(lb < ub) 
	{
		middle = (lb+ub)/2;      // divide the array into two halves
		merge_sort(lb,middle);   // function call for left half
		merge_sort(middle+1,ub); // function call for right half
		merge(a,lb,middle,ub);   // function call merge()
	}
}

// function definition merge()
void merge(float a[],int low,int mid,int high)
{
	float temparr[SIZE];
	int i,j,k;
	i = low;
	j = mid+1;
	k = low;
	while(i<=mid && j<=high)
	{
		if(a[i] <= a[j])
		{
			temparr[k] = a[i];
			++i;
		}
		else
		{
			temparr[k] = a[j];
			++j;
		}
		++k;
	}
	if(i<=mid) // if elements in the first segment are left
	{
		while(i<=mid)
		{
			temparr[k] = a[i];
			++i;
			++k;
		}
	}
	else // if elements in second segment are left
	{
		while(j<=high)
		{
			temparr[k] = a[j];
			++j;
			++k;
		}
	}
	// copy the elements from array temparr[] to array a[]
	for(i=low;i<=high;++i)
	   a[i] = temparr[i];
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
	obj.merge_sort(0,n-1); // function call
	cout<<"\n\nMerge sorted array is"<<endl<<endl;
	obj.display(n); // function call
	return 0;
}
