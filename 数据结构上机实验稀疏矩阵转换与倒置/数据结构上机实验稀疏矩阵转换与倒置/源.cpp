#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void disprint(int a[12][3])
{
	int matrix[3][4] = { 0 };
	for (int i=1;i<=a[0][2];i++)
	{
		for (int j=1;j<=a[0][0];j++)
		{
			matrix[a[i][0]-1][a[i][1]-1] = a[i][2];
		}
}
	printf("´òÓ¡3X4Ï¡Êè¾ØÕó\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
void disprint1(int a[12][3])
{
	int matrix[4][3] = { 0 };
	for (int i = 1; i <= a[0][2]; i++)
	{
		for (int j = 1; j <= a[0][0]; j++)
		{
			matrix[a[i][0] - 1][a[i][1] - 1] = a[i][2];
		}
	}
	printf("´òÓ¡4X3Ï¡Êè¾ØÕó\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[12][3] = { {3,4,5},{1,2,3},{1,3,1},{2,1,1},{3,2,2},{3,4,1} };
	int b[12][3];
	b[0][1] = a[0][0];
	b[0][0] = a[0][1];
	b[0][2] = a[0][2];
	printf("\n\n output data:\n");
	for (int i = 0; i <= a[0][2]; i++)
	{
		printf("£¨");
		for (int j = 0; j <= 2; j++)
			printf(" %d", a[i][j]);
		printf("£©");
		printf("\n");
	}
	disprint(a);
	if (b[0][2] != 0)
	{
		int q=1,line,p;
		for (line = 1; line <= a[0][1]; line++)
		{
			for ( p = 1; p <= a[0][2]; p++)
			{
				if (a[p][1] == line)
				{
					b[q][1] = a[p][0];
					b[q][0] = a[p][1];
					b[q][2] = a[p][2];
					q++;
				}
			}
		}
	}
	printf("\n\n output data:\n");
	for (int i = 0; i <= b[0][2]; i++)
	{
		printf("£¨");
		for (int j = 0; j <= 2; j++)
			printf(" %d", b[i][j]);
		printf("£©");
		printf("\n");
	}
	disprint1(b);
	return 0;
}
