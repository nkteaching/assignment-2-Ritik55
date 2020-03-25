#include<iostream>
using namespace std;

int check_ch(string str,char ch)
{
	static int i;
	if(str[i]=='\0')
	{
		return 0;
	}
	else if(str[i++]==ch)
	{
		return 1;
	}
	else
	{
		check_ch(str,ch);
	}
}
int main()
{
	string str="fast";
	char ch='z';
	int var=check_ch(str,ch);
	if(var==1)
	cout<<ch<<" found";
	else
	cout<<ch<<" not found";
	return 0;
}
