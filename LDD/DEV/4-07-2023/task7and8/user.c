#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include<stdio.h>
int main()
{
	int r,i;
	char m[1024];
	for(i=0;i<1024;i++)
		m[i]='*';
	m[i]='\0';
	int fd=open("/dev/TASK7",O_RDWR);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	r=write(fd,m,strlen(m));
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	if(lseek(fd,10,SEEK_SET)==-1)
	{
		perror("lseek");
		return 0;
	}
	r=write(fd,"sree embedded",13);
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	if(lseek(fd,100,SEEK_SET)==-1)
	{
		perror("lseek");
		return 0;
	}
	r=write(fd,"technologies",12);
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	if(lseek(fd,0,SEEK_SET)==-1)
	{
		perror("lseek");
		return 0;
	}
	r=read(fd,m,strlen(m));
	if(r==-1)
	{
		perror("MW");
		return 0;
	}
	printf("%s\n",m);
	close(fd);
}
