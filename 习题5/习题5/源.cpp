#include<stdio.h>
int main()
{
	int n;
	printf("������n\n");
	scanf_s("%d", & n);
	if (n % 3 == 0 && n % 5 == 0)
		printf("%d%s", n, "�ܱ�3��5����");
	else 
		printf("%d%s",n,"���ܱ�3��5����");
	return 0;
}