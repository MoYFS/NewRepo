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
	printf("���� �Ա� ����\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s %s  %d\n", (p+i)->names,(p+i)->sex,(p+i)->age);
	}
}
void rename(struct student* p,int m)
{
	printf("�޸ĺ�����\n");
	scanf("%s", (p+m)->names);
}
void resex(struct student* p, int m)
{
	printf("�޸ĺ��Ա�\n");
	scanf("%s", (p+m)->sex);
}
void reage(struct student* p, int m)
{
	printf("�޸ĺ�����\n");
	scanf("%d", &(p+m)->age);
}
void newinput(struct student* p, int m)
{
	printf("���� �Ա� ����\n");
	printf("%s %s  %d\n", (p+m)->names, (p+m)->sex, &(p+m)->age);
}
//�ֽ��ߣ��Ϸ�Ϊ�������֡�The dividing line, the upper part of the function.
int main()
{
	struct student member[4];
	struct student* p = member;
	int i;
	char name[10];
	printf("����  �Ա� ����\n");
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
				printf("�޸���Ŀ\n����������n���޸��Ա�������s���޸�����������a���������������Ϣ������i\n");
				scanf("%s", pm);
				switch (*d)
				{
				case 'n':rename(p, m); break;
				case 's':resex(p, m); break;
				case 'a':reage(p, m); break;
				case 'i':newinput(p, m); break;
				default:printf("������ȷ����");
					break;
				}
				printfl(p);
				break;
			}
		}
	}
	return 0;
}