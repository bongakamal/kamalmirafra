#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
char b[10];
int id=shmget((key_t)8482,1000,0666);
if(id<0)
perror("get");
void *shad=shmat(id,NULL,0);
if(*(int*)shad==-1)
		perror("at::");

//strcpy(b,(char*)shad);
int j=*((int*)shad);
printf("%d\n",j);
 j=*((int*)shad);
printf("%d\n",j);
//printf("%s\n",b);
int i=shmdt(shad);
if(i==-1)
		perror("dt::");

}
