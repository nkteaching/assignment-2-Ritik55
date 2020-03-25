#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

char* put_commas(int val)
{
	static char num[100]; 
	static int i,j,count;
	if(val!=0)
	{
		count++;
		
		j=i;
		i++;
		if(count==4)
		{
			num[j]=',';
			j=i;
			i++;
			count=1;
		}
		int ascii=48+(val%10);
		char ch=ascii;
		num[j]=ch;
		put_commas(val/10);
	}
	else
	{
		num[i]='\0';
		char temp;
		i=0;
		int size;
		for(size=0;num[size]!='\0';size++);
		for(i=0;i<size/2;i++)
		{
			temp= num[i];
			num[i]=num[j];
			num[j]=temp;
			j--;
		}
		return num;
	}
}

int main()
{
	int val;
	cout<<"enter number: ";
	cin>>val;
	cout<<put_commas(val);
	return 0;
}

