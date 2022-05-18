#include<stdio.h>
int main()
{
	int a, b, x = 0,c;
	scanf_s("%d", &c);
	printf("\n");
	for (a = 1; a <= c; a++) {
		for (b = 1; b <= a; b++)
		{
			printf("%s","*");
		}
		printf("\n");
	}
		return 0;
}