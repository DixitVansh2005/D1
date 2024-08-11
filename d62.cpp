// find the path matrix of a graph using Warshall algorithm

#include<iostream>
#include<iomanip>
#define S 10

using namespace std;

class S_path
{
	private :
		int i,j;
	public :
	    void enter(int a[S][S],int);
	    void display(int a[S][S],int);
	    void Warshall(int a[S][S],int p[S][S],int);
};

// function definition enter()
void S_path::enter(int a[S][S],int n)
{
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cin>>a[i][j];
	}
}

// function definition display()
void S_path::display(int a[S][S],int n)
{
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
}

// function definition Warshall()
void S_path::Warshall(int a[S][S],int p[S][S],int n)
{
	int k;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j] == 0)
			    p[i][j] = 0;
			else
			    p[i][j] = 1;
		}
	}
	// shortest path evaluation
	for(k=0;k<n;++k)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			    p[i][j] = p[i][j] | (p[i][k] & p[k][j]);
		}
	}
}

int main()
{
	S_path obj;
	int a[S][S],p[S][S],n;
	cout<<"Enter the number of vertices"<<endl;
	cin>>n;
	cout<<"\nEnter the adjacency matrix"<<endl;
	obj.enter(a,n); // function call
	// echo the data
	cout<<"\nAdjacency matrix is"<<endl;
	obj.display(a,n); // function call
	obj.Warshall(a,p,n); // function call
	cout<<"\nPath matrix is"<<endl<<endl;
	obj.display(p,n); // function call
	return 0;
}
