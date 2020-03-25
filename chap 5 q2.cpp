#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first=NULL;

struct node* create_linked_list(int a[],int size)
{
	struct node *tail, *t;
	int i;
	first= new node;
	first->data= a[0];
	first->next= NULL;
	tail= first;
	for(i=1;i<size;i++)
	{
		t= new node;
		t->data= a[i];
		t->next= NULL;
		tail->next= t;
		tail= t;
	}
	cout<<"Linked List created successfully.."<<endl;
}
void display(struct node *p)
{
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}

int calc_length(struct node *p)
{
	if(p==NULL)
	return 0;
	else
	{
		p=p->next;
		return 1+calc_length(p);
	}
}

int main()
{
	int size1,size2;
	cout<<"how many elements you want to store in Linked list: ";
	cin>>size1;
	int a[size1];
	cout<<"enter "<<size1<<" elements: ";
	for(int i=0;i<size1;i++)
	{
		cin>>a[i];
	}
	create_linked_list(a,size1);
	cout<<"Length of Linked List= "<<calc_length(first)<<endl;
	return 0;
}
