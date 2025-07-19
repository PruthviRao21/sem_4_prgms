#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
void Bs(int* a,int n)
{
	cnt=0;
	int flag=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			cnt++;
			if(a[j]>a[j+1])
			{
				flag=1;
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if(flag==0)
			return;
	}
}
void Is(int* a,int n)
{
	cnt=0;
	for(int i=1;i<n;i++)
	{
		int val=a[i];
		int j=i-1;
		while(cnt++ && a[j]>val)
		{
			a[j+1]=a[j];
			j--;
			if(j<0)
			break;
		}
		a[j+1]=val;
	}
}
void Ss(int *a,int n)
{
	cnt=0;
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			cnt++;
			if(a[min]>a[j])
			{
				min=j;
			}
			if(min!=i)
			{
				int temp=a[min];
				a[min]=a[i];
				a[i]=temp;
			}
		}
	}
}
void tester()
{
	int n;
	printf("\nEnter the number of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	 printf("\nThe elements before sorting \n");
        for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
	for(;;)
	{
		printf("\nEnter:\n1.Bubble sort\n2.Insertion Sort\n3.Selection Sort\nOther to exit:\n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:Bs(arr,n);
			        printf("\nEnter the elements after sorting\n");
			        for(int i=0;i<n;i++)
                		printf("%d ",arr[i]);
				break;
			 case 2:Is(arr,n);
                                printf("\nEnter the elements after sorting\n");
                                for(int i=0;i<n;i++)
                                printf("%d ",arr[i]);
				break;
			 case 3:Ss(arr,n);
                                printf("\nEnter the elements after sorting\n");
                                for(int i=0;i<n;i++)
                                printf("%d ",arr[i]);
				break;
			default: exit(1);

		}
	}
}
void plotter(int i)
{
	int *arr,n=10;
	srand(time(NULL));
	FILE *f1,*f2,*f3,*f;
	if(i==1)
	{
		f1=fopen("Bs_best.txt","w");
		 f2=fopen("Bs_avg.txt","w");
		 f3=fopen("Bs_worst.txt","w");
	}
	else if(i==2)
        {
                f1=fopen("Is_best.txt","w");
                 f2=fopen("Is_avg.txt","w");
                 f3=fopen("Is_worst.txt","w");
     	}

	while(n<=30000)
	{
		arr=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			arr[i]=i+1;
		if(i==1)
			Bs(arr,n);
		else if(i==2)
			Is(arr,n);
			fprintf(f1,"%d\t%d\n",n,cnt);
		 for(int i=0;i<n;i++)
                        arr[i]=rand()%n;
		 if(i==1)
			 Bs(arr,n);
		 else
		 	Is(arr,n);
                        fprintf(f2,"%d\t%d\n",n,cnt);
		 for(int i=0;i<n;i++)
                        arr[i]=n-i;
		 if(i==1)
			 Bs(arr,n);
		 else
			 Is(arr,n);
                        fprintf(f3,"%d\t%d\n",n,cnt);
			if(n<10000)
			n*=10;
			else
				n+=10000;
		free(arr);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}
void plotter2()
{
	FILE* f=fopen("Ss_avg.txt","w");
	int n=10;
	int *a;
	while(n<=30000)
	{
		a=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			a[i]=i+1;
		Ss(a,n);
		fprintf(f,"%d\t%d\n",n,cnt);
		if(n<10000)
			n*=10;
		else
			n+=10000;
		free(a);
	}
	fclose(f);
}
void main()
{
	for(;;)
	{
		printf("\nEnter 1 for tester and 2 for plotter and other to exit\n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: tester();
				break;
			case 2: 
				for(int i=1;i<3;i++)
					plotter(i);
				plotter2();
				break;
			default: exit(1);
				 
		}
	}
	
}
