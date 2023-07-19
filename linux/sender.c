#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include <errno.h>
#include <string.h>
struct msg
{
	int t;
	char text[20];
};
int main()
{
	int i;
	key_t key=ftok("./kamalreddy",22);
printf("key%d\n",key);
	int msgid=msgget(key,IPC_CREAT|0666);
printf("id%d\n",msgid);
	if(msgid<0)
		perror("get");
	struct msg s;
	for(i=0;i<4;i++)
	{
		s.t=i+1;
		strcpy(s.text,"kamal");
		s.text[5]=i+49;
		s.text[6]='\0';
		if(msgsnd(msgid,&s,30,0)<0)
			perror("snd");
		printf("%d\t%s\n",s.t,s.text);
	}
	getchar();

	msgctl(msgid,IPC_RMID,0);
return 0;
}
