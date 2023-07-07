#include<stdio.h>
struct s
{
	int a;
	struct ga
	{
		int d;
		int *p;
	}add;
};
void kamal (int *Z)
{

	printf("%d\n",*(Z));
}
int main()
{
	int o=10;
	struct s Z;
	Z.add.d=10;
	Z.add.p=&o;
	kamal(Z.add.p);
	//	printf("%d\n",*(Z.add.p));
}
