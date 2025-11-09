#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
int main()
{
	struct node*head=NULL,*temp,*newnode;
	int c=1,count=0;
	while(c)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter element to add to the linked list (Enter 0 to stop):\n");
		scanf("%d",&newnode->data);
        printf("Inserted to the list\n");
		if(newnode->data==0)
		{
			break;
		}
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		count++;
	}
	temp=head;
	printf("Linked list:\n");
	while(temp!=NULL)
	{
		printf("%d=>",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("total number of nodes:%d",count);
	return 0;
}
