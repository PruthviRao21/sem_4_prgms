#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
int ls(int key,int* a,int n)
{
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		cnt++;
		if(a[i]==key)
		{
		   ans=i;
		   break;
		}
	}
	return ans;
}
int bs(int key,int* a,int low,int high)
{
	int ans;
	if(low<=high)
	{
		cnt++;
		int mid=(low+high)/2;
		if(a[mid]==key)
		{
			ans=mid;
			return ans;
		}
		else if(a[mid]>key)
			return bs(key,a,low,mid-1);
		else
			return bs(key,a,mid+1,high);
	}
	return -1;
}
void tester()
{
	int n;
	printf("\nEnter the size: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int key;
	printf("\nEnter the key : ");
	scanf("%d",&key);
	for(;;)
	{
		int ch;
		printf("\nEnter :\n1.Linear search\n2.Binary search\n");
		scanf("%d",&ch);
		int ans;
		switch(ch)
		{
			case 1:ans=ls(key,arr,n);
			       printf("Index is %d\n",ans);
			       break;
			  case 2:ans=bs(key,arr,0,n-1);
                               printf("Index is %d\n",ans);
				 break;
			default:exit(1);
		}
	}
}
void plotter(int i)
{
	srand(time(NULL));
	int *arr;
	int key,n=2;
	FILE *f1,*f2,*f3;

	if(i==1)
	{
//		FILE *f1,*f2,*f3;
		f1=fopen("binarybest.txt","w");
 		f2=fopen("binaryavg.txt","w");
		 f3=fopen("binaryworst.txt","w");

	}
	else 
        {
  //              FILE *f1,*f2,*f3;
                f1=fopen("linearbest.txt","w");
                f2=fopen("linearavg.txt","w");
                 f3=fopen("linearworst.txt","w");
        }
	while(n<=1024)
	{
		arr=(int*)malloc(sizeof(int)*n);
		cnt=0;
		for(int x=0;x<n;x++)
			*(arr+x)=1;
		
	 if(i!=1)
	 {
		 ls(1,arr,n);
		 fprintf(f1,"%d\t%d\n",n,cnt);

	 }
	 else
	 {
		 bs(1,arr,0,n-1);
		fprintf(f1,"%d\t%d\n",n,cnt);
	 }
	 	cnt=0;
		 for(int x=0;x<n;x++)
                        *(arr+x)=rand()%n;
		 key=rand()%n;
	 if(i!=1)
         {
                 ls(key,arr,n);
                 fprintf(f2,"%d\t%d\n",n,cnt);

         }
         else
         {
                 bs(key,arr,0,n-1);
                fprintf(f2,"%d\t%d\n",n,cnt);
         }
		  cnt=0;
                for(int x=0;x<n;x++)
                        *(arr+x)=1;

         if(i!=1)
         {
                 ls(0,arr,n);
                 fprintf(f3,"%d\t%d\n",n,cnt);

         }
         else
         {
                 bs(0,arr,0,n-1);
                fprintf(f3,"%d\t%d\n",n,cnt);
         }

	n*=2;
	free(arr);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
}
void main()
{
	for(;;)
	{
		int ch;
		printf("\nEnter 1 for Tester and 2 for Plotter and Other to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:tester();
			       break;
			case 2:for(int i=1;i<3;i++)
				       plotter(i);
			       break;
			default: exit(1);
		}
	}
}
