#include<stdio.h>
//#pragma prag (1)
struct st
{
char c;
int a;
char h;
int b;
};
int main()
{
struct st s;
s.c='q';
s.a=1;
printf("%p\n",&s.c);
printf("%p\n",&s.a);
}
