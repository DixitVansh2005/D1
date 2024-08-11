// deletion in a binary search tree

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
		void rinorder(bstree *);
		bstree *delnode(bstree *,int);
};

// function definition insert()
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

// function definition rinorder() recursively
void linked_list::rinorder(bstree *t)
{
	if(t != NULL)
	{
		rinorder(t->lptr); // print the node whose lptr is NULL or path has already been traversed
		cout<<" "<<t->info;
		rinorder(t->rptr);
	}
	else
	   return;
}

// function definition delnode() recursively
bstree *linked_list::delnode(bstree *t,int info)
{	
    bstree *temp,*par,*child;
    // base case
    if (t == NULL)
        return t;
    // if the info to be deleted is smaller than the t's info then it lies in the left subtree
    if (info < t->info) 
        t->lptr = delnode(t->lptr,info);
    // if the info to be deleted is greater than the t's info then it lies in the right subtree
    else if (info > t->info)
        t->rptr = delnode(t->rptr,info);
    // if info is same as t's info this node to be deleted with only one child or no child
    else 
	{
		if(t->lptr == NULL)
		{
            temp = t->rptr;
            delete t;
            return temp;
        }
        if(t->rptr == NULL) 
	    {
            temp = t->lptr;
            delete t;
            return temp;
        }
        // node has two children
	    // get the inorder child (smallest in the right subtree)
        par = t;
        child = t->rptr;
        while (child->lptr != NULL) 
	    {
            par = child;
            child = child->lptr;
        }
        // copy the inorder successor's content to this node
        t->info = child->info;
        // delete the inorder successor
        if(par->lptr == child)
            par->lptr = child->rptr;
        else
            par->rptr = child->rptr;
        delete child;
    }
    return t;
}

int main()
{
	linked_list obj;
	bstree *t=NULL;
	int n,num,info,i;
	cout<<"Enter number of data items to be inserted : ";
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cout<<"\nEnter the data : ";
		cin>>num;
		obj.insert(&t,num); // function call
	}
	cout<<"\nInorder traversal : ";
	obj.rinorder(t); // function call
	
	cout<<"\n\nEnter the info of a leaf node to be deleted : ";
	cin>>info;
    t = obj.delnode(t,info);
    cout<<"\nModified BST tree after deleting leaf node"<<endl;
    obj.rinorder(t);
    
    cout<<"\n\nEnter the info of a node with a single child to be deleted : ";
    cin>>info;
    t = obj.delnode(t,info);
    cout<<"\nModified BST tree after deleting single child node"<<endl;
    obj.rinorder(t);

    cout<<"\n\nEnter the info of a node with both child to be deleted : ";
    cin>>info;
    t = obj.delnode(t,info);
    cout<<"\nModified BST tree after deleting both child nodes"<<endl;
    obj.rinorder(t);
    return 0;
}
