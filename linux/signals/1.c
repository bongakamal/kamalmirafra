#include <unistd.h>
#include <signal.h>
#include<stdio.h>
void fun (int r)
{
	printf("in fun\n");
	sleep(5);
	printf("kamal\n");
}
int main()
{
	(void) signal(SIGINT,fun);
	(void) signal(SIGALRM,fun);
	alarm(5);
	printf("k\n");
	while(1);
}
