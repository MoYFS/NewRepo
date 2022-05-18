#include<stdio.h>
 static int k = 0;
char one = 'A', two = 'B', three = 'C';
int main()
{
	int hano(char a,char b,char c,int g);
	int n;
	printf("ÊäÈëÅÌ×ÓÊı\n");
	scanf_s("%d", &n);
	hano(one, two, three, n);
	printf("%d", k);
	return 0;
}
int hano(char a,char b,char c,int g)
{
	int mova(char z, char m);
	if (g == 1)
	{
		mova(a, c);
	}
	else
	{
		hano(a,c,b,g-1);
		mova(a, c);
		hano(b, a, c, g - 1);
	}
	return 0;
}
int mova(char z, char m)
{
	k++;
	printf("%c--->%c\n", z, m);
	return 0;
}