#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[])
{
	int num;
	scanf_s("%d", &num);
	if (num < 0 || num >= 100000)
	{
		printf("data error!");
	}
	if (num / 10000 > 0)
	{
		printf("%d\n", num / 10000);
	}
	if (num % 10000 >= 1000)
	{
		printf("%d\n", (num % 10000) / 1000);
	}
	if (num % 1000 >= 100)
	{
		printf("%d\n", (num % 1000) / 100);
	}
	if (num % 100 >= 10)
	{
		printf("%d\n", (num % 100) / 10);
	}
	if (num % 10 >= 1)
	{
		printf("%d\n", num % 10);
	}
	system("pause");
	return 0;
}
