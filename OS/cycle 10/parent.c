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
	pid_t pid;
	void* ptr;
	int shm_fd;
	const int SIZE=4096;
	if(argc>2)
	{
		sscanf(argv[1],"%d",&i);
		sscanf(argv[2],"%d",&j);
		if(i<2)
		{
			printf("Invalid input\n");
			return 0;
		}
	}
	else
	{
		printf("Minimum of 2 arguments must be passed\n");
		exit(0);
	}
	pid=fork();
	if(pid==0)
	{
		execlp("./child","prime",argv[1],argv[2],NULL);
	}
	else if(pid>0)
	{
		wait(NULL);
		printf("\nChild completed\n");
		int shm_fd=shm_open("prgm",O_RDONLY,0666);
		ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
		printf("%s ",(char*)ptr);
		shm_unlink("prgm");
	}
	return 0;
}
