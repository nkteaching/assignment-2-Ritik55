#include<iostream>
#include<fstream>
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
};
int DelimiterMatching()
{
	ifstream fin("file.txt");
	int i=0;
	stack s;
	char ch;
	fin>>ch;
	while(fin)
	{
		if(ch=='['||ch=='{'||ch=='(')
		s.push(ch);
		
		else if(ch==']')
		{
			if(s.pop()!='[')
			{
				fin.close();
				return 0;
			}
		}
		
		else if(ch=='}')
		{
			if(s.pop()!='{')
			{
				fin.close();
				return 0;
			}
		}
		
		else if(ch==')')
		{
			if(s.pop()!='(')
			{
				fin.close();
				return 0;
			}
		}
		
		else if(ch=='/')
		{
			int flag=0;
			fin>>ch;
			if(ch=='*')
			{
				while(fin)
				{
					fin>>ch;
					if(ch=='*')
					{
						fin>>ch;
						if(ch=='/')
						{
							flag=1;
							break;
						}
					}
				}
				if(flag==0)
				{
					fin.close();
					return -1;
				}
			}
			else continue;
		}
		fin>>ch;
	}
	if(s.head)
	{
		fin.close();
		return 0;
	}
	else
	{
		fin.close();
		return 1;
	}
}
int main()
{
	if(DelimiterMatching()==1)
	{
		cout<<"balanced";
	}
	else if(DelimiterMatching()==0)
	{
		cout<<"not balanced";
	}
	else if(DelimiterMatching()==-1)
	{
		cout<<"string is encountered";
	}
	return 0;
}
