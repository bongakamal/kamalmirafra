#include<stdio.h>
#include<stdlib.h>

typedef struct prime
{
int p;
int cp;
struct prime *nxt;
}prime;
prime* creation(int);
 void  OUTPUT(prime *p);
int primecheck(int);
