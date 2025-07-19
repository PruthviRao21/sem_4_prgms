#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int cnt;
int string_matching(char *text,char* pattern,int m,int n)
{
	
	for(int i=0;i<=m-n;i++)
	{
		int j=0;
		while(j<n)
		{
			cnt++;
			if(pattern[j]!=text[i+j])
				break;
			j++;
		}
		if(j==n)
		{
			// printf("The pattern found\n");  only for tester
			return cnt;
		}
	}
	//printf("\nThe pattern not found\n"); only for tester
	return cnt;

}
void tester()
{
	int m,n;
	char pattern[100],text[100];
	printf("\nEnter the pattern length\n");
	scanf("%d",&m);
	printf("\nEnter the pattern\n");
	getchar();
	fgets(pattern,sizeof(pattern),stdin);
	pattern[strcspn(pattern,"\n")]='\0';
	printf("\nEnter the text length\n");
        scanf("%d",&n);
	printf("\nEnter the text\n");
        getchar();
        fgets(text,sizeof(text),stdin);
        pattern[strcspn(text,"\n")]='\0';
	int comp=string_matching(text,pattern,n,m);


}
void plotter()
{
	
	FILE *f1 =fopen("stringbest.txt", "w");
	FILE *f2 =fopen("stringworst.txt", "w");
	FILE *f3 =fopen("stringavg.txt", "w");
	char *text=(char *)malloc(1000*sizeof(char));
	char * pattern;
	for(int i=0;i<1000;i++)
 		*(text+i) = 'a';
	int m,n;
	n=1000;
 	m=10;
	while(m<1000)
	{
 		pattern = (char *)malloc(m*sizeof(char));
 
 		for(int i=0; i<m; i++)
 		pattern[i] = 'a';
		cnt=0;
		string_matching(text, pattern, n,m);
		fprintf(f1, "%d\t%d\n", m, cnt); 
 		cnt = 0;
 		pattern[m-1] = 'b';
		string_matching(text, pattern, n,m);
		fprintf(f2, "%d\t%d\n", m, cnt);
		for(int i=0; i<m; i++)
		pattern[i] =97+ rand()%3;
		cnt=0;
		string_matching(text, pattern, n,m);
		fprintf(f3,"%d\t%d\n", m, cnt); 
		cnt=0;
		free(pattern);
		if(m<100)
		m=m+10;
		else
		m=m+100;
	}
}
void main()
{
	for(;;)
	{
		int ch;
		printf("\nEnter 1 for Tester and 2 for plotter\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:tester();
			case 2:plotter();
			default : exit(1);
		}
	}
}

