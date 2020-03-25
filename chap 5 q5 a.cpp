#include<iostream>
using namespace std;

void print_odd(int val,int n)
{
	if(val%2!=0 && val>1 && val<n)
	{
		cout<<val<<"\t";
	}
	else if(val>n)
	return;
	val++;
	print_odd(val,n);
}
int main()
{
	int n;
	cout<<"enter n value: ";
	cin>>n;
	print_odd(1,n);
	return 0;
}

