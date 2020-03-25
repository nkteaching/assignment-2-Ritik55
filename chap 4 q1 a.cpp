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

int main()
{
	stack stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.display();
	stack stack2;
	while(stack1.head)
	{
		stack2.push(stack1.pop());
	}
	stack stack3;
	while(stack2.head)
	{
		stack3.push(stack2.pop());
	}
	while(stack3.head)
	{
		stack1.push(stack3.pop());
	}
	cout<<endl<<endl;
	stack1.display();
}
