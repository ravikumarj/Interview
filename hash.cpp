#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
using namespace std;
/*struct list
{
	int val;
	struct list *next;
};

struct Table
{
	int tableSize;
	struct list **table;
};

typedef struct Table Hashtable;*/
Hashtable *init(int tablesize)
{
	Hashtable *ptr;
	int i=0;
	ptr=new Hashtable;
	ptr->table=(struct list **)malloc(sizeof(list *)*tablesize);
	for(i=0;i<tablesize;i++)
	{
		ptr->table[i]=NULL;
	}
	ptr->tableSize=tablesize;
	return ptr;
}

int Hash(Hashtable *hash,int val)
{
	int index=0;
	index=val%hash->tableSize;
	return index;
}
bool lookup(Hashtable *hash,int val)
{
        int index=Hash(hash,val);
        if(hash->table[index] == NULL)
        {
                //      cout<<"\nitem not in Hash table";
                return false;
        }
        else
        {
                struct list *cur=hash->table[index];
                while(cur != NULL)
                {
                        if(cur->val == val)
                        {
                                return true;
                                break;
                        }
                        else
                        {
                                cur=cur->next;
                        }
                }
                return false;

        }

}
//Returns true if element was added in Hash
bool add(Hashtable *hash,int val)
{
	struct list *ptr;
	struct list *newnode=new list;
	newnode->val=val;
	newnode->next=NULL;
	int index=Hash(hash,val);
	if(hash->table[index]==NULL)
	{
		hash->table[index]=newnode;
	}
	else
	{
		if(lookup(hash,val)==false)
		{	
			ptr=hash->table[index]; //collision!!
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			ptr=ptr->next;
		}
		else
		{
		//cout<<"\nItem already present duplicate";
		return false;
		}
	}
return true;
}
/*main()
{
	Hashtable *hash_ptr;
	int tablesize=10;
	hash_ptr=init(10);
	cout<<"\nHash() --> "<<Hash(hash_ptr,20)<<"\n"<<Hash(hash_ptr,25);
	add(hash_ptr,20);
	add(hash_ptr,25);
	add(hash_ptr,25);
	cout<<"\n"<<lookup(hash_ptr,20);
	cout<<"\n"<<lookup(hash_ptr,21);	
	cout<<"\n"<<lookup(hash_ptr,25);

}*/
