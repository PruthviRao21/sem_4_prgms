#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char fn[20],pattern[10],temp[100];
	printf("Enter the file name : ");
	scanf("%s",fn);
	FILE* fp;
	fp=fopen(fn,"r");
	printf("\nEnter the pattern : ");
	scanf("%s",pattern);
	while(!feof(fp))
	{
		fgets(temp,100,fp);
		if(strstr(temp,pattern))
		{
			printf("%s",temp);
			printf("\n");
		}
	}
	return 0;
}
