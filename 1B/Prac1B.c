#include<stdio.h>
#include<stdlib.h>

int*search(int arr[],int size,int target);

int main()
{
	int s,v;
	printf("enter size of array: ");
	scanf("%d",&s);
	if (s <= 0) {
       printf(" Invalid or empty array. Nothing to search.\n");
       return 0;
   }
	int arr[s];
	printf("enter elements of array: ");
	int i;
	for(i=0;i<s;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter search value: ");
	scanf("%d",&v);
	int*result=search(arr,s,v);
	
	if(result!=NULL)
	{
		printf("%d is found in array",v);
		
	}
	else
	{
		printf("%d is not found in array",v);
	}
	return 0;
}

int*search(int arr[],int size,int target)
{
	if(arr==NULL || size==0)
	{
		return NULL;
	}
	
	int beg=0;
	int end=size-1;
	
	while(beg<=end)
	{
		 int mid = (beg + end) / 2; 
		printf("\n searching between indexes[%d-%d]\n",beg,end);
		int i;
		for(i=beg;i<=end;i++)
		{
		if(i==mid)
			{
				printf("[%d] ",arr[i]);
			}
			else
			{
				printf("%d  ",arr[i]);
			}
		}
		if(arr[mid]==target)
		{
			printf("\n midpoint value %d is matched with target %d\n",arr[mid],target);
			return &arr[mid];
		}
		else if(arr[mid]<target)
		{
			
			printf("\n target value %d is greater than midpoint value %d.Searching right side\n",target,arr[mid]);
			beg=mid+1;
		}
		else
		{
			printf("\n target value %d is lesser than midpoint value %d.Searching left side\n",target,arr[mid]);
			end=mid-1;
		}
	}
	return NULL;
	}
