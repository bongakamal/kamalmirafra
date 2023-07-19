#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sched.h>
  #include <unistd.h>
 #include <sys/types.h>
       #include <sys/wait.h>


int fun(void *arg)
{
	int i=0;
	printf("child%p\n",&i);
	sleep(1000);
	printf("kamal\n");
	return 0;
}
int main()
{
	int i;
	void *stack=malloc(4000);
	int fd=	clone(fun,stack+4000,SIGCHLD,0);
	if(fd<0)
		perror("clone");
	else
		//sleep(1000);
		printf("fd::%d\n",fd);
	printf("st::%p\t%p\n",&stack,stack);
wait(&i);
return 0;
}
