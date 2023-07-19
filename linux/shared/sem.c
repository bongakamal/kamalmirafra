#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

#include<stdio.h>
#include <semaphore.h>

int main() {
	sem_t *sem = sem_open("/my_named_semaphore", O_CREAT, 0644, 1);
	int semValue;
	sem_getvalue(sem, &semValue);  
	printf("// Process 1%d\n",semValue);
	sem_wait(sem);
	sem_getvalue(sem, &semValue);  

	printf("// Process 1%d\n",semValue);

	sleep(40);
	sem_post(sem);

	sem_close(sem);
	sem_destroy(sem);
	return 0;
}






    


    



   

    



