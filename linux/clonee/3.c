 /* #include <unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<sched.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
#define _GNU_SOURCE*/#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sched.h>
  #include <unistd.h>
 #include <sys/types.h>
       #include <sys/wait.h>

struct a{
	int a;
	int b;
};
int fun(struct a *s)
{
//struct a *p=(struct a*)s;
	//printf("%d\n",p->a);
	printf("%d\n",s->a);
return 0;
}
int main()
{
	struct a s;
	s.a=10;
	s.b=9;
	void *st=malloc(4000);

	int id=clone(fun,st+4000,SIGCHLD,&s);
		printf("%d\n",id);
wait(&id);
return 0;
}

