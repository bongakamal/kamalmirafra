#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void myshell()
{
	int p,q,r;
	p=fork();
	if(p==0)
	{

		char s[100];
		printf("$");
		r=execl("/bin/sh","sh",NULL);
		if(r==-1)
			perror("execl fail");
		exit(0);
	}
	else
		wait(&q);

}
int main()
{

	myshell();
}

