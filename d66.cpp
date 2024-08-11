// Dijkstra's shortest path algorithm
// for finding shortest path from a given vertex to all other vertices

#include<iostream>
#include<iomanip>
#define INFINITY 9999
#define S 10

using namespace std;

class S_path
{
	private :
		int i,j;
	public :
	    void enter(int g[S][S],int);
	    void display(int g[S][S],int);
	    void Dijkstra(int g[S][S],int n,int start);
};

// function definition enter()
void S_path::enter(int g[S][S],int n)
{
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cin>>g[i][j];
	}
}

// function definition display()
void S_path::display(int g[S][S],int n)
{
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cout<<setw(6)<<g[i][j];
		cout<<endl;
	}
}

// function definition Dijkstra()
void S_path::Dijkstra(int g[S][S],int n,int start)
{
    int w[S][S],dist[S],visited[S],count,mindist,current;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(g[i][j] == 0)
                w[i][j] = INFINITY;
            else
                w[i][j] = g[i][j];
        }
    }
    for(i=0;i<n;++i)
	{
        dist[i] = w[start][i];
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    while(count<n-1) 
	{
        mindist = INFINITY;
        for(i=0;i<n;++i)
        {
            if( (dist[i] < mindist) && !visited[i]) 
		    {
                mindist = dist[i];
                current = i;
            }
        }
        visited[current] = 1;
        for(i=0;i<n;++i)
        {
            if(! visited[i])
            {
                if((mindist + w[current][i]) < dist[i]) 
                    dist[i] = mindist + w[current][i];
            }
        }
        count++;
    }
    for(i=0;i<n;i++)
    {
        if(i!=start)
            cout<<"\nDistance of node "<<i<<" = "<<dist[i];
    }
}

int main()
{
	S_path obj;
    int g[S][S],n,start;
	cout<<"Enter the number of vertices"<<endl;
	cin>>n;
	cout<<"\nEnter the weight matrix"<<endl;
	obj.enter(g,n); // function call
	system("CLS");
	// echo the data
	cout<<"Weight matrix is"<<endl;
	obj.display(g,n); // function call
    cout<<"\nEnter the starting node number 0 to "<<n-1<<" : ";
    cin>>start;
    obj.Dijkstra(g,n,start);
    return 0;
}



