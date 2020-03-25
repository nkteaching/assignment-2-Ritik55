#include<iostream>
#include<cstring>
using namespace std;

bool check_palindrome(string str,int j)
{
	static int i;
	if(str[i]!=str[j])
	{
		return false;
	}
	else
	{
		if(str[i]==str[j])
		{
			if(i+1==j-1 || i==j)
			{
				return true;
			}
			else
			{
				i++;
				j--;
				check_palindrome(str,j);	
			}
		}
	}
}
int main()
{
	string str;
	cout<<"enter string: ";
	getline(cin,str);
	if(check_palindrome(str,str.size()-1))
	{
		cout<<"String is palindrome";
	}
	else
	{
		cout<<"String is not palindrome";
	}
	return 0;
}
