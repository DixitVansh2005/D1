// implementation of a binary tree

#include<iostream>
#include<iomanip>

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
	private :
		binarytree *s[]; // stack 
	public :
		void insert(binarytree **,int); // function prototype 
		void preorder(binarytree *);
		void inorder(binarytree *);
		void postorder(binarytree *);
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

// function definition preorder()
void linked_list::preorder(binarytree *t)
{
	int top = -1;
	if(t == NULL)
	    return;
	++top;
	s[top] = t;
	while(top != -1)
	{
		t = s[top];
		--top;
		while(t != NULL)
		{
			cout<<setw(8)<<t->info;
			if(t->rptr != NULL)
			{
				++top;
				s[top] = t->rptr; // store address of non empty right subtree
			}
			t = t->lptr; // branch left
		}
	}
}

// function definition inorder()
void linked_list::inorder(binarytree *t)
{
	int top = -1;
	do
	{
	    while(t != NULL)
	    {
	        ++top;
	        s[top] = t;
	        t = t->lptr; // branch left
	    }
	    if(top == -1)
	        break;
	    // pop the node
	    t = s[top];
	    --top;
	    cout<<setw(8)<<t->info; // print the info
	    t = t->rptr; // branch right
	}while(t != NULL || top != -1);
}

// function definition postorder()
void linked_list::postorder(binarytree *t)
{
	int top = -1;
	if(t == NULL)
	    return;
	do
    {
        while(t != NULL)
	    {
	        if(t->rptr != NULL) // push the right child
	        {
	        	++top;
	            s[top] = t->rptr;
	        }
	        // push the node
	        ++top;
	        s[top] = t;
	        t = t->lptr;
	    }
	    // pop the node
        t = s[top];
        --top;
        if(t->rptr != NULL && s[top] == t->rptr)
	    {
	    	// pop the stack
	        --top;
	        ++top;
	        s[top] = t;
	        t = t->rptr;
	    }
        else
	    {
	        cout<<setw(8)<<t->info;
	        t = NULL;
	    }
   }while (top != -1);
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
	obj.preorder(t); // function call
	cout<<"\nInorder Traversal : ";
	obj.inorder(t); // function call
	cout<<"\nPostorder Traversal : ";
	obj.postorder(t); // function call
    return 0;
}
