#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<stdio.h>
int main() {
	sem_t *sem = sem_open("/my_named_semaphore", 0);
	int semValue;
	sem_getvalue(sem, &semValue);
	printf("// Process 3%d\n",semValue);
	sem_wait(sem);
	sem_getvalue(sem, &semValue);
	printf("// Process 3%d\n",semValue);

	sem_post(sem);

	sem_close(sem);

	return 0;
}


