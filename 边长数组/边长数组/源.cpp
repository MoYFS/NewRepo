#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date
{
	int nlen;
	char date[0];
};
int main()
{
	char a[] = "123456789";
	date* p = (date*)malloc(sizeof(date) * strlen(a)+1);
	strcpy(p->date,a);
	printf("%s", p->date);
}