#include <stdio.h>
void sort(int a[]);
int main() {
	int a[10];
	int i;
	printf("input 10 numbers:\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	sort(a);
	return 0;
}
void sort(int a[])
{
	int i, j, t;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 9-i; j++)
				if (a[j] > a[j + 1])
				{
					t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
				}
	printf("the sorted numbers:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", a[i]);
	}
}
