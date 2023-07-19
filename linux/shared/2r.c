#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
 #include <unistd.h>

int main()
{
	//int fd=shmget((key_t)9984,1024,0666|IPC_CREAT);

	int fd=shmget((key_t)9984,1024,0666);
	if(fd==-1)
	{
		perror("dt");
	}
printf("k");
	void *rad=shmat(fd,NULL,0);
printf("k");
	if(*(int*)rad==-1)
	{
		perror("at");
	}
printf("k");
	printf("%d\n",*(int*)rad);
	int i=shmdt(rad);
	if(i==-1)
	{
		perror("at");
	}
}

