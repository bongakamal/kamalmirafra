 #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include<stdio.h>
int main()
{
	char m[30]={"mirafra technologies hyderabad"};
	char n[30];
	int r;
	int fd=open("/dev/TASK1",O_RDWR);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	r=write(fd,m,30);
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	printf("%s\n",m);
	close(fd);
}
