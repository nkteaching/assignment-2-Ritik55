#include<iostream>
using namespace std;

void print_odd(int n)
{
	if(n==1)
	return;
	else
	{
		if(n%2!=0)
		cout<<n<<"\t";
		n--;
		print_odd(n);
	}
	
}
int main()
{
	int n;
	cout<<"enter n value: ";
	cin>>n;
	print_odd(n-1);
	return 0;
}

