#include<iostream>
using namespace std;

float sum(int n)
{
	static int count=1;
	static float summ=1;
	if(n==0)
	{
		return summ;
	}
	else if(count==1)
	{
		count++;
		sum(--n);
	}
	else if(count%2==0)
	{
		summ= summ+(1.0/count);
		count++;
		sum(--n);
	}
	else if(count%2!=0)
	{
		summ= summ-(1.0/count);
		count++;
		sum(--n);
	}
}

int main()
{
	int n;
	cout<<"enter n value: ";
	cin>>n;
	cout<<"sum is "<<sum(n);
	return 0;
}

