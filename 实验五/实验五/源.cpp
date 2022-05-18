#include<stdio.h>
#include<string.h>
int main()
{
    int a[8]={213,2123,22,33,445,6464,2324,7678}, b[8];
	int i, n;
	n = (sizeof(a)/sizeof(a[0]))-1;
	for (i = 0; i <= n; i++)
	{
		b[n - i] = a[i];
		printf("%-6d", a[i]);
	}
	printf("\n");
	for (i = 0; i <= n; i++)
	{
		a[i] = b[i];
		printf("%-6d", a[i]);
	}
	return 0;
}