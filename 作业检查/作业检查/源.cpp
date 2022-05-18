#include<stdio.h>
int main()
{
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} }, i, n;
	int (* b)[3];
	b = &a[0];
	for (i=0;i<3;i++)
	{
		for (n = 0; n <= 2; n++)
		{
			printf("%d  ",   *b[i] + n);
}
		printf("\n");
	}
	return 0;
}
