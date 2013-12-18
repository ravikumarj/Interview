#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct list
{
        int val;
        struct list *next;
};

struct Table
{
        int tableSize;
        struct list **table;
};

typedef struct Table Hashtable;
Hashtable *init(int tablesize);
int Hash(Hashtable *hash,int val);
bool lookup(Hashtable *hash,int val);
bool add(Hashtable *hash,int val);

