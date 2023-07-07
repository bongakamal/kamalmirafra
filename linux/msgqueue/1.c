#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
struct msg
{
	int type;
	char mssage[100];
};
int main()
{
	int id,n;
	struct msg ka;
	if(id=msgget(555,IPC_CREAT|0666)==-1)
	{
		perror("");
	}
	ka.type=9;
	strcpy(	ka.mssage, "kamal");
	n=msgsnd(id,&ka,100,0);
	if(n<0)
	{
		perror("msgsend");
	}
	printf("writng\n");
}

