#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *left;
	struct node *right;
};


struct node *newnode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->a = data;
	temp->left= temp->right = NULL;
	return temp;
}

int height(struct node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int ldepth = height(root->left);
		int rdepth = height(root->right);
		if(ldepth<rdepth)
			return rdepth+1;
		else
			return ldepth+1;
	}
}
void level_traverse(struct node *root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d", root->a);
	else
	{
		level_traverse(root->left,level-1);
		level_traverse(root->right,level-1);
	}
}

void print_level(struct node *root)
{
	int i;
	int h = height(root);
	for(i=0;i<=h;i++)
	{
		level_traverse(root,i);
	}
}

int leaf_count(struct node *root)
{
	static count = 0;
	if(root == NULL)
	return 0;
	else
	{
		if(root->left == NULL && root->right == NULL)
			count++;
		leaf_count(root->left);
		leaf_count(root->right);
	}
	return count;
}

int main()
{
	struct node *root = newnode(1);
	root->left= newnode(2);
	root->right = newnode(3);
	root->left->left =newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(4);
	root->right->right = newnode(6);
	root->right->right->left = newnode(7);
	root->right->right->right = newnode(8);
	print_level(root);
	int counter = leaf_count(root);
	printf("no of leaf nodes : %d",counter);
	return 0;

}

