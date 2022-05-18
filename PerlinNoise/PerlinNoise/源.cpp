#include<stdio.h>
void PerlinNoise(int a[]);
void yicichazhi(int a[],int b[][2]);
void ercichazhi(int b[][2]);
void zh(int a[][2], char b[][51]);
int main()
{
	int i,n;
    int cs[26];
	int cs1[51][2] = {0};
	char cs2[51][51] = { ' ' };
	for (i = 0; i <= 20;i++)
	{
		for (n = 0; n <= 50; n++)
		{
			cs2[i][n] = ' ';
		}
	}
	PerlinNoise(cs);
    yicichazhi(cs, cs1);
	ercichazhi(cs1);
	zh(cs1, cs2);//×ª»»³ö´í
	for (i = 0; i <=50; i++)
	{
		for (n = 0; n <=50; n++)
		{
			printf("%c", cs2[i][n]);
		}
		printf("\n");
	}
	printf("%d",i);
	return 0;
}
