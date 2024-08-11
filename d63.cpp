// find the path matrix of a graph using modified Warshall algorithm

#include<iostream>
#include<iomanip>
#define S 10
#define INFINITY 9999

using namespace std;

class S_path
{
	private :
		int i,j;
	public :
	    void enter(int a[S][S],int);
	    void display(int a[S][S],int);
	    void m_Warshall(int a[S][S],int p[S][S],int);
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
		    cout<<setw(6)<<a[i][j];
		cout<<endl;
	}
}

// function definition m_Warshall()
void S_path::m_Warshall(int a[S][S],int p[S][S],int n)
{
	int k;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j] == 0)
			    p[i][j] = INFINITY;
			else
			    p[i][j] = a[i][j];
		}
	}
	cout<<"\nAdjacency matrix after replacing zeroes by "<<INFINITY<<" is"<<endl;
	display(p,n); // function call
	
	// shortest path evaluation
	for(k=0;k<n;++k)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				if(p[i][j] > p[i][k] + p[k][j])
				    p[i][j] = p[i][k] + p[k][j];
			}
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
	obj.m_Warshall(a,p,n); // function call
	cout<<"\nPath matrix is"<<endl<<endl;
	obj.display(p,n); // function call
	return 0;
}
