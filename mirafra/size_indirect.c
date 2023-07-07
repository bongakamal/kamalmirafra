#include<stdio.h>
#define var(a)   (char*)(a+1) - (char*)(a)
int main()
{
int f=10;
//int *p=&f;
char c='c';
char *p=&c;
printf("%lu",var(p));
}
