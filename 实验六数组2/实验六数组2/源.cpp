#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[] = { 57,50,46,40,36,32,27,24,21,16,13,11,7,4,2 };
	int l =0, m=7, r =14, x,c=0,i=0;
	printf("输入要查找的数\n");
	scanf_s("%d", &x);
	for (;;)
	{
		if (x == a[0])
		{
			printf("1");
			break;
		}
		if (x == a[14])
		{
			printf("15");
			break;
		}
		if (x == a[m])
		{
			printf("%d", m+1);
			break;
		}
		else
		{
			if (x > a[m])
			{
				r = m;
				m = (l + r) / 2;
			}
			else
			{
				l = m;
				m = (l + r) / 2;
			}
		}
		i++;
		if (i > 7)
		{
			printf("无此数");
			break;
		}
	}
}
