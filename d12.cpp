// Traversal of a two dimensional array
// display elements of a two dimensional array divisible by 5

#include<iostream>
#include<iomanip> // for setw manipulator
#define S 5

using namespace std;

class array
{
	private :
		int i,j;
	public :
		void enter(int a[S][S],int,int);    // function prototype
		void display(int a[S][S],int,int);  // function prototype
		void display5(int a[S][S],int,int); // function prototype
};

// function definition enter()
void array::enter(int a[S][S],int row,int col)
{
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		   cin>>a[i][j];
	}
}

// function definition display()
void array::display(int a[S][S],int row,int col)
{
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		   cout<<setw(6)<<a[i][j];
		cout<<endl;
	}
}

// function definition display5()
void array::display5(int a[S][S],int row,int col)
{
	int count=0;
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		{
			if(a[i][j] % 5 ==0)
			{
				cout<<setw(6)<<a[i][j];
				++count;
			}
		}
	}
	if(!count)
	   cout<<"\nNot present in the array"<<endl<<endl;
}

int main()
{
	array obj;
	int a[S][S],row,col;
	cout<<"Enter the number of rows and columns in the 2-d array <= "<<S<<"*"<<S<<endl<<endl;
	cin>>row>>col;
	cout<<"\nEnter the 2-d array of order "<<row<<"*"<<col<<endl<<endl;
	obj.enter(a,row,col); // function call
	// echo the data
	cout<<"\nEntered 2-d array is"<<endl<<endl;
	obj.display(a,row,col); // function call
	
	// display elements divisible by 5
	cout<<"\n\nElements in the above array divisible by 5 are"<<endl<<endl;
	obj.display5(a,row,col); // function call
	return 0;
}
