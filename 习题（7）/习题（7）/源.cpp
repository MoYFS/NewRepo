#include<stdio.h>
int main()
{
	long long a, b, c,d=1;
	scanf_s("%lld,%lld", &a,&b);
	c = 2;
	while (c <= a && c <= b)
	{
		if (a % c == 0 && b % c == 0)
		{
			d = c;
			c++;
		}
		else
		{
			c++;
		}
	}
	printf("%lld", d);
	return 0;
}