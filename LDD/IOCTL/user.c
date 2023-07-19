#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "header.h"

int main()
{
	char buffer[101];
	int fd=open("/dev/ioctl1",O_RDWR);
	if(fd<0)
	{
	printf("buffer");
		perror("opem");
		return 0;
	}
int r=ioctl(fd,0,"A");
//int r=ioctl(fd,PLAY,buffer);
	if(r<0)
	{
		perror("ioctl");
		return 0;
	}
	printf("%s\n",buffer);
 r=ioctl(fd,PRE,buffer);
	if(r<0)
	{
		perror("ioctl");
		return 0;
	}
	printf("%s\n",buffer);
}
