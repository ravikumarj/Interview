#include<iostream>
#include<stdio.h>
#include"hash.h"
using namespace std;
struct Node
{
        int data;
        struct Node *next;
};

void insertAtTail(struct Node **head,int data)
{
        struct Node *current=*head;
        struct Node *newnode=new Node;
        if(current==NULL)
        {
                *head=newnode;
                newnode->data=data;
                newnode->next=NULL;
        }
        else
        {

                while(current->next!=NULL)
                {
                        current=current->next;
                }

                current->next=newnode;
                newnode->data=data;
                newnode->next=NULL;
        }
}

void printlist(struct Node *head)
{
        while(head!=NULL)
        {
                cout<<head->data<<"\t";
                head=head->next;
        }
}
struct Node *copyList(struct Node *head)
{
struct Node *copyhead=NULL;
if(head == NULL)
	{
	return NULL;
	}
else
	{
	struct Node *copy=new Node;
	copyhead=copy;
	copy->data=head->data;
	copy->next=NULL;
	head=head->next;
	while(head!=NULL)
		{
		copy->next=new Node;
		copy=copy->next;
		copy->data=head->data;
		head=head->next;
		}
		

	}
return copyhead;
}
void reverse(struct Node **head)
{
struct Node *result=NULL;
struct Node *current=*head;
struct Node *temp;
while(current != NULL)
        {
        temp=current->next;
        current->next=result;
        result=current;
        current=temp;
        }

*head=result;
}


int isPalindrome(struct Node *head)
{
struct Node *rev=copyList(head);

        reverse(&rev);
        struct Node *slow=head;
        struct Node *fast=head;
        while(fast != NULL && fast->next !=NULL)
        {
                if(head->data != rev->data)
                {
                        return 0;
                }
                else
                {
                        head=head->next;
                        rev=rev->next;
                        fast=fast->next->next; //only half list comparision is enough
                }
        }
return 1;


}
main()
{
	struct Node *head=NULL;
	insertAtTail(&head,2);
	insertAtTail(&head,2);
	/*insertAtTail(&head,3);
	insertAtTail(&head,3);
	insertAtTail(&head,0);
	insertAtTail(&head,2); */
	cout<<"\nHead\n";
	printlist(head);
	cout<<"\n";
	cout<<isPalindrome(head);
}
