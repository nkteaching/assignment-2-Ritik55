#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class queue
{
	public:
	node *head=NULL;
	void enqueue(int x)
	{
		if(head==NULL)
		{
			head=new node;
			head->data= x;
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
			t->data= x;
			t->next= NULL;
		}
	}
	int dequeue()
	{
		node *p=head,*q;
		if(p)
		{
			q=p->next;
			head= q;
			p->next=NULL;
			return p->data;
		}
		else
		{
			return -1;
		}
	}
	void empty_queue()
	{
		node *p=head,*q;
		while(p)
		{
			q=p;
			p=p->next;
			delete q;
		}
		head=NULL;
	}
};

class stack
{
	queue q;
	public:
	void push(int x)
	{
		q.enqueue(x);
	}
	int pop()
	{
		node *a= q.head, *b=a;
		if(a)
		{
			queue q1;
			while(b->next!=NULL)
			{
				q1.enqueue(a->data);
				a=a->next;
				b=a;
			}
			q.empty_queue();
			while(q1.head)
			{
				q.enqueue(q1.dequeue());
			}
		}
	}
	void disp()
	{
		node *p=q.head;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};


int main()
{
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.disp();
	return 0;
	return 0;
}
