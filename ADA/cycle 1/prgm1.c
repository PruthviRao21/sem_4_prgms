#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
int cnt;
int euclid(int m,int n)
{
	while(n)
	{
		cnt++;
		int r=m%n;
		m=n;
		n=r;
	}
	return m;
}
int consec(int m,int n)
{
	int min=m;
	if(m>n)
		min=n;
	while(1)
	{
		cnt++;
		if(m%min==0)
		{
			cnt++;
			if(n%min==0)
				break;
		}
		min--;
	}
	return min;
}
int modified(int m,int n)
{
	while(n)
	{
		if(m>n)
		m-=n;
		else
		n-=m;
		cnt++;
	}
	return m;
}
void tester()
{
	int ch;
	int m,n;
	printf("Enter the values\n");
	scanf("%d%d",&m,&n);
	if(m==0 || n==0)
	{
		printf("Invalid input\n");
		exit(0);
	}
	for(;;)
	{
	printf("\nEnter choice:\n1.Euclid\n2.Consecutive int\n3.Modified\nOther To exit\n");
	scanf("%d",&ch);
	int val;
	switch(ch)
	{
		case 1: val=euclid(m,n);
		       printf("GCD is %d\n",val);
		       break;
		case 2: val=consec(m,n);
                       printf("GCD is %d\n",val);
                       break;
		case 3: val=modified(m,n);
                       printf("GCD is %d\n",val);
                       break;
		default:exit(1);

	}
	}
}
void plotter(int ch)
{
	int m,n,i,j,k;
	int maxcount,mincount;
	FILE *fp1,*fp2;
	for(i=x;i<=y;i+=10)
	{
		maxcount=0; mincount=10000;
		for (j=2;j<=i; j++ ) 
		{
			for(k=2;k<=i; k++)
			{
				cnt=0;
				m=j;
				n=k;
				switch(ch)
				{
				case 1:euclid(m,n);
					break;
				case 2:consec(m,n);
					break;
				case 3:modified(m,n);
					break;
				}
			if(cnt>maxcount) 
			maxcount=cnt;
			if(cnt<mincount)
			mincount=cnt;
			}
		}
		switch(ch)
		{
		case 1:fp2=fopen("e_b.txt","a");
		       fp1=fopen("e_w.txt","a");
			break;
		case 2:fp2=fopen("c_b.txt","a");
		       fp1=fopen("c_w.txt","a");
			break;
		case 3:fp2=fopen("m_b.txt","a");
			fp1=fopen("m_w.txt","a");
			break;
		}
	fprintf(fp2,"%d %d\n",i,mincount);
	fclose(fp2);
	fprintf(fp1,"%d %d\n",i,maxcount);
	fclose(fp1);
	}	
}
void main()
{
	for(;;)
	{
		printf("\nEnter 1 for tester and 2 for plotter and Other to exit\n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:tester();
			       break;
			case 2:for(int i=1;i<4;i++)
				       plotter(i);
			       break;
			default:exit(1);
		}
	}
	
}
