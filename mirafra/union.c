#include<stdio.h>
union add
{
	int a;
	struct j
{
		char c;
	};
};
int main()
{
	union add f;
	f.a=10;
	printf("%lu\n",sizeof(f));
	printf("%d\n",f.a);
	f.c='\0';
	printf("%c\n",f.c);
	printf("%d\n",f.a);
}
