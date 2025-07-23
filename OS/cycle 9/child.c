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
	int shmid=shmget(key,sizeof(pack_t),0666);
	ptr=(pack_t*)shmat(shmid,NULL,0666);
	printf("[CHILD] Attached to shared memory with key=%d ,id=%d, address=%p\n",key,shmid,ptr);
	for(int i=0;i<ptr->n;i++)
	ptr->arr[i]=2*i+1;	
	shmdt((void*)ptr);
//	shmctl(shmid,IPC_RMID,NULL);

	
	return 0;
}
