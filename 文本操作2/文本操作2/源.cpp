#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<io.h>
void branch1(char temp[])
{
	char opinion2;
	printf("�Ƿ�ɾ�����ļ�\nY/N\n");
	getchar();
	scanf("%c", &opinion2);
	switch (opinion2)
	{
	case 'Y':remove(temp),printf("ɾ���ɹ�\n"); break;
	case 'N':printf("�޲���"); break;
	default:printf("�������");
		break;
	}
}
void branch2(char temp[])
	{

	}
int main()
{
	FILE* paper;
	char a, fileaddress[50];
	char b;
	char opinion;
	scanf("%s+\0", fileaddress);
	printf("%s\n", fileaddress);
	if (_access(fileaddress, 0) != 0)
	{
		printf("%s�õ�ַ�����ڸ��ļ�\n�Ƿ񴴽����ļ�\nY/N\n", fileaddress);
		getchar();
		char temp1;
		scanf("%c", &temp1);
		if (temp1 == 'Y') {
			paper = fopen(fileaddress, "w");
			printf("�����ɹ�\n");
			fclose(paper);
		}
		else
		{
			return 0;
		}
	}
	paper = fopen(fileaddress, "r");
	if ((b=fgetc(paper)) == EOF)
	{
		fclose(paper);
		paper = fopen(fileaddress, "w");
		printf("Ϊ���ļ�������������\n");
		b = getchar();
		b = getchar();
		while (b != EOF)
		{
			fputc(b, paper);
			b = getchar();
		}
		printf("����ɹ�\n");
		fflush(stdin);//��ջ�����
		fclose(paper);
	}
	else
	{
		fclose(paper);
		paper = fopen(fileaddress, "r");
		while ((a = fgetc(paper)) != EOF)
		{
			printf("%c", a);
		}
		printf("\n");
		fclose(paper);
	}
	printf("�Ƿ���ļ����в�����\nY/N\n");

	opinion =(char) malloc(sizeof(char));
	getchar();
	scanf("%c", &opinion);
	if (opinion != NULL)
	{
		switch (opinion)
		{
		case 'Y':branch1(fileaddress); break;
		case 'N':branch2(fileaddress); break;
		default:printf("�������%c",opinion); 
			break;
		}
	}
	system("pause");
}