#include<stdio.h>
int main()
{
	int grade;
	printf("������ɼ�\n");
	scanf_s("%d", &grade);
	if (grade >= 0 && grade <= 100)
	{
		switch (grade)
		{
		case 60:printf("D"); break;
		case 70:printf("C"); break;
		case 80:printf("B"); break;
		case 90:printf("A"); break;
		default:printf("E"); break;
		}
	}
	else
	{
		printf("�����������");
	}
	return 0;
}