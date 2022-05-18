#include "stdio.h"
int main()
{
	int a, b,c;
	scanf_s("%d/%d", &a, &b);
	printf("a:%d b:%d\n", a, b);
	if (a < b )
	{
		int cnt = 0, mer = a * 10 / b, rem = a * 10 % b;
		printf("0.%d", mer);
		while (rem) {
			mer = rem * 10 / b;
			rem = rem * 10 % b;
			++cnt;
			if (cnt == 400)
				break;
			printf("%d", mer);
		}
		printf("\n");
	}
	else
	{
		int cnt = 0, mer = a * 10 / b, rem = a * 10 % b;
		c = a / b;
		printf("%d.%d",c, mer);
		while (rem) {
			mer = rem * 10 / b;
			rem = rem * 10 % b;
			++cnt;
			if (cnt == 400)
				break;
			printf("%d", mer);
		}
		printf("\n");
	}
	return 0;
}