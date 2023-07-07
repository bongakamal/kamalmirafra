 #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
int main()
{
	char m[30]={"mirafra"};
	char t[20]={"technologies"};
	char h[20]={"hyderabad"};
	int r;
	int fd=open("/dev/TASK1",O_RDWR);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	r=write(fd,m,20);
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	r=write(fd,t,20);
	if(r==-1)
	{
		perror("TW");
		return 0;
	}
	r=write(fd,h,20);
	if(r==-1)
	{
		perror("HW");
		return 0;
	}
	r=read(fd,m,30);
	if(r==-1)
	{
		perror("READ");
		return 0;
	}
	printf("%s\n",m);
	close(fd);
}
