// sum of elements of either diagonals of a square matrix

#include<iostream>
#include<iomanip>  // for setw manipulator
#define S 5

using namespace std;

class matrix
{
	private :
		int i,j,order,a[S][S];
	public :
		void enter(int);        // function prototype
		void display(int);      // function prototype
		void sum_diagonal(int); // function prototype
};

// function definition enter()
void matrix::enter(int order)
{
	// row wise reading
	for(i=0;i<order;++i)
	   for(j=0;j<order;++j)
	      cin>>a[i][j];
}

// function definition display()
void matrix::display(int order)
{
	for(i=0;i<order;++i)
	{
		for(j=0;j<order;++j)
		   cout<<setw(6)<<a[i][j];
		cout<<endl;
	}
}

// function definition sum_diagonal()
void matrix::sum_diagonal(int order)
{
	int sum;
	// sum of elements of both diagonals
	for(i=0;i<order;++i)
    {
    	for(j=0;j<order;++j)
    	{
    		if(i==j || i+j==order-1)
    		   sum+=a[i][j];
		}
	}
	cout<<"\nSum of elements on both diagonals is "<<sum<<endl<<endl;	
}

int main()
{
	matrix obj;
	int order,a[S][S];
	do 
	{
		system("CLS");
		cout<<"Enter the order of square matrix <= "<<S<<"*"<<S<<endl<<endl;
		cin>>order;
	}while(order<=0 || order>S); // get ranged size only
	cout<<"\nEnter the matrix of order "<<order<<"*"<<order<<endl<<endl;
	obj.enter(order); // function call
	// echo the data
	cout<<"\nGiven Matrix is"<<endl<<endl;
	obj.display(order); // function call
	// sum of elements on both diagonals
	obj.sum_diagonal(order); // function call
	return 0;
}
