#include<stdio.h>
int prime(int a);//��������
int main()
{
	int n, i;
	scanf_s("%d", &n);
	if (prime(n) == 1) //return����ֵ1
		printf("prime");
	else
		printf("not prime");
}
int prime(int a)
{
	int i;
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
			return 0;//a%i==0������
		else
			return 1;//a%i==0����
	}
}