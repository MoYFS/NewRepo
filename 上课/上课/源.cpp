#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a, b, c, d = 0;
	scanf_s("%d", &a);
	b = a / 100;
	c = (a / 10) % 10;
	d = a - b * 100 - c * 10;
	printf("%d", d * 100 + c * 10 + b);
	return 0;
}