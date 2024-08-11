// multiplication of two matrices

#include<iostream>
#include<iomanip> // for setw manipulator
#define S 5

using namespace std;

class matrix
{
	private :
		int i,j,x[S][S],y[S][S],z[S][S];
	public :
		void enter(int x[S][S],int,int);                              // function prototype
		void display(int x[S][S],int,int);                            // function prototype
		void matmul(int x[S][S],int y[S][S],int z[S][S],int,int,int); // function prototype
};

// function definition enter()
void matrix::enter(int x[S][S],int row,int col)
{
	// row wise reading
	for(i=0;i<row;++i)
	   for(j=0;j<col;++j)
	      cin>>x[i][j];
}

// function definition display()
void matrix::display(int x[S][S],int row,int col)
{
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		   cout<<setw(6)<<x[i][j];
		cout<<endl;
	}
}

// function definition matmul()
void matrix::matmul(int x[S][S],int y[S][S],int z[S][S],int row1,int row2,int col2)
{
	int k;
	for(i=0;i<row1;++i)
	{
		for(j=0;j<col2;++j)
		{
	        z[i][j]=0;
	        for(k=0;k<row2;++k)
		        z[i][j] += x[i][k]*y[k][j];
	    }
	}
}

int main()
{
	matrix obj;
	int a[S][S],b[S][S],c[S][S],row1,col1,row2,col2;
	cout<<"Enter the order of first matrix <= "<<S<<"*"<<S<<endl<<endl;
	cin>>row1>>col1;
	cout<<"\nEnter the order of second matrix <= "<<S<<"*"<<S<<endl<<endl;
	cin>>row2>>col2;
	if(col1 != row2)
	   cout<<"\nMatrix multiplication not possible"<<endl<<endl;
	else
	{
		cout<<"\nEnter the first matrix of order "<<row1<<"*"<<col1<<endl<<endl;
		obj.enter(a,row1,col1); // function call
		cout<<"\nEnter the second matrix of order "<<row2<<"*"<<col2<<endl<<endl;
		obj.enter(b,row2,col2); // function call
		system("CLS"); // clears the screen
		// echo the data
		cout<<"\nFirst matrix is"<<endl<<endl;
		obj.display(a,row1,col1); // function call
		cout<<"\n\nSecond matrix is"<<endl<<endl;
		obj.display(b,row2,col2); // function call
		// matrix multiplication
		obj.matmul(a,b,c,row1,row2,col2); // function call
		cout<<"\n\nProduct of the two matrices is"<<endl<<endl;
		obj.display(c,row1,col2); // function call
	}
	return 0;
}
