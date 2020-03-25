#include<iostream>
using namespace std;

class stack
{
	struct node
	{
		int data;
		node *next;
	};
	public:
	node *head=NULL;
	push(int x)
	{
		if(head==NULL)
		{
			head= new node;
			head->data=x;
			head->next= NULL;
		}
		else
		{
			node *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			node *t=new node;
			p->next= t;
			t->data=x;
			t->next=NULL;
		}
	}
	int pop()
	{
		node *q,*p=head;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		if(p==head)
		{
			head=NULL;
			return p->data;
		}
		else
		{
			q->next=NULL;
			return p->data;
		}
	}
	display()
	{
		node *p=head;
		cout<<"sum is ";
		while(p)
		{
			cout<<p->data;
			p=p->next;
		}
		cout<<endl;
	}
};
void reverse(stack &s)
{
	int a[100],i=0;
	while(s.head)
	{
		a[i]=s.pop();
		i++;
	}
	for(int j=0;j<i;j++)
	{
		s.push(a[j]);
	}
}
int main()
{
	int n1,n2;
	cout<<"enter two integers: ";
	cin>>n1>>n2;
	stack s1;
	while(n1!=0)
	{
		s1.push(n1%10);
		n1=n1/10;
	}
	reverse(s1);
	stack s2;
	while(n2!=0)
	{
		s2.push(n2%10);
		n2=n2/10;
	}
	reverse(s2);
	stack s3;
	int a,b,c,carry=0;
	while(1)
	{
		if(s1.head)
		a=s1.pop();
		else a=0;
		
		if(s2.head)
		b=s2.pop();
		else b=0;
		
		c=a+b+carry;
		if(c>9)
		{
			s3.push(c%10);
			carry=c/10;	
		}
		
		else
		{
			carry=0;
			s3.push(c);
			c=0;
		}
		
		if(!s1.head && !s2.head && c==0 && carry==0)
		break;
	}
	reverse(s3);
	s3.display();
	return 0;
}
