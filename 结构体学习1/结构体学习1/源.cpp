#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char names[10];
	char sex[4];
	int age;
};
void printfl(struct student* p)
{
	int i;
	printf("名字 性别 年龄\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s %s  %d\n", (p+i)->names,(p+i)->sex,(p+i)->age);
	}
}
void rename(struct student* p,int m)
{
	printf("修改后名称\n");
	scanf("%s", (p+m)->names);
}
void resex(struct student* p, int m)
{
	printf("修改后性别\n");
	scanf("%s", (p+m)->sex);
}
void reage(struct student* p, int m)
{
	printf("修改后年龄\n");
	scanf("%d", &(p+m)->age);
}
void newinput(struct student* p, int m)
{
	printf("名字 性别 年龄\n");
	printf("%s %s  %d\n", (p+m)->names, (p+m)->sex, &(p+m)->age);
}
//分界线，上方为函数部分。The dividing line, the upper part of the function.
int main()
{
	struct student member[4];
	struct student* p = member;
	int i;
	char name[10];
	printf("名字  性别 年龄\n");
	for (i = 0; i < 4; i++)
	{
		scanf("%s%s%d", member[i].names, member[i].sex, &member[i].age);
	}
	printf("\n");
	printfl(p);
	while (1)
	{
		char pm[10]="\0";
		char* d = pm;
		int m=0;
		scanf("%s", name);
		for (m = 0; m < 4; m++)
		{
			if (strcmp(name, (p + m)->names)==0)
			{
				printf("修改项目\n改名请输入n，修改性别请输入s，修改年龄请输入a，从新输入该人信息请输入i\n");
				scanf("%s", pm);
				switch (*d)
				{
				case 'n':rename(p, m); break;
				case 's':resex(p, m); break;
				case 'a':reage(p, m); break;
				case 'i':newinput(p, m); break;
				default:printf("输入正确操作");
					break;
				}
				printfl(p);
				break;
			}
		}
	}
	return 0;
}