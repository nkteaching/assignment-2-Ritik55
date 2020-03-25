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
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout<<"before"<<endl;
	s1.display();
	stack s2;
	while(s1.head)
	{
		s2.push(s1.pop());
	}
	int i=0, *p;
	p= new int [100];
	while(s2.head)
	{
		p[i]=s2.pop();
		i++;
	}
	for(int j=i-1;j>=0;j--)
	{
		s1.push(p[j]);
	}
	delete []p;
	cout<<endl<<"after"<<endl;
	s1.display();
	return 0;
}
