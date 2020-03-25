#include<iostream>
using namespace std;

void cubes(int n)
{
	if(n!=1)
	{
		cubes(--n);
		cout<<n*n*n<<" ";
	}
	return;
}
int main()
{
	int n;
	cout<<"enter n value: ";
	cin>>n;
	cubes(++n);
	return 0;
}
