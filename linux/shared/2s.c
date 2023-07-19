#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<error.h>
#include <unistd.h>
 #define _GNU_SOURCE

int main()
{
	struct shmid_ds *p;
	int id;
	int fd=shmget((key_t)9984,1024,0666|IPC_CREAT);
	if(id<0)
		perror("get::");
	void *shad=shmat(fd,NULL,0);
	if(*(int*)shad==-1)
		perror("at::");
	*(int*)shad=10;

	id=shmdt(shad);
	if(id==-1)
		perror("dt");
	sleep(10);
	id=shmctl(fd,IPC_INFO,p);
	if(id==-1)
		perror("ctl");
}

