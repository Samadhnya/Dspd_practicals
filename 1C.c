#include<stdio.h>
#include<string.h>
struct student
{
	char name[50];
	int year;
	char branch[100];
	float avg;
};
int main()
{
struct student s[100],temp;
int i,j,n;
printf("enter no. of student: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	printf("\n enter student details %d:\n",i+1);
	printf("enter name: ");
	scanf(" %[^\n]",s[i].name);
	printf("enter year: ");
	scanf("%d",&s[i].year);
	printf("enter branch: ");
	scanf("%s",s[i].branch);
	printf("enter Average Marks: ");
	scanf("%f",&s[i].avg);
}
for(i=0;i<n-1;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(s[i].avg<s[i].avg)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
			
		}
	}
}
printf("\n Students sorted by Average Marks(Descending):\n");
printf("\tName\t\tYear\tBranch\tAverage Marks\n");
for(i=0;i<n;i++)
{
	printf("\t%-15s\t%d\t%s\t%.2f\n",s[i].name,s[i].year,s[i].branch,s[i].avg);
}

	return 0;
}

