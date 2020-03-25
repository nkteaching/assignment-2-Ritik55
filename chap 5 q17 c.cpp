#include<iostream>
using namespace std;

void remove_ch(char *a,char ch,int size)
{
	static int i;
	if(a[i]=='\0')
	{
		cout<<a;
	}
	else if(a[i]!=ch)
	{
		i++;
		remove_ch(a,ch,size);
	}
	else
	{
		int temp_i,j;
		if(a[i]==ch)
		{
			temp_i=i;
			for(j=i+1;j<size;j++)
			{
				a[temp_i]=a[j];
				temp_i++;
			}
			size--;
			a[size]='\0';
		}
		i++;
		remove_ch(a,ch,size);
	}
}
int main()
{
	char str[100]="ritik dodai";
	char ch='i';
	int size;
	for(size=0;str[size]!='\0';size++);
	remove_ch(str,ch,size);
	return 0;
}
