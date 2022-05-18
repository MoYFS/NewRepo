#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<io.h>
void branch1(char temp[])
{
	char opinion2;
	printf("是否删除该文件\nY/N\n");
	getchar();
	scanf("%c", &opinion2);
	switch (opinion2)
	{
	case 'Y':remove(temp),printf("删除成功\n"); break;
	case 'N':printf("无操作"); break;
	default:printf("输入错误");
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
		printf("%s该地址不存在该文件\n是否创建该文件\nY/N\n", fileaddress);
		getchar();
		char temp1;
		scanf("%c", &temp1);
		if (temp1 == 'Y') {
			paper = fopen(fileaddress, "w");
			printf("创建成功\n");
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
		printf("为空文件，请输入数据\n");
		b = getchar();
		b = getchar();
		while (b != EOF)
		{
			fputc(b, paper);
			b = getchar();
		}
		printf("输入成功\n");
		fflush(stdin);//清空缓存区
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
	printf("是否对文件进行操作？\nY/N\n");

	opinion =(char) malloc(sizeof(char));
	getchar();
	scanf("%c", &opinion);
	if (opinion != NULL)
	{
		switch (opinion)
		{
		case 'Y':branch1(fileaddress); break;
		case 'N':branch2(fileaddress); break;
		default:printf("输入错误%c",opinion); 
			break;
		}
	}
	system("pause");
}