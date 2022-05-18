#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<io.h>
#include"text.h"
int main()
{
	FILE* paper;
	char a[10],fileaddress[]={ "D:\\下载\\大苏打.txt"};
	//scanf("%s+\0", fileaddress);
	if (access(fileaddress,0)!=0)
	{
		printf("%s该地址不存在该文件", fileaddress);
	}
//	paper = fopen("D:\\下载\\text.txt", "w");
	printf("输入10个字符\n");
	//scanf("%s", &a);
	//fputs(a, paper);
	//fclose(paper);
}
