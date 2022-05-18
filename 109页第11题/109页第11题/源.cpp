#include<stdio.h>
int main()
{
	int a[4]={0,0,0,0},b=0,i=0;
	scanf_s("%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3]);
	while ((a[0] > a[1]) || (a[2] > a[3]) || (a[0] > a[2]) || (a[1] > a[3]))
	{
		if (i <=2)
		{
			if (a[i] > a[i + 1])
			{
				b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
				i++;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i = 0;
		}
	}
	printf("%d,%d,%d,%d", a[0], a[1], a[2], a[3]);
	return 0;	
}