#include<stdio.h>
#include<math.h>
int a=100, b, c,d=0;
int main()
{
	int sushu(int n);
	while (a <= 200)
	{
		if (sushu(a) == 1)
		{
			printf("  %d", a);
			d++;
		}
		else
		{
			printf("");
		}
		a++;
	}
	printf("\n%d", d);
	return 0;
}
int sushu(int n)
{
	int i = 2, w = 0,r=0,z;
	while (i<=sqrt(n)&&w==0)
	{
		r = (n % i);
		if (r == 0)
		{
			w = 1;
		}
		else
		{
			i++;
		}
	}
	if (w == 0)
	{
		z = 1;
	}
	else
	{
		z = 0;
	}
	return(z);
}