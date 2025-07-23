#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/types.h>
typedef struct pack_t
{
	int n;
	int arr[100];
}pack_t;
int main()
{
	key_t key=1122;
	pack_t * ptr;
	pid_t pid;
	int shmid=shmget(key,sizeof(pack_t),IPC_CREAT|0666);
	ptr=(pack_t*)shmat(shmid,NULL,0666);
	printf("[PARENT] created a shared memory with id=%d and key=%d and address=%p\n",shmid,key,ptr);
	printf("[PARENT] Enter n : ");
	scanf("%d",&ptr->n);
	pid=fork();
	if(pid==0)
	{
		execlp("./child","child",NULL);

	}
	else
	{
		wait(NULL);
		printf("\n[PARENT] child finished executing\n");
		for(int i=0;i<ptr->n;i++)
		{
			printf("%d ",ptr->arr[i]);
		}
	}
	shmdt((void*)ptr);
	shmctl(shmid,IPC_RMID,NULL);

	
	return 0;
}
