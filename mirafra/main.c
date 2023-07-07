#include"header.h"
int main()
{
	prime *H=0,*L=0,*n=0;
	int m=0,Z=0,c=0;
	m=unittesting();
	if(m==-1)
		return 0;
	while(1)
	{
		printf("enter the range from where to where you want to get prime nummbers\n");
		scanf("%d%d",&m,&Z);
		if(m>=0&&Z>=0)
		{
			if(Z<m)
			{
				c=m;
				m=Z;
				Z=c;
			}
			break;
		}
		else
			printf("enter positive number prime numbers are positive only\n");
	}
	if(m==1)
		m=m+1;
	for(;m<=Z;m++)
	{
		if(m==2)
			c=1;
		else if(!(m%2==0))
			c=primecheck(m);
		if(c==1)
		{
			n=creation(m);
			if(!H)
			{
				H=n;
				H->cp=0;
			}
			else
			{
				L->nxt=n;
				if((m - L->p)==2)
					n->cp=L->p;
				else
					n->cp=0;
			}
			L=n;
		}
		c=0;

	}
	OUTPUT(H);
}
prime* creation(int m)
{
	prime *N=(prime*)malloc(sizeof(prime));
	N->p=m;
	N->nxt=0;
	return N;
}
void OUTPUT(prime *p)
{
	while(p)
	{
		printf("%d\t",p->p);
		printf("%d\t",p->cp);
		printf("\n");
		p=p->nxt;
	}
}
int primecheck(int m)
{
	int i;
	for(i=2;i<=m/2;i++)
	{
		if(m%i==0)
			break;
	}
	if(m%i==0)
		return -1;
	else 
		return 1;
}
int unittesting()
{
	int c=0,d=0;
	c=primecheck(3);
	if(c==1)
		printf("sucessfull at '3'\n");
	else{
		printf("not successfull at '3'\n");
		d=-1;}	
	c=primecheck(9);
	if(c==1){
		printf(" not successfull at '9'\n");
		d=-1;}
	else
		printf("  sucessfull at '9'\n");
return d;
}
