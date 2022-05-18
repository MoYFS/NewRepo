#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int digui(int z);
	int n = 5;
	printf("%d", digui(n));
}
int digui(int z)
{
int s = 1; 
	if (z == 0)
	{
		return(s);
	}
	else
	{
		s = digui(z - 1) * z;
	}
}