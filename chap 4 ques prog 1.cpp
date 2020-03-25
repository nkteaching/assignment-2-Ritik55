#include<iostream>
using namespace std;

class stack
{
	struct node
	{
		char data;
		node *next;
	};
	public:
	node *head=NULL;
	void push(char ch)
	{
		if(head==NULL)
		{
			head= new node;
			head->data=ch;
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
			p->next=t;
			t->data=ch;
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
	char a[100];
	cout<<"enter string: ";
	gets(a);
	int i=0;
	stack s1;
	while(a[i]!='\0')
	{
		s1.push(a[i]);
		i++;
	}
	stack s2;
	i=0;
	while(a[i]!='\0')
	{
		s2.push(a[i]);
		i++;
	}
	stack s3;
	while(s2.head)
	{
		s3.push(s2.pop());
	}
	int count=1;
	while(s1.head && s3.head)
	{
		if(s1.pop() != s3.pop())
		{
			cout<<"string is not palindrome";
			count=0;
			break;
		}
	}
	if(count==1)
	{
		cout<<"string is palindrome";
	}
	return 0;
}
