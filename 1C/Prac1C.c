#include<stdio.h>
#include<string.h>
struct student
{
	char name[50];
	int year;
	char sec[50];
	float avg;
};
int main()
{
struct student s[100],temp;
int i,j,n;
printf("Enter  the no. of student: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	printf("Enter the  name of student: ");
	scanf(" %[^\n]",s[i].name);
	printf("Enter the year: ");
	scanf("%d",&s[i].year);
	printf("Enter the section of student : ");
	scanf("%s",s[i].sec);
	printf("Enter average marks of student: ");
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
printf("\n Students sorted by Average Marks\n");
printf("\tName\t\tYear\tBranch\tAverage Marks\n");
for(i=n;i>=0;i--)
{
	printf("\t%-15s\t%d\t%s\t%.2f\n",s[i].name,s[i].year,s[i].sec,s[i].avg);
}

	return 0;
}
