#include<iostream>
using namespace std;

struct A
{
	int a;
};
class stack
{
	struct node
	{
		int d;
		float data;
		node *next;
	};
	public:
	node *head=NULL;
	push(float x)
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
	push(struct A x)
	{
		if(head==NULL)
		{
			head= new node;
			head->d=x.a;
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
			t->d=x.a;
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
	struct A x;
	s1.push(1.2);
	s1.push(x.a=5);
	s1.push(1.5);
	s1.push(x.a=10);
	s1.display();
	return 0;
}
