#include<stdio.h>
#define SIZE 7
int main()
{
	int hash[SIZE];
	int n,key,index,i;
	for(i=0;i<SIZE;i++)
	{
		hash[i]=-1;
			
	}
	printf("enter no. of keys to insert:\n");
	scanf("%d",&n);
	printf("enter %d keys:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		index=key%SIZE;
		while(hash[index]!=-1)
		{
			index=(index+1)%SIZE;
		}
		hash[index]=key;
	}
	printf("\n final hash table:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("slot %d: %d\n",i,hash[i]);
	}
	return 0;
}
