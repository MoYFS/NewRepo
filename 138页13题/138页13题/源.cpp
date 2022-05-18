#include<stdio.h>
#include<math.h>
int main()
{
	double x1, x2,a;
	printf("输入一个数");
	scanf_s("%lf", &a);
	for (x1 = a / 2, x2 = (x1 + (a / x1)) / 2; fabs(x1 - x2) >= 1e-5; x1 = x2, x2 = (x1 + (a / x1)) / 2);
	printf("%lf", x2);
}