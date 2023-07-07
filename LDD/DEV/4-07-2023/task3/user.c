 #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
int main()
{
	char m[30]={"mirafra hyderabad"};
	char t[30]={"technologies"};
	int r;
	int fd=open("/dev/TASKkamal",O_RDWR);
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
	
	r=lseek(fd,8,SEEK_SET);
	if(r==-1)
	{
		perror("LSEEK");
		return 0;
	}
	r=read(fd,t,30);
	if(r==-1)
	{
		perror("READ");
		return 0;
	}
	printf("%s\n",t);
	close(fd);
}
