#include<stdio.h>
//#define Z 1
int main()
{
#ifndef Z
#error Macro is not defined
#endif 
#if(Z==1)
	printf("kamal\n");
#elif(Z==2)
	printf("REDDY\n");
#else
	printf("none\n");
#endif 
}
