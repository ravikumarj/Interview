#include<iostream>
#include<stdio.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
void insertAtHead(struct Node **head,int data)
{

	struct Node *newnode=new Node;
	newnode->next=*head;
	newnode->data=data;
	*head=newnode;
}
void insertAtNth(struct Node **head,int data,int index)
{
	struct Node *current=*head;
	struct Node *temp;
	if(index ==0 )
	{
		if((*head)!=NULL)
			temp=current;
		else
			temp=NULL;

		struct Node *newnode=new Node;
		newnode->data=data;
		newnode->next=temp;
		(*head)=newnode;
	}
	else
	{
		int i=0;
		while(i<index-1)
		{
			if(current==NULL)
			{
				cout<<"\nOut of Range";
			}
			else
			{
				current=current->next;
				i++;
			}
		}
		if(current!=NULL)
		{
			temp=current->next;
			struct Node *newnode=new Node;
			newnode->data=data;
			newnode->next=temp;
			current->next=newnode;	

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

struct Node * copyList(struct Node *head1)
{
	struct Node *list1=head1;

	struct Node *head=NULL;
	if(list1==NULL)
	{
		return head;
	}
	else
	{
		struct Node *newnode=new Node;
		head=newnode;
		while(list1!=NULL)
		{
			newnode->data=list1->data;
			if(list1->next!=NULL)
			{
				newnode->next=new Node;
			}
			newnode=newnode->next;
			list1=list1->next;
		}	
	}
	return head;	

}

int count(struct Node *head)
{
	int count=0;	
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		while(head!=NULL)
		{
			head=head->next;
			count=count+1;
		}
	}
	return count;

}

int GetNth(struct Node *head,int index)
{
	int i=0;
	bool flag=true;
	while(i<index)
	{
		head=head->next;
		if(head==NULL)
		{
			cout<<"\nindex out of Range";
			flag=false;
			break;
		}
		i++;
	}
	if(flag)
		return head->data;

}
void deleteList(struct Node **head)
{
	struct Node *current=*head;
	while(current!=NULL)
	{
		struct Node *temp=current->next;
		cout<<"\nDeleting .."<<current->data;
		delete(current);

		current=temp;
	}
	*head=NULL;
}


int pop(struct Node **head)
{
	int temp;
	struct Node *current=*head;
	if(current->next==NULL)
	{
		temp= current->data;
		delete current;
		*head=NULL;
	}
	else
	{
		temp=current->data;
		*head=current->next;
		delete current;
	}
	return temp;
}

void sortedInsert(struct Node **head,struct Node *newnode)
{
	struct Node *current=*head;
	struct Node *prev=current;

	if((*head)==NULL)
	{
		*head=newnode;
		newnode->next=NULL;
	}
	else if((*head)->data>newnode->data)
	{
		prev=*head;
		*head=newnode;
		newnode->next=prev;
	}

	else
	{
		while(current->data<newnode->data)
		{
			prev=current;
			current=current->next;
			if(current==NULL)
			{
				break;
			} 

		}
		struct Node *temp=prev->next;
		prev->next=newnode;
		newnode->next=temp;


	}
}
void insertSort(struct Node **head)
{
	struct Node *result=NULL;
	struct Node *current=*head;
	struct Node *temp;
	while(current!=NULL)
	{
		temp=current->next;	
		sortedInsert(&result,current);
		current=temp;
	}

	*head=result;
}

void append(struct Node **head1,struct Node **head2)
{
	if((*head1)==NULL)
	{
		*head1=*head2;
		*head2=NULL;
	}
	else
	{
		struct Node *current=*head1;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=*head2;
		*head2=NULL;
	}
}

void frontBackSplit(struct Node *head,struct Node **front,struct Node **back)
{

	struct Node *slow=head;
	struct Node *fast=head;
	if(head==NULL)
	{
		*front=NULL;
		*back=NULL;
	}
	else if(head->next==NULL)
	{
		*front=head;
		*back=NULL;
	}

	while((fast->next!=NULL) &&(fast->next->next != NULL))
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	struct Node *temp=slow->next;
	*front=head;
	slow->next=NULL;
	*back=temp;
}
void removeDuplicate(struct Node *head)
{
	struct Node *current=head;
	struct Node *temp;
	while(current->next!=NULL)
	{
		if(current->next->data ==current->data)
		{
			temp=current->next;
			current->next=current->next->next;
			delete(temp);
		}
		else
		{
			current=current->next;
		}
	}


}



void moveNode(struct Node **dest,struct Node **source)
{
	struct Node *temp_s;
	struct Node *temp_d;
	if(*source == NULL)
	{
		cout<<"\nError :Source list Empty";
	}
	/*	else if(*dest == NULL)
		{
		temp_s=(*source)->next;

	 *dest=*source;
	 (*dest)->next=NULL;
	 *source=temp_s;

	 }*/
	else
	{
		temp_s=(*source)->next;
		temp_d=(*dest);
		*dest=*source;
		*source=temp_s;
		(*dest)->next=temp_d;
	}

}
void alternateSplit(struct Node *head,struct Node **evenList,struct Node **oddList)
{
	struct Node *current;
	struct Node *current1,*current2;
	if(head == NULL)
	{
		*evenList=NULL;
		*oddList=NULL;
	}
	else
	{
		*evenList=head;
		*oddList=head->next;
		current1=*evenList;
		current2=*oddList;
		if(head->next != NULL)
		{	
			current=head->next->next;


			while(current!=NULL)
			{
				(current1)->next=current;
				(current1)=(current1)->next;
				current=current->next;
				(current2)->next=current;
				(current2)=(current2)->next;
				if(current!=NULL)
				{
					current=current->next;
				}
			}
			(current1)->next=NULL;
		}	

	}
}
struct Node *shuffleMerge(struct Node *even,struct Node *odd)
{
	struct Node dummy;
	struct Node *result=&dummy;
	dummy.next=NULL;
	struct Node *list1=even;
	struct Node *list2=odd;
	while(1)
	{
		if(list1 == NULL)
		{
			result->next=list2;
			break;
		}
		else if(list2 == NULL)
		{
			result->next=list1;
			break;
		}
		else
		{
			if(list1 != NULL && list2 != NULL)
			{
				result->next=list1;
				result=result->next;
				list1=list1->next;
				result->next=list2;
				result=result->next;
				list2=list2->next;
			}


		}
	}
	return dummy.next;
}
int length(struct Node *a)
{
	int count=0;
	if(a == NULL)
	{
		return count;
	}
	else
	{
		while(a!=NULL)
		{
			count=count+1;
			a=a->next;
		}
	}
	cout<<"\nCount-->"<<count<<endl;
	return count;

}
struct Node *sortedMerge(struct Node *a,struct Node *b,int &count)
{
	struct Node dummy;
	dummy.next=NULL;
	struct Node *result=&dummy;
	while(1)
	{
		if(a==NULL)
		{
			result->next=b;
			break;
		}
		else if(b==NULL)
		{
			result->next=a;
			//	count=count+length(a);
			//	cout<<"\nElse if--->"<<count;
			break;
		}
		else
		{
			if(a->data <b->data)
			{
				result->next=a;
				result=result->next;
				a=a->next;
			}
			else
			{
				result->next=b;
				result=result->next;
				b=b->next;
				count=count+length(a);
				//	cout<<"\nElse--->"<<count<<"\n";

			}
		}	


	}

	return dummy.next;
}



int mergeSort(struct Node **headref)
{
	int count=0,count_f=0,count_b=0;
	struct Node *head=*headref;
	struct Node *front,*back;
	if((head == NULL)||(head->next == NULL))
		return 0;

	frontBackSplit(head,&front,&back);
	count_f=mergeSort(&front);
	count_b=mergeSort(&back);

	*headref=sortedMerge(front,back,count);
	return count+count_f+count_b;
}
struct Node *sortedIntersect(struct Node *a,struct Node *b)
{
	struct Node result;
	struct Node *ptr=NULL;
	while(1)
	{
		if(a==NULL)
		{
			break;
		}
		else if(b==NULL)
		{
			break;
		}
		else
		{
			if(a->data == b->data)
			{
				insertAtTail(&ptr,a->data);
				a=a->next;
				b=b->next;
			}
			else if(a->data < b->data)
			{
				a=a->next;
			}
			else
			{
				b=b->next;
			}
		}	
	}	


return ptr;
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
void recursiveReverse(struct Node **head)
{
	struct Node *first;
	struct Node *rest;
	if(*head == NULL)
		return;
	first=*head;
	rest=first->next;
	if(rest==NULL)
		return;
	recursiveReverse(&rest);

	first->next->next=first;
	first->next=NULL;
	
	*head=rest;
}
main()
{

	struct Node *front=NULL;
	struct Node *back=NULL;
	struct Node *head=NULL;
	/*insertAtHead(&head,5);
	  insertAtHead(&head,0);
	  insertAtHead(&head,9);*/
	insertAtTail(&head,2);
	insertAtTail(&head,4);
	insertAtTail(&head,1);
	insertAtTail(&head,3);
	insertAtTail(&head,5);
	insertAtTail(&head,2);
	insertAtTail(&head,2);
	insertAtTail(&head,3);
	insertAtTail(&head,1);
	insertAtTail(&head,5);

	//insertAtNth(&head,11,3);
	struct Node *copy=copyList(head);
	printlist(copy);
	cout<<"\n";
	printlist(head);
	cout<<"\nCount === "<<count(head);
	//	cout<<"\nGetNth(3) === "<<GetNth(head,3);
	//cout<<"\nGetNth(7) === "<<GetNth(head,7);
	//	cout<<"\nGetNth(0) === "<<GetNth(head,0);
	//	deleteList(&copy);
	//	printlist(copy);
	//	cout<<"\n POP ==="<<pop(&head)<<"\n";
	//	printlist(head);
	struct Node *head2=NULL;
	struct Node *newnode=new Node;
	newnode->data=1;
	newnode->next=NULL;
	sortedInsert(&head2,newnode);
	newnode=new Node;
	newnode->data=3;
	newnode->next=NULL;
	sortedInsert(&head2,newnode);
	newnode=new Node;
	newnode->data=6;
	newnode->next=NULL;
	sortedInsert(&head2,newnode);
	newnode=new Node;
	newnode->data=7;
	newnode->next=NULL;
	sortedInsert(&head2,newnode);
	newnode=new Node;
	newnode->data=12;
	newnode->next=NULL;
	sortedInsert(&head2,newnode);


	//	cout<<"\nAfter Sorted Insert\n";
	//	printlist(head2);
	cout<<"\nHead 2\n";
	insertSort(&head2);
	printlist(head2);
	//	cout<<"\nAfter append\n";
	//	append(&head,&head2);
	//	printlist(head);

	/*	frontBackSplit(head,&front,&back);

		cout<<"\nFront List";
		printlist(front);
		cout<<"\nBack list";
		printlist(back);*/
	//	cout<<"\nFinal\n";
	//	insertSort(&head);
	//	printlist(head);
	//	removeDuplicate(head);
	/*	cout<<"\nBefore MoveNode\n";
		printlist(head);
		cout<<"\n";
		printlist(head2);

		moveNode(&head,&head2);

		cout<<"\nAfter MoveNode\n";
		printlist(head);
		cout<<"\n";
		printlist(head2);
		moveNode(&head,&head2);
		moveNode(&head,&head2);

		cout<<"\nAfter 2MoveNode\n";
		printlist(head);
		cout<<"\n";
		printlist(head2);
		moveNode(&head,&head2);

		cout<<"\nAfter MoveNode\n";
		printlist(head);
		cout<<"\n";
		printlist(head2);
		moveNode(&head2,&head);

		cout<<"\nAfter Reverse MoveNode\n";
		printlist(head);
		cout<<"\n";
		printlist(head2); */
	/*	cout<<"\nBefore split\n";
		printlist(head);

		struct Node *even=NULL;
		struct Node *odd=NULL;
		alternateSplit(head,&even,&odd);
		insertSort(&even);
		insertSort(&odd);

		cout<<"\nEven\n";
		printlist(even);
		cout<<"\nOdd\n";
		printlist(odd); */

	/*	cout<<"\nAfter shuffle Merge\n";
		struct Node *result=NULL;
		result=shuffleMerge(even,odd);
		printlist(result);*/
	/*	cout<<"\nAfter Sorted Merge\n";
		struct Node *sorted_result=NULL;
		insertSort(&even);
		insertSort(&odd);
		cout<<"\nEven\n";
		printlist(even);
		cout<<"\nOdd\n";
		printlist(odd);
		cout<<"\n";
		sorted_result=sortedMerge(even,odd);
		printlist(sorted_result);
		cout<<"\\n";
		cout<<"\nEven\n";
		printlist(even);
		cout<<"\nOdd\n";
		printlist(odd); */
	cout<<"\n";
	printlist(head);
	cout<<"\nMerge Sort\n";
	int inv=mergeSort(&head);
	printlist(head);
	cout<<"\nInversion count= "<<inv; 

	/*cout<<"\nIntersection\n";
	  struct Node *result=sortedIntersect(even,odd);
	  printlist(result);*/

	cout<<"\nAfter Reverse\n";
	recursiveReverse(&head);
	printlist(head);


}

