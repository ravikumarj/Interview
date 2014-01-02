#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* Newnode(int data)
{
	struct node *ptr=new struct node;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
}
struct node* insert(struct node *root,int data)
{
	if(root==NULL)
	{
		return Newnode(data);
	}
	else
	{
		if(data<root->data)
		{
			root->left=insert(root->left,data);
		}
		else
		{
			root->right=insert(root->right,data);
		}
	return root;
	}

}
bool lookup(struct node *root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	else
	{
		if(root->data==data)
		{
			return true;
		}
		else
		{
			if(data<root->data)
			{
				return lookup(root->left,data);
			}
			else
			{
				return lookup(root->right,data);
			}
		}

	}
}

int count(struct node *root)
{
	int left=0,right=0;
	if(root != NULL)
	{
			left=count(root->left);
			right=1+count(root->right);
		return left+right;
	}
	else
	{
		return 0;
	}
}




main()
{
	struct node *tree=NULL;
	tree=insert(tree,5);
	tree=insert(tree,4);
	tree=insert(tree,3);
	tree=insert(tree,8);
	tree=insert(tree,6);
	tree=insert(tree,7);

	cout<<lookup(tree,5);
	cout<<"\n"<<lookup(tree,3);

	int c=count(tree);
	cout<<"\nnumber of nodes "<<c<<endl;
}
