#include<stdio.h>
int main()
{
	void x(int a);
	int b;
	scanf_s("%d", &b);
	x(b);
	return 0;
}
void x(int a)
{
	int z=0,i,b=0,c=a;
	for (;;)
	{
		if (c / 10 == 0)
		{
			z++;
			break;
		}
		else
		{
			z++;
		}
		c = c/ 10;
	}
	for (i = 0; i <= z; i++)
	{

		if ((a % 10) % 2 == 0)
		{
			b =b*10+ (a % 10);
			a = a / 10;
}
		else
		{
			a = a / 10;
		}
	}
	printf("%d", b/10);
}