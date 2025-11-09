#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left,*right;
};
struct node*create(int val)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->left=newnode->right=NULL;
	return newnode;
}
struct node*insert(struct node*root,int val)
{
	if(root==NULL)
	{
		return create(val);
	}
	if(val<root->data)
	{
		root->left=insert(root->left,val);
	}
	else
	{
		root->right=insert(root->right,val);
	}
	return root;
}
void search(struct node*root,int key)
{
	if(root==NULL)
	{
		printf("NULL\n");
		return;
	}
	if(key==root->data)
	{
		printf("found\n");
	}
	else if(key<root->data)
	{
		search(root->left,key);
	}
	else
	{
		search(root->right,key);
	}
}
struct node*delleaf(struct node*root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(key<root->data)
	{
		root->left=delleaf(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=delleaf(root->right,key);
	}
	else{
		if(root->left==NULL&&root->right==NULL)
		{
			printf("%d deleted\n",root->data);
			free(root);
			return NULL;
		}
		else
		{
			printf("%d is not a leaf\n",root->data);
		}
	}
	return root;
}
void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int main()
{
	struct node*root=NULL;
	int ch,val;
	while(1)
	{
		printf("1.For search an element \n");
		printf("2.For insert an element\n");
		printf("3.Delete a leaf element\n");
		printf("4. For exit:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter element to search:\n");
				scanf("%d",&val);
				search(root,val);
				break;
				
				case 2:
					printf("Enter element to insert:\n");
					scanf("%d",&val);
					root=insert(root,val);
					printf("Inorder traversal:\n");
					inorder(root);
					printf("\n");
					break;
					
					case 3:
						printf("enter leaf element to delete:\n");
						scanf("%d",&val);
					root=delleaf(root,val);
					printf("inorder traversal:\n");
					inorder(root);
					printf("\n");
					break;
					
					case 4:
						exit(0);
						
						default:
							printf("invalid input\n");
		}
	}
	return 0;
}