#include<iostream>
using namespace std;
struct dNode 
{
	int data;
	struct dNode *prev;
	struct dNode *next;
};


void push(struct dNode **head,int data)
{
struct dNode *newnode=new dNode;
struct dNode *temp;
        newnode->prev=NULL;
        newnode->next=NULL;
        newnode->data=data;

	if(*head == NULL)
		{
		*head=newnode;
		}
	else
		{
		temp=(*head);
		*head=newnode;
		newnode->next=temp;
		temp->prev=newnode;
		}
		
	
}




void insertAfter(struct dNode **cur,int data)
{
	struct dNode *newnode=new dNode;
	struct dNode *temp;

	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->data=data;


	if((*cur)==NULL)
	{
		(*cur)=newnode;
	}
	else
	{
		if((*cur)->next!=NULL)
			{
                        (*cur)->next->prev=newnode;
			newnode->next=(*cur)->next;
			}
		(*cur)->next=newnode;
		newnode->prev=(*cur);
	}

}


void insert(struct dNode **head,int index,int data)
{

struct dNode *temp=*head;
if(index == 0)
	{
	push(&temp,data);
	}
else
	{
	struct dNode *newnode=new dNode;
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	for(int i=0;i<index;i++)
		{
		temp=temp->next;
		}
	if(temp->next != NULL)
		{
		temp->next->prev=newnode;
		newnode->next=temp->next;
		}
	temp->next=newnode;
	newnode->prev=temp;
		
	

	}

}
void insertAtTail(struct dNode **head,int data)
{
struct dNode *newnode=new dNode;
newnode->data=data;
newnode->next=NULL;
newnode->prev=NULL;
struct dNode *temp=*head;
if((*head)==NULL)
	{
	(*head)=newnode;
	}
else
	{
	while(temp->next != NULL)
		{
		temp=temp->next;
		}
	temp->next=newnode;
	newnode->prev=temp;
	

	}
	

}

void reverse(struct dNode **head)
{
struct dNode *cur=*head;
struct dNode *temp;

while(cur != NULL)
	{
	temp=cur->prev;
	cur->prev=cur->next;
	cur->next=temp;
	cur=cur->prev;
	}
*head=temp->prev;


}

void printlist(struct dNode *head)
{
struct dNode *mark=head;
	cout<<"\n";
	while(head->next!=NULL)
		{
		cout<<head->data<<"\t";
		head=head->next;
	
		}
	cout<<head->data;
	cout<<"\n";
	int i=0;
/*	while(head!=NULL)
		{
		cout<<head->data<<"\t";
		head=head->prev;
		i++;
		}*/
}
main()
{
struct dNode *head=NULL;

push(&head,5);
push(&head,4);
push(&head,3);
insertAfter(&head,16);
insertAfter(&head,17);
insertAfter(&head,18);

insertAtTail(&head,6);
insertAtTail(&head,7);
insertAtTail(&head,8);
insertAtTail(&head,9);

insert(&head,3,99);

printlist(head);

reverse(&head);
printlist(head);
}
