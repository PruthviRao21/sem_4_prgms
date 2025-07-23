#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/wait.h>
int main(int argc,char* argv[])
{
	int i,j,k;
	void* ptr;
	int shm_fd;
	shm_fd=shm_open("prgm",O_CREAT|O_RDWR,0666);
	ftruncate(shm_fd,4096);
	ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
	printf("Child\n");
	i=atoi(argv[1]);
	j=atoi(argv[2]);
	int flag=0;
	for(int num1=i;num1<=j;num1++)
	{
		flag=0;
		for(k=2;k*k<=num1;k++)
		{
			if(num1%k==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("%d ",num1);
			sprintf(ptr,"%d ",num1);
			ptr+=strlen(ptr);
		}
	}
	return 0;
}
