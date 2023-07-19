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

	if (msgrcv(id, &ka, sizeof(ka.message), 9, 0) == -1)
	{
		perror("msgrcv");
		return 1;
	}

	printf("Received message: %s\n", ka.message);

	return 0;
}

