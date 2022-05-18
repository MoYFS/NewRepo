#include<stdio.h>
int main()
{
	int sign = 1,b;
	scanf_s("%d", &b);
	double sum = 1.0, fm = 2.0;
	while (fm <= b)
	{
		sign = -sign;
		sum = sum + sign / fm;
		fm++;
	}
	printf("%f", sum);
}
