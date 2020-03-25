#include<iostream>
using namespace std;

void count_ch(string str,char ch)
{
	static int i,count;
	if(str[i]=='\0')
	{
		i++;
		cout<<count;
		return;
	}
	else
	{
		if(ch==str[i])
		{
			count++;
		}
		i++;
		count_ch(str,ch);
	}
}
int main()
{
	string str="fast national university";
	char ch='a';
	int size=str.size();
	str[size-1]='\0';
	count_ch(str,ch);
	return 0;
}
