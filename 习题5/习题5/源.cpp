#include<stdio.h>
int main()
{
	int n;
	printf("请输入n\n");
	scanf_s("%d", & n);
	if (n % 3 == 0 && n % 5 == 0)
		printf("%d%s", n, "能被3和5整除");
	else 
		printf("%d%s",n,"不能被3和5整除");
	return 0;
}