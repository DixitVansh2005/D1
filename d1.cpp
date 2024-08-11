// to swap two numbers in C++

#include<iostream>

using namespace std;

int main()
{
	int num1,num2,temp;
	cout<<"Enter two integers for swapping"<<endl;
	cin>>num1>>num2;
	// echo the data
	cout<<"\nEntered numbers are "<<num1<<" "<<num2<<endl;
	// swapping
	temp = num1;
	num1 = num2;
	num2 = temp;
	cout<<"\nSwapped numbers are "<<num1<<" "<<num2<<endl;
	return 0;
}
