#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	int age;
	char sex[10];
};
int main()
{
	struct student a;
	struct student* p;
	for (;;)
	{
		scanf_s("%s%d%s", a.name, 20, &a.age, a.sex, 10);
		p = &a;
		printf("姓名：%s\n年龄：%d岁\n性别：%s", p->name, p->age, p->sex);
	}
		return 0;
}
