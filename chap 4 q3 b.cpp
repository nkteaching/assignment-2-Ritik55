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
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
	}
};
int main()
{
	stack s1;
	s1.push(5);
	s1.push(7);
	s1.push(3);
	s1.push(1);
	cout<<"stack 1"<<endl;
	s1.display();
	int i=0, *a;
	a= new int [100];
	while(s1.head)
	{
		a[i]=s1.pop();
		i++;
	}
	int size=i,j,temp;
	i--;
	for(j=0;j<size/2;j++)
	{
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		i--;
	}
	i=0;
	stack s2;
	while(i!=size)
	{
		s2.push(a[i]);
		i++;
	}
	cout<<endl<<"stack 2"<<endl;
	s2.display();
	return 0;
}
