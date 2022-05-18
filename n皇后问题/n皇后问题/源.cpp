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
	printf("皇后问题（n<20)=");
	scanf("%d", &n);
	if (n > 20)
	{
		printf("n值过大，请重新输入\n");
		scanf("%d", &n);
	}
	else
	{
		printf("%d皇后问题求解如下：\n", n);
		queen(n);
		//queeN(n);
	}
	system("pause");
	//queen(20);
}