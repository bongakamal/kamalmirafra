#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char b[30]= {0};//="1234567890abcdefghijklm";
	char buff[30]="Mirafra Technologies Hyderabad";
	fd=open("/dev/my_driver2",O_RDWR);
	if(fd<0)
	{
		perror("open failed\n");
	}
	write(fd,buff,strlen(buff)+1);
		if(lseek(fd,21,SEEK_SET)==-1)
		{
		perror("lseek fail\n");
		return 0;
		}
	 
	read(fd,buff,sizeof(buff));
	printf("%s\n",buff);
	close(fd);
}
