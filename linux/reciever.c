#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg
{
	int t;
	char text[20];
};
int main()
{
	key_t key=ftok("./kamalreddy",22);
printf("key%d\n",key);
	
int id=msgget(key,0666);
printf("id%d\n",id);
	if (id<0)
		perror("get");
	int i=0;
	struct msg r;
	for(i=0;i<4;i++)
	{
		if(msgrcv(id,&r,30,0,0)<0)
			perror("rcv");
		printf("%d\t%s\n",r.t,r.text);
	}
	getchar();
printf("key%d\n",key);
printf("id%d\n",id);

	msgctl(id,IPC_RMID,0);
return 0;
}

