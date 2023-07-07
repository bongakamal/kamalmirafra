#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

struct msg
{
	int type;
	char message[100];
};

int main()
{
	int id;
	struct msg ka;

	if ((id = msgget(705, IPC_CREAT | 0666)) == -1)
	{
		perror("msgget");
		return 1;
	}

	ka.type = 9;
	strcpy(ka.message, "kamal");

	if (msgsnd(id, &ka, sizeof(ka.message), 0) == -1)
	{
		perror("msgsnd");
		return 1;
	}

	printf("Message sent.\n");

	return 0;
}

