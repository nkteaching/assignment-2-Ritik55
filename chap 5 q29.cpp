#include<iostream>
using namespace std;

void print(int n)
{
	if(n!=0)
	{
		print(--n);
		cout<<n<<" ";
	}
}
int main()
{
	print(10);
	return 0;
}

