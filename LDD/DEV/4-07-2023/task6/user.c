#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>

#include<string.h>
int main()
{
	char m[4496];
	int r,i;
	for( i=0;i<4496;i++)
		m[i]='*';
		m[i]=0;
	printf("%d\n",i);
	printf("%ld\n",strlen(m));
	int fd=open("/dev/TASK1",O_RDWR);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	r=write(fd,m,i);
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	r=read(fd,m,i);
	if(r==-1)
	{
		perror("READ");
		return 0;
	}
	printf("%s\n",m);
	close(fd);
}
