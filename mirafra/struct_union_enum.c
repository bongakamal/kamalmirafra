#include<stdio.h>
struct s
{
	int a;
	union
	{
		int b;
		char c;
	};
	enum 
	{
		ONE=1,
		TWO=2
	};
	char f;
};
int main()
{
	struct s s;
	s.b=10;
	s.a=1;
	if(s.a==TWO)
		s.b=99;
	printf("%d\n",s.b);
}
