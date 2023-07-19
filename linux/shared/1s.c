#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<error.h>
#include<string.h>
int main()
{
	int id;
	id=shmget((key_t)8482,1000,0666|IPC_CREAT);
	if(id<0)
	{
		perror("get::");
	}
	void *shad=shmat(id,NULL,0);
//printf("%d\n",id);
if(*(int*)shad==-1)
		perror("ad::");
//*((int*)shad)=id;
//*((int*)shad)=40;
	strcpy((char*)shad,"kamal");
int i=shmdt(shad);
if(i==-1)
		perror("dt::");
//sleep(30);
shmctl(id,IPC_RMID,0);
}
