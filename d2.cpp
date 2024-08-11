// traversal in one dimensional array
// traversal means visiting each element of an array
// find sum and average of n numbers

#include<iostream>
#define S 20

using namespace std;

class array
{
	private:
	   int i;
	   float a[S];
	public:
		void enter(int);   // function prototype 
		void display(int); // function prototype
		void sumavg(int);  // function prototype
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

// function definition sumavg()
void array::sumavg(int n)
{
	float sum=0.0,avg;
	for(i=0;i<n;++i)
	   sum += a[i];
	avg = sum/n;
	cout<<"\n\nSum = "<<sum;
	cout<<"\n\nAverage = "<<avg;
}

// main() function
int main()
{
	array obj; // object declared
	int n;
	system("CLS"); // clears screen in dev c++
	cout<<"Enter the number of elements in the array <= "<<S<<endl;
	cin>>n;
	cout<<"\nEnter "<<n<<" elements :\n\n";
	obj.enter(n); // function call
	// echo the data
	cout<<"\nGiven array is :\n\n";
	obj.display(n); // function call
	obj.sumavg(n); // function call
	return 0;
}
