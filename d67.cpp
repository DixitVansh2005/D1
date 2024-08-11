// Kruskal's algorithm for shortest path

#include<iostream>
#include<iomanip>
#define S 11
#define INFINITY 9999

using namespace std;

class S_path
{
	private :
		int i,j;
	public :
		void enter(int w[S][S],int n);
		void display(int w[S][S],int n);
		 int find(int parent[S],int);
		 int uni(int parent[S],int,int);
		void Kruskal(int w[S][S],int n);
};

// function definition enter()
void S_path::enter(int w[S][S],int n)
{
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
		    cin>>w[i][j];
		    if(w[i][j] == 0)
		        w[i][j] = INFINITY;
		}
	}
}

// function definition display()
void S_path::display(int w[S][S],int n)
{
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		    cout<<setw(6)<<w[i][j];
		cout<<endl;
	}
}

// function definition find()
int S_path::find(int parent[S],int i)
{
	// traverse parent array to find root of vertex i
    while(parent[i])
        i = parent[i]; 
    return i; // return root of the set containing vertex i
}

// function defnition uni()
int S_path::uni(int parent[S],int i,int j)
{
    if(i!=j)
    {
        parent[j]=i; // Union operation i.e., make i as parent of j
        return 1; // Union operation successful
    }
    return 0; // Union operation unsuccessful i.e., edge forms a cycle
}

// function definition Kruskal()
void S_path::Kruskal(int w[S][S],int n)
{
	int parent[S],edges,min,min_dist=0,v1,v2,a,b;
	// initialize parent array()
    for(i=1;i<=n;++i)
        parent[i] = 0;
    // initialize number of edges
    edges = 0;
	cout<<"\nThe edges of minimum spanning tree are"<<endl<<endl;
	cout<<"Edge"<< "  : "<< "Distance"<< endl;
    while(edges < n-1)
    {
        for(i=1,min=INFINITY;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(w[i][j] < min)
                {
                    min = w[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
        a = find(parent,v1);
        b = find(parent,v2);
        if(uni(parent,a,b))
        {
            cout<<v1<<" - "<<v2<<" :    "<<min<<endl;
            ++edges;
            min_dist += min;
        }
        else
        {
        	cout<<v1<<" - "<<v2<<" :    forms a cycle so not included"<<endl;
		}
        w[v1][v2] = w[v2][v1] = INFINITY;            
    }
    cout<<"\nMinimum distance between all vertices = "<<min_dist<<endl;
}

int main()
{
	S_path obj;
	int w[S][S],n;
    cout<<"\n\tImplementation of Kruskal's algorithm"<<endl;
    cout<<"\nEnter the number of vertices <= "<<S-1<<" : ";
    cin>>n;
    cout<<"\nEnter the weight adjacency matrix"<<endl<<endl;
    obj.enter(w,n);
    system("CLS");
    // echo the data
    cout<<"\nEntered weight matrix is"<<endl<<endl;
    obj.display(w,n);
    obj.Kruskal(w,n);
    return 0;
}
