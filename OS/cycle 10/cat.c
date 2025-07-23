#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	char ch;
	if(argc < 2)
	{
		printf("File not entered\n");
		exit(0);
	}	
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("File is empty\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);
	printf("\n");
	return 0; 
}
