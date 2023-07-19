#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void  fun(int r)
{
	printf("KAMAL\n");
}
int main()
{
printf("kamalllll\n");
printf("%d",getpid());
raise(SIGUSR2);
(void) signal(SIGUSR1,fun);
	while(3);
}
