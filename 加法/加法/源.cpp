#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char jg[5],xs[5];
	char zj[5];
	int i, n=0,m;
	char x;
	char ss1[5];
	char ss2[5];
	char s1[5] = "1234";
	char s2[5] = "123";
	long long int ws1 = 0,js=0;//记录s1的长度
	long long int ws2 = 0,bjs=0;//记录s2的长度
	ws1 = strlen(s1)+1;
	ws2 = strlen(s2)+1;
	for (i = 0; i <= ws1 - 1; i++)
	{
		ss1[i] = s1[ws1 - 1 - i];
	}
	for (i = 0; i <= ws2 - 1; i++)
	{
		ss2[i] = s2[ws2 - 1 - i];
	}
	if (ws1 >= ws2)
	{
		strcpy_s(zj,5, ss1);
		strcpy_s(xs,5, ss2);
		bjs = ws1;
		js = ws2;
	}
	else
	{
		strcpy_s(zj,5, ss2);
		strcpy_s(xs, 5, ss1);
		bjs = ws2;
		js = ws1;
	}
	for (i = 0,x=0; i <= js ;)
	{
		x = zj[i] + xs[i] - 96+n;
			if (x >= 58)
			{
				jg[i] = x - 57;
				n++;
			}
			else
			{
				jg[i] =  x;
				n = 0;
			}
			i++;
	}
	printf("       ");
	printf("       ");
	printf("%s", jg);
}