// searching and insertion in a binary search tree

#include<iostream>
#include<iomanip>

using namespace std;

class bstree
{
	public :
		bstree *lptr;
		int info;
		bstree *rptr; 
};

class linked_list
{
	public :
		void insert(bstree **,int); // function prototype 
		void rpreorder(bstree *);
		bstree *find(bstree *,int);
};

// function definition insert() recursively
void linked_list::insert(bstree **root,int num)
{
	if(*root==NULL)
	{
		*root = new bstree;
		(*root)->lptr = NULL;
		(*root)->info = num;
		(*root)->rptr = NULL;
		return;
	}
	else
	{
		// search the node to which new node will be attached
		if(num<(*root)->info) // if new data is less traverse to left
		    insert(&((*root)->lptr),num);
		else // else traverse to right
		    insert(&((*root)->rptr),num);
	}
	return;
}

// function definition rpreorder() recursively
void linked_list::rpreorder(bstree *t)
{
	if(t == NULL)
	    return;
	cout<<setw(8)<<t->info;
	rpreorder(t->lptr);
	rpreorder(t->rptr);
}

// function definition find() recursively
bstree *linked_list::find(bstree *t,int info)
{	
    bstree *temp = t;
    if(temp==NULL || temp->info == info)
        return temp;
    if (info < temp->info)
        find(temp->lptr,info);
    else
        find(temp->rptr,info);
}

int main()
{
	linked_list obj;
	bstree *t=NULL,*pos=NULL,*parpos=NULL,*newptr=NULL;
	int n,num,info,i;
	cout<<"Enter number of data items to be inserted : ";
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cout<<"\nEnter the data : ";
		cin>>num;
		obj.insert(&t,num); // function call
	}
	cout<<"\nPreorder traversal : ";
	obj.rpreorder(t); // function call
	cout<<"\nEnter the element to be searched : ";
	cin>>info;
	if(obj.find(t,info) == NULL)
	    cout<<"\n"<<info<<" not found in the binary search tree"<<endl;
    else
        cout<<"\n"<<info<<" found in the binary search tree "<<endl;
    return 0;
}
