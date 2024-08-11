// postfix expression evaluation using stack

#include<iostream>
#include<process.h>

using namespace std;

class node
{
	public:
	    float info;
	    node *next;
}*top = NULL;

class linked_list
{
	public:
		void push(float); // function prototype
		float pop();
		int total();
};

// function definition push()
void linked_list::push(float data)
{
	node *newptr = new node;
	newptr->info = data;
	newptr->next = top;
	top = newptr;
}

// function definition pop()
float linked_list::pop()
{
	node *temp = NULL;
	float topvalue;
	if(!top)
	{
		cout<<"\n\nSome operand is missing"<<endl<<endl;
		exit(1);
	}
	topvalue = top->info;
	temp = top;
	top = top->next;
	delete(temp);
	return(topvalue);
}

// function definition total()
// it returns number of elements left in the stack
int linked_list::total()
{
	int count = 0;
	node *temp=top;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	return(count);
}

int main()
{
	linked_list obj;
	char ch;
	int operand,tempdigit;
	float op1,op2,result;
	cout<<"Enter expression (with spaces) terminated by newline "<<endl<<endl;
	do
	{
		ch = cin.get();
		switch(ch)
		{
			case '+':   op1 = obj.pop(); // function call
			            op2 = obj.pop();
			            obj.push(op2+op1);
			            break;
			            
			case '-':   op1 = obj.pop(); // function call
			            op2 = obj.pop();
			            obj.push(op2-op1);
			            break;
			
			case '*':   op1 = obj.pop(); // function call
			            op2 = obj.pop();
			            obj.push(op2*op1);
			            break;
			            
			case '/':   op1 = obj.pop(); // function call
			            op2 = obj.pop();
			            obj.push(op2/op1);
			            break;
			            
			case '%':   op1 = obj.pop(); // function call
			            op2 = obj.pop();
			            obj.push((int)op2 % (int)op1);
			            break;
			
			case '\n':  // check the status of the stack
			            if(obj.total() > 1)
			               cout<<"\n\n"<<obj.total()-1<<" operator(s) is(are) missing"<<endl;
			            else
			            {
			            	result = obj.pop(); // function call
			            	cout<<"\nResult of evaluation is "<<result<<endl;
						}
			            exit(0);
			default :
				        operand = (int)ch - (int) '0';
				        tempdigit = 0;
				        if(operand >= 0 && operand <= 9)
				        {
				        	ch = cin.get();
				        	while(ch != ' ')
				        	{
				        		tempdigit = (int)ch - (int) '0';
				        		operand = operand*10+tempdigit;
				        		ch = cin.get();
							}
							obj.push(operand); // function call
						}
		}
	}while(1);
	return 0;
}
