// breadth first search technique for graph traversal

#include<iostream>
#include<iomanip>
#define S 20
#define TRUE 1
#define FALSE 0

using namespace std;

struct edge
{
	int terminal;
	edge *next;
};

struct vertex
{
	int visited;
	int vertex_no;
	char info;
	int path_length;
	edge *edge_ptr;
};

struct queue
{
	int info;
	queue *next;
};

class array
{		
	public :
		void enter(int a[S][S],int); // function prototype
		void display(int a[S][S],int);
		void table(int a[S][S],vertex vert[S],int); 
		edge *insert_vertex(int,edge *);
		void bfs(vertex vert[S],int);
		queue *insert_queue(int n,queue *first);
		queue *delete_queue(int *n,queue *first);
};

// function definition enter() to read adjacency matrix
void array::enter(int a[S][S],int n)
{
	int i,j;
	cout<<"\nEnter the adjacency matrix"<<endl;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cin>>a[i][j];
	}
}

// function definition display()
void array::display(int a[S][S],int n)
{
	int i,j;
	cout<<"\nAdjacency matrix is"<<endl;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		    cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
}

// function definition table()
void array::table(int a[S][S],vertex vert[S],int n)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		vert[i].visited = FALSE;
		vert[i].vertex_no = i+1;
		vert[i].info = 'A' + i;
		vert[i].path_length = 0;
		vert[i].edge_ptr = NULL;
	}
	
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j] > 0)
			    vert[i].edge_ptr = insert_vertex(j,vert[i].edge_ptr); // function call
		}
	}
}

// function definition insert_vertex()
edge *array::insert_vertex(int n,edge *first)
{
	edge *newptr,*current;
	newptr = new edge;
	newptr->terminal = n;
	newptr->next = NULL;
	if(!first)
	    return(newptr);
	for(current = first;current->next != NULL;current = current->next)
	    ; 
	current->next = newptr;
	return(first);
}

// function definition bfs() for computing path length
void array::bfs(vertex vert[S],int index)
{
	queue *qptr = NULL;
	edge *link;
	vert[index].visited = TRUE;
	qptr = insert_queue(index,qptr);
	while(qptr)
	{
		qptr = delete_queue(&index,qptr); // function call
		for(link = vert[index].edge_ptr; link!=NULL; link = link->next)
		{
			if(vert[link->terminal].visited == FALSE)
			{
				vert[link->terminal].visited = TRUE;
				vert[link->terminal].path_length = vert[index].path_length+1;
				qptr = insert_queue(link->terminal,qptr);
			}
		}
	}
}

// function definition insert_queue()
queue *array::insert_queue(int n,queue *first)
{
	queue *newptr,*current;
	newptr = new queue;
	newptr->info = n;
	newptr->next = NULL;
	if(!first)
	    return(newptr);
	for(current = first;current->next != NULL;current = current->next)
	    ;
	current->next = newptr;
	return(first);
}

//function definition delete_queue()
queue *array::delete_queue(int *n,queue *first)
{
	queue *prev;
	if(!first)
	    return(NULL);
	*n = first->info;
	prev = first;
	first = first->next;
	delete(prev);
	return(first);
}

int main()
{
	array obj;
	int a[S][S],i,n,index;
	vertex vert[S];
	edge *list;
	cout<<"Enter the number of vertices in the graph <= "<<S<<" : ";
	cin>>n;
	obj.enter(a,n); // function call
	system("CLS");
	obj.display(a,n); // function call
	obj.table(a,vert,n); // function call
	cout<<"\nEnter the starting vertex 0-"<<n-1<<" : ";
	cin>>index;
	obj.bfs(vert,index); // function call
	cout<<"\nPath length = 0 means that either it is the starting vertex or";
	cout<<" there is no path till that vertex"<<endl;
	cout<<"\nPath length of the vertex from "<<vert[index].info<<endl;
	cout<<"\nVertex     Path length     Vertex_connectivity"<<endl;
	for(i=0;i<n;++i)
	{
		cout<<"\n   "<<vert[i].info<<"             "<<vert[i].path_length;
		for(list = vert[i].edge_ptr;list != NULL; list = list->next)
		{
			cout<<"            ";
			cout.put(list->terminal + 'A');
		}
	}
	return 0;
}


