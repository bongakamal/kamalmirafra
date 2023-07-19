#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include <errno.h>
#include <string.h>
struct msg
{
	long t;
	char text[20];
};
int main()
{
	int i,j=4;
	key_t key=ftok("./kamalakar",15);
printf("key%d\n",key);
	int msgid=msgget(key,IPC_CREAT|0666);
	if(msgid<0)
		perror("get");
	struct msg s;
	for(i=0;i<4;i++,j--)
	{
		s.t=4;
		strcpy(s.text,"kamal");
		s.text[5]=i+49;
		s.text[6]='\0';
		if(msgsnd(msgid,&s,30,0)<0)
			perror("snd");
		printf("%d\t%s\n",s.t,s.text);
	getchar();
	}
//	msgctl(key,IPC_RMID,0);
}
