#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
struct msg
{
	int type;
	char mssage[100];
};
int main()
{
	int id;
	struct msg ka;
	if(id=msgget(789,0666)==-1)
	{
		perror("");
	}
//	ka.type=9;
//	ka.mssage="kamal";
	msgrcv(id,&ka,100,0,0);
	printf("%s\n",ka.mssage);
//msgctl(id,IPC_RMID,NULL);
}

