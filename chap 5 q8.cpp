#include<iostream>
using namespace std;

int mul(int a,int b)
{
	if(b==0)
	{
		return b;
	}
	else
	{
		return a+mul(a,--b);
	}
}
int main()
{
	int a,b;
	cout<<"enter two integers: ";
	cin>>a>>b;
	cout<<endl<<a<<"*"<<b<<" = "<<mul(a,b)<<endl;
	return 0;
}
