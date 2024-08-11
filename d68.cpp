// Prim's algorithm for shortest path 

#include<iostream>
#include<iomanip>
#define INFINITY 9999
#define S 11
#define TRUE 1
#define FALSE 0

using namespace std;

class S_path
{
	private :
		int i,j;
	public :
		void enter(int w[S][S],int n);
		void display(int w[S][S],int n);
		void Prim(int w[S][S],int n);
};

// function definition enter()
void S_path::enter(int w[S][S],int n)
{
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
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
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cout<<setw(6)<<w[i][j];
		cout<<endl;
	}
}

// function definition Prim()
void S_path::Prim(int w[S][S],int n)
{
	int visited[S],edges,v1,v2,min,min_dist=0;  
    // create a array to track selected vertex
    // selected will become true otherwise false
    for(i=0;i<n;++i)
        visited[i] = FALSE;
    // set number of edge to 0
    edges = 0;
    visited[0] = TRUE;
    cout<<"\nThe edges of minimum spanning tree are"<<endl<<endl;
    cout << "Edge"<< "  : "<< "Distance"<< endl;
    while (edges < n-1) 
    {
    	// for each vertex in the weighted graph w, find the all adjacent vertices
        // calculate the distance from the vertex selected above
        // if the vertex is already in the weighted graph w, discard it otherwise
        // choose another vertex nearest to the above selected one
        min = INFINITY;
        v1 = 0;
        v2 = 0;
        for(i=0;i<n;++i)
  	    {
            if(visited[i]) 
	        {
                for(j=0;j<n;++j) 
			    {
                    if( !visited[j] && w[i][j] != INFINITY)
				    {  
					    // not in selected and there is an edge
                        if (w[i][j] < min) 
					    {
                            min = w[i][j];
                            v1 = i;
                            v2 = j;
                        }
                    }
                }
            }
        }
        cout<<v1+1<<" - "<<v2+1<<" :    "<<w[v1][v2]<<endl;
        visited[v2] = TRUE;
        ++edges;
        min_dist += min;
    }
    cout<<"\nMinimum distance between all vertices = "<<min_dist<<endl;
}

int main() 
{
    S_path obj;
	int w[S][S],n;
    cout<<"\n\tImplementation of Prim's algorithm"<<endl;
    cout<<"\nEnter the number of vertices <= "<<S-1<<" : ";
    cin>>n;
    cout<<"\nEnter the weight adjacency matrix"<<endl<<endl;
    obj.enter(w,n);
    system("CLS");
    // echo the data
    cout<<"\nEntered weight matrix is"<<endl<<endl;
    obj.display(w,n);
    obj.Prim(w,n);
    return 0;
}

//0 7 3 12 0
//7 0 0 0 9
//3 0 0 0 7
//12 0 0 0 5
//0 9 7 5 0

//0 4 0 0 0 0 0 5 2
//4 0 4 2 0 0 0 0 1
//0 4 0 4 0 0 0 0 0
//0 2 4 0 9 0 0 0 3
//0 0 0 9 0 6 0 0 7
//0 0 0 0 6 0 5 1 4
//0 0 0 0 0 5 0 5 0
//5 0 0 0 0 1 5 0 8
//2 1 0 3 7 4 0 8 0

//0 2 0 0 0 1 6
//2 0 5 0 0 0 1
//0 5 0 6 0 0 3
//0 0 6 0 3 0 3
//0 0 0 3 0 2 7
//1 0 0 0 2 0 4
//6 1 3 3 7 4 0
