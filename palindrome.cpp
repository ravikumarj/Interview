#include<iostream>
#include<stdio.h>
#include"hash.h"
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};

int CompareLists(struct Node *headA, struct Node* headB)
{
	while(1)
	{
		if((headA== NULL)&&(headB!=NULL))
			return 0;
		else if ((headA!= NULL)&&(headB==NULL))
			return 0;
		else if((headA!=NULL) &&(headB!=NULL))
		{        
			if(headA->data==headB->data)
			{
				headA=headA->next;
				headB=headB->next;
			}
			else
			{
				return 0;
			}


		}
		else
		{
		
			return 1;
		}
		

	}
}  
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


/*int isPalindrome(struct Node *head)
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


  }*/
int palindrome(struct Node *head)
{
	struct Node *second_half=head;
	struct Node *temp,*slow,*fast,*midnode=NULL,*prev;

	slow=head;
	fast=head;

	while((fast!=NULL) && (fast->next!=NULL))
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	if(fast != NULL) // odd number of elements
	{
		cout<<"\nOdd;";
		temp=prev->next;
		prev->next=NULL;
		midnode=temp;
		second_half=temp->next;
	}
	else if(fast == NULL)
	{
		temp=prev->next;
		prev->next=NULL;
		second_half=temp;
	}


	cout<<"\nFirst Half\n";
	printlist(head);
	cout<<"\nSecond Half\n";

	reverse(&second_half);
	int res=CompareLists(head,second_half);

	reverse(&second_half);
printlist(second_half);
	if(midnode!=NULL)
	{
		prev->next=midnode;
		midnode->next=second_half;
	}
	else
	{
		prev->next=second_half;
	}


	return res;
}
bool isPal_rec(struct Node **left,struct Node *right)
{

	if(right==NULL)
	{
		return true;
	}
	bool ret=isPal_rec(left,right->next);
	if(((*left)->data== right->data)&&(ret==true))
	{
		(*left)=(*left)->next;
		return true;
	}
	
	return false;
	

}



main()
{
	struct Node *head=NULL;
	insertAtTail(&head,2);
	insertAtTail(&head,0);
	insertAtTail(&head,3);
	insertAtTail(&head,1);
	insertAtTail(&head,2);
	cout<<"\nHead\n";
	printlist(head);
	cout<<"\n";
	struct Node *right=head;
	int res=isPal_rec(&right,head);
	cout<<"\nPalindrome == "<<res;
	cout<<"\nlist after test\n";
	printlist(head);
}
