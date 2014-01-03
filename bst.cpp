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
			right=count(root->right)+1;
		return left+right;
	}
	else
	{
		return 0;
	}
}

int maxDepth(struct node *root)
{
	int left=0,right=0;
	if(root==NULL)
		return 0;
	else
	{
		left=maxDepth(root->left);
		right=maxDepth(root->right);
		if(left>right)
			{
			return left+1;
			}
		else
			{
			return right+1;
			}
	}

}

int minValue(struct node *root)
{
	if(root->left == NULL)
		return root->data;
	else
	{
		int min=minValue(root->left);
		return min;
	}


}

void print(struct node *root)
{
if(root == NULL)
	return;
print(root->left);
cout<<"\n"<<root->data;
print(root->right);
}

bool hasPath(struct node *root,int sum)
{
	i//Empty tree
	if(root == NULL)
	{
		return(sum == 0);
	}
	else
	{
	bool left=false;
	bool right=false;	
	int sub=sum-root->data;
	if(sub == 0 && root->left == NULL && root->right == NULL)
		return true;
	if(root->left)
	 left=hasPath(root->left,sub);
	if(root->right)
	 right=hasPath(root->right,sub);

	return (left||right);

	}
}
main()
{
	struct node *tree=NULL;
	tree=insert(tree,5);
	tree=insert(tree,4);
	tree=insert(tree,3);

/*	tree=insert(tree,8);
	tree=insert(tree,6);
	tree=insert(tree,2);
	tree=insert(tree,1);*/

	cout<<lookup(tree,5);
	cout<<"\n"<<lookup(tree,3);

	int c=count(tree);
	cout<<"\nnumber of nodes "<<c<<endl;
	int height=maxDepth(tree);
	cout<<"\nDepth -->"<<height;
	int min=minValue(tree);
	cout<<"\nMin -->"<<min;

	cout<<"\nPrint tree \n";
	print(tree);
	cout<<"\nHas Sum\n";
	cout<<hasPath(tree,12)<<endl;;
	cout<<hasPath(tree,9);
}
