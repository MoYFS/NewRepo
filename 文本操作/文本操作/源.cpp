#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<io.h>
#include"text.h"
int main()
{
	FILE* paper;
	char a[10],fileaddress[]={ "D:\\����\\���մ�.txt"};
	//scanf("%s+\0", fileaddress);
	if (access(fileaddress,0)!=0)
	{
		printf("%s�õ�ַ�����ڸ��ļ�", fileaddress);
	}
//	paper = fopen("D:\\����\\text.txt", "w");
	printf("����10���ַ�\n");
	//scanf("%s", &a);
	//fputs(a, paper);
	//fclose(paper);
}
