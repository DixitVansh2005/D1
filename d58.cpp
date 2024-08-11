// implementation of a binary tree

#include<iostream>

using namespace std;

class binarytree
{
	public :
		binarytree *lptr;
		int info;
		binarytree *rptr; 
};

class linked_list
{
	public :
		void insert(binarytree **,int); // function prototype 
		void rpreorder(binarytree *);
		void rinorder(binarytree *);
		void rpostorder(binarytree *);
};

// function definition insert()
void linked_list::insert(binarytree **root,int num)
{
	if(*root==NULL)
	{
		*root = new binarytree;
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

// function definition rpreorder()
void linked_list::rpreorder(binarytree *sr)
{
	if(sr != NULL)
	{
		// print the info of a node
		cout<<" "<<sr->info;
		rpreorder(sr->lptr); // traverse till lptr is not NULL
		rpreorder(sr->rptr); // traverse till rptr is not NULL
	}
	else
	   return;
}

// function definition rinorder()
void linked_list::rinorder(binarytree *sr)
{
	if(sr != NULL)
	{
		rinorder(sr->lptr); // print the node whose lptr is NULL or path has already been traversed
		cout<<" "<<sr->info;
		rinorder(sr->rptr);
	}
	else
	   return;
}

// function definition rpostorder()
void linked_list::rpostorder(binarytree *sr)
{
	if(sr != NULL)
	{
		rpostorder(sr->lptr); // traverse till lptr is not NULL
		rpostorder(sr->rptr); // traverse till rptr is not NULL
		cout<<" "<<sr->info;
	}
	else
	   return;
}

int main()
{
	linked_list obj;
	binarytree *t;
	int n,num,i;
	t = NULL; // empty tree
	cout<<"Enter number of data items to be inserted : ";
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cout<<"\nEnter the data : ";
		cin>>num;
		obj.insert(&t,num); // function call
	}
	cout<<"\nPreorder Traversal : ";
	obj.rpreorder(t); // function call
	cout<<"\nInorder Traversal : ";
	obj.rinorder(t); // function call
	cout<<"\nPostorder Traversal : ";
	obj.rpostorder(t); // function call
}
