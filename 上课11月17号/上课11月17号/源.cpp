#include<stdio.h>
int main()
	{
	int f1 = 1, f2 = 1, i = 2, f3=0, n;
	scanf_s("%d", &n);
	for (; i < n; i++, f1 = f2, f2 = f3)
	{
		f3 = f1 + f2;
	}
	printf("%9d\n", f3);
	return 0;
	}