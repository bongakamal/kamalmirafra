#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	printf("a.out%d\n",getpid());
	pid_t f=fork();
	if(f==0)
		printf("child%d\n",getpid());
//	else
		printf("parent%d\n",getpid());
printf("kamal\n");
}

