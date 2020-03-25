#include<iostream>
using namespace std;

class stack
{
	public:
	struct node
	{
		int data;
		node *next;
	}*head=NULL;
	void push(int x)
	{
		if(head==NULL)
		{
			head= new node;
			head->data=x;
			head->next=NULL;
		}
		else
		{
			node *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			node *t=new node;
			p->next=t;
			t->data=x;
			t->next=NULL;
		}
	}
	int pop()
	{
		node *p,*q=head;
		while(q->next!=NULL)
		{
			p=q;
			q=q->next;
		}
		if(q==head)
		{
			head=NULL;
			return q->data;
		}
		else
		{
			p->next=NULL;
			return q->data;
		}
	}
	void display()
	{
		node *p=head;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}

	}
};

class queue
{
	public:
	struct node
	{
		int data;
		node *next;
	}*head=NULL;
	void push(int x)
	{
		if(head==NULL)
		{
			head= new node;
			head->data=x;
			head->next=NULL;
		}
		else
		{
			node *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			node *t=new node;
			p->next=t;
			t->data=x;
			t->next=NULL;
		}
	}
	int pop()
	{
		node *p=head,*q;
		if(p)
		{
			q=p->next;
			head=q;
			return p->data;
		}
 
	}
};

int main()
{
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<"before"<<endl;
	s.display();
	queue q;
	while(s.head)
	{
		q.push(s.pop());
	}
	while(q.head)
	{
		s.push(q.pop());
	}
	cout<<endl<<"after"<<endl;
	s.display();
	return 0;
}
