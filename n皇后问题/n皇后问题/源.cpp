#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include"te.h"
#include"te2.h"
int main()
{
	int n;
	printf("�ʺ����⣨n<20)=");
	scanf("%d", &n);
	if (n > 20)
	{
		printf("nֵ��������������\n");
		scanf("%d", &n);
	}
	else
	{
		printf("%d�ʺ�����������£�\n", n);
		queen(n);
		//queeN(n);
	}
	system("pause");
	//queen(20);
}