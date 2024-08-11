// illustration of various string operations 

#include<iostream>
#include<string.h>

using namespace std;

class String
{
	public:
	    int strLength(char *cptr); // function prototype
	    void strCopy(char *dest,char *source); 
	    char *strConcat(char *dest,char *source);
	    int strComp(char *str1,char *str2);
	    void strRev(char *str1); 
	    char *subStrLeft(char *str1,int n); 
	    char *subStrRight(char *str1,int n);
	    char *subStrMid(char *str1,int m,int n);
	    void toUpperCase(char *str1); 
	    void toLowerCase(char *str1);
};

// function definition strLength()
int String::strLength(char *cptr)
{
	int len=0;
	while(*cptr)
	{
		++len;
		++cptr;
	}
	return(len);
}

// function definition strCopy()
void String::strCopy(char *dest,char *source)
{
	char *ptr1,*ptr2;
	ptr1 = source;
	ptr2 = dest;
	while(*ptr1)
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
	}
	*ptr2 = '\0';
}

// function definition strConcat()
char *String::strConcat(char *dest,char *source)
{
	char *ptr1,*ptr2;
	ptr1 = source;
	ptr2 = dest;
	while(*ptr2++)
	   ;
	ptr2--; // position before null character
	while(*ptr1)
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
	}
	*ptr2 = '\0';
	return(dest);
}

// function definition strComp()
int String::strComp(char *str1,char *str2)
{
	char *ptr1,*ptr2;
	ptr1 = str1;
	ptr2 = str2;
	while((*ptr1 == *ptr2) && (*ptr1 && *ptr2))
	{
		++ptr1;
		++ptr2;
	}
	if(*ptr1 == '\0' && *ptr2 == '\0')
	   return 0;
	else if(*ptr1 == '\0')
	   return -1;
	else if(*ptr2 == '\0')
	   return 1;
	else
	   return(*ptr1 - *ptr2);
}

// function definition strRev()
void String::strRev(char *str1)
{
	char *ptr1,*ptr2,temp;
	ptr1 = str1;
	ptr2 = str1;
	while(*ptr2 != '\0')
	   ++ptr2;
	--ptr2; // position before null character
	while(ptr1 < ptr2)
	{
		 temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
		++ptr1;
		--ptr2;
	}
}

// function definition subStrLeft()
char *String::subStrLeft(char *str1,int n)
{
	char *ptr1,*temp,*ptr2 = '\0';
	ptr1 = str1;
	if(n==0)
	   return ptr2;
	temp = ptr2 = new char[n+1];
	while((*ptr1) && (n>0))
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
		--n;
	}
	*ptr2 = '\0';
	return(temp);
}

// function definition subStrRight()
char *String::subStrRight(char *str1,int n)
{
	char *ptr1,*temp,*ptr2 = '\0';
	ptr1 = str1;
	if(n==0)
	   return ptr2;
	temp = ptr2 = new char[n+1];
	while(*ptr1++)
	   ;
	ptr1 -= n+1;
	while(*ptr1)
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
		--n;
	}
	*ptr2 = '\0';
	return(temp);
}

// function definition subStrMid()
char *String::subStrMid(char *str1,int m,int n)
{
	char *ptr1,*temp,*ptr2 = '\0';
	ptr1 = str1;
	if(n==0)
	   return ptr2;
	temp = ptr2 = new char[n+1];
	ptr1 += m;
	while((*ptr1) && (n>0))
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
		--n;
	}
	*ptr2 = '\0';
	return(temp);
}

// function definition toUpperCase()
void String::toUpperCase(char *str1)
{
	char *ptr1;
	ptr1 = str1;
	while(*ptr1)
	{
		if((*ptr1 >= 'a') && (*ptr1 <= 'z'))
		   *ptr1 -= 32;
		++ptr1;
	}
}

// function definition toLowerCase()
void String::toLowerCase(char *str1)
{
	char *ptr1;
	ptr1 = str1;
	while(*ptr1)
	{
		if((*ptr1 >= 'A') && (*ptr1 <= 'Z'))
		   *ptr1 += 32;
		++ptr1;
	}
}

int main()
{
	String obj;
	char str1[] = "Mastering C";
	char str2[10] = " Programs";
	char tempstr[40];
	char *p;
	int diff;
	
	cout<<"\nString length of str1 is "<<obj.strLength(str1)<<endl; // function call
	
	obj.strCopy(tempstr,str1); // function call 
	cout<<"\nCopied string is "<<tempstr<<endl;
	
	p = obj.strConcat(tempstr,str2); // function call
	cout<<"\nConcatenated string is "<<p<<endl;
	
	diff = obj.strComp(str1,str2); // function call
	if(diff == 0)
	   cout<<"\nStrings are identical"<<endl;
	else if(diff > 0)
	   cout<<"\nString "<<str1<<" comes after String "<<str2<<endl;
	else 
	   cout<<"\nString "<<str1<<" comes before String "<<str2<<endl;
	
	cout<<"\nOriginal String is "<<str2<<endl;
	obj.strRev(str2); // function call
	cout<<"\nReversed String is "<<str2<<endl;
	
	p = obj.subStrLeft(str1,5); // function call
	cout<<"\nLeft substring is "<<p<<endl;
	
	p = obj.subStrRight(str1,5); // function call
	cout<<"\nRight substring is "<<p<<endl;
	
	p = obj.subStrMid(str1,4,6); // function call
	cout<<"\nMiddle substring is "<<p<<endl;
	
	obj.toUpperCase(str1); // function call
	cout<<"\nUpper case string is "<<str1<<endl;
	
	obj.toLowerCase(str1); // function call
	cout<<"\nLower case string is "<<str1<<endl;
	
	return 0;
}
