#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*sourcefile,*destfile;
	char sourcename[100],destname[100];
	char ch;
	printf("enter source file name: ");
	scanf("%s",sourcename);
	printf("\nenter destination file name: ");
	scanf("%s",destname);
	sourcefile=fopen(sourcename,"r");
	if(sourcefile==NULL)
	{
		printf("\nerror,can't open");
		exit(1);
	}
	destfile=fopen(destname,"w");
	if(destfile==NULL)
	{
		printf("\nerror can't create");
		fclose(sourcefile);
		exit(1);
	}
	while((ch=fgetc(sourcefile))!=EOF)
	{
		fputc(ch,destfile);
	}
	printf("\nfile copied successfully");
	fclose(sourcefile);
	fclose(destfile);
	return 0;
}