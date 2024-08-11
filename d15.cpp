// printing upper and lower triangle of a square matrix

#include<iostream>
#include<iomanip>  // for setw manipulator
#define S 5

using namespace std;

class matrix
{
	private :
		int i,j,a[S][S];
	public :
		void enter(int);        // function prototype
		void display(int);      // function prototype
		void print_triangles(int); // function prototype
};

// function definition enter()
void matrix::enter(int n)
{
	// row wise reading
	for(i=0;i<n;++i)
	   for(j=0;j<n;++j)
	      cin>>a[i][j];
}

// function definition display()
void matrix::display(int n)
{
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		   cout<<setw(6)<<a[i][j];
		cout<<endl;
	}
}

// function definition print_triangles()
void matrix::print_triangles(int n)
{
	// upper triangle
	cout<<"\nUpper Triangle of matrix is"<<endl<<endl;
	for(i=0;i<n;++i)
    {
    	for(j=0;j<i;++j)
    	   cout<<setw(6)<<" ";
    	for(j=i;j<n;++j)
    	   cout<<setw(6)<<a[i][j];
    	cout<<endl;
	}
	// lower triangle
	cout<<"\nLower Triangle of matrix is"<<endl<<endl;
	for(i=0;i<n;++i)
    {
    	for(j=0;j<=i;++j)
    	   cout<<setw(6)<<a[i][j];
    	cout<<endl;
	}	
}

int main()
{
	matrix obj;
	int n,a[S][S];
	do 
	{
		system("CLS");
		cout<<"Enter the order of square matrix <= "<<S<<"*"<<S<<endl<<endl;
		cin>>n;
	}while(n<=0 || n>S); // get ranged size only
	cout<<"\nEnter the matrix of order "<<n<<"*"<<n<<endl<<endl;
	obj.enter(n); // function call
	system("CLS");
	// echo the data
	cout<<"\nGiven Matrix is"<<endl<<endl;
	obj.display(n); // function call
	// print upper and lower triangles of matrix
	obj.print_triangles(n); // function call
	return 0;
}
