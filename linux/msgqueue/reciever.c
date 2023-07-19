#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct msg
{
	long int t;
	char text[20];
};
int main()
{
	key_t key=ftok("./kamalakar",15);
	printf("key%d\n",key);

	int id=msgget(key,0666);
	if (id<0)
		perror("get");
	int i=0,l;
	struct msg r;
	for(i=0;i<4;i++)
	{
		l=i+1;
		if(msgrcv(id,&r,30,l,IPC_NOWAIT)<0)
			perror("rcv");
		printf("%d\t%s\n",r.t,r.text);
		getchar();
	}
	msgctl(key,IPC_RMID,0);
}

