// zombie process
// child terminated but has an entry in parent process table
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t parent_pid,child_pid,my_pid;
	child_pid=fork();
	if(child_pid<0)
	{
		printf("Fork failed\n");
		exit(0);
	}
	else if(child_pid==0)
	{
		printf("[child] This is child process\n");
		my_pid=getpid();
		parent_pid=getppid();
		printf("[child] My pid is %d\n",my_pid);
		printf("[child] My parent's pid is %d\n", parent_pid);
		printf("[child] Exiting.\n");
		exit(0);
	}
	else
	{
	printf("[PARENT] This is the parent process.\n");
	my_pid = getpid();
	parent_pid = getppid();
	printf("[PARENT] My pid is %d\n", my_pid);
	printf("[PARENT] My parent's pid is %d\n", parent_pid);
	printf("[PARENT] Sleeping for 10 seconds.\n");
	sleep(10);
	printf("[PARENT] Child pid = %d has ended, but it has an entry in process table. \n"
	       "[PARENT] It is a zombie process.\n", child_pid);

	}
	return 0;
}
