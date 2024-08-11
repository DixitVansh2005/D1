// transpose of a matrix

#include<iostream>
#include<iomanip> // for setw manipulator
#define S 5

using namespace std;

class matrix
{
	private :
		int i,j;
	public :
		void enter(int a[S][S],int,int);     // function prototype
		void display(int a[S][S],int,int);   // function prototype
		void transpose(int a[S][S],int,int); // function prototype
};

// function definition enter()
void matrix::enter(int a[S][S],int row,int col)
{
	// row wise reading
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		   cin>>a[i][j];
    }
}

// function definition display()
void matrix::display(int a[S][S],int row,int col)
{
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		   cout<<setw(6)<<a[i][j];
		cout<<endl;
	}
}

// function definition transpose()
void matrix::transpose(int a[S][S],int row,int col)
{
	for(j=0;j<col;++j)
	{
		for(i=0;i<row;++i)
		   cout<<setw(6)<<a[i][j];
		cout<<endl;
	}
}

int main()
{
	matrix obj;
	int a[S][S],row,col;
	do // get ranged value only
	{
		system("CLS");
		cout<<"Enter the order of matrix <= "<<S<<"*"<<S<<endl<<endl;
		cin>>row>>col;
	}while(row<=0 || row>S || col<=0 || col>S);
	cout<<"\nEnter the matrix of order "<<row<<"*"<<col<<endl<<endl;
	obj.enter(a,row,col); // function call
	// echo the data
	cout<<"\nEntered matrix is"<<endl<<endl;
	obj.display(a,row,col); // function call
	// transpose
	cout<<"\n\nTranspose of given matrix is"<<endl<<endl;
	obj.transpose(a,row,col); // function call
	return 0;
}
