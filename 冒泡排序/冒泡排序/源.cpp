#include<stdio.h>	
void main()
{
	int n[10] = { 25,35,68,79,21,13,98,7,16,62 };
	int i, j, temp;
	for (i = 1; i <= 9; i++)
	{
		for (j = 0; j <= 9 - i; j++)
		{
			if (n[j] < n[j + 1])
			{
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
	printf("����������˳��:\n");
	for (i = 0; i < 10; i++)
		printf("%-4d", n[i]);
	printf("\n");
}
