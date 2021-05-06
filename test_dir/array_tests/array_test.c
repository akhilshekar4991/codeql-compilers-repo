#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
	int a[5], b[5], c[5];
	srand(time(0));
	for(int i=0; i<5; i++) 
	{
		a[i] = rand();
		b[i] = rand();
		c[i] = a[i] * b[i];
	}
}
