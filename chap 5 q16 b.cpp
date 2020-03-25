#include<iostream>
#include<cstring>
using namespace std;

bool check_palindrome(string str,int j,int size)
{
	static int i;
	if(i+j==size)
	{
		return true;
	}
	else if( (str[i]>=65 && str[i]<=122) && (str[j]>=65 && str[j]<=122) )
	{
		if( (str[i]==str[j]) || (str[i]==str[j]+32) || (str[i]==str[j]-32))
		{
			i++;
			j--;
			check_palindrome(str,j,size);
		}
		else
		{
			return false;
		}
	}
	else
	{
		if( (str[i]>=65 && str[i]<=122)==0 && (str[j]>=65 && str[j]<=122)==0 )
		{
			i++;
			j--;
		}
		else if((str[i]>=65 && str[i]<=122)==0)
		{
			i++;
		}
		else if((str[j]>=65 && str[j]<=122)==0)
		{
			j--;
		}
		check_palindrome(str,j,size);
	}
}
int main()
{
	string str;
	cout<<"enter string: ";
	getline(cin,str);
	int size;
	for(int i=0;str[i]!='\0';i++)
	{
		if( (str[i]>=65 && str[i]<=122) )
		{
			size++;
		}
	}
	if(check_palindrome(str,str.size()-1,size))
	{
		cout<<"String is palindrome";
	}
	else
	{
		cout<<"String is not palindrome";
	}
	return 0;
}
