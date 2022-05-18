#include<stdio.h>
int main()
{
	char a=0;
	int  d = 0, x = 0, s = 0, k = 0, q = 0;
	for (; a != '\n';)
	{
		a = getchar();
		if (a >= 'a' && a <= 'z')
		{
			x++;
		}
		else if (a >= 'A' && a <= 'Z')
		{
			d++;
		}
		else if (a >= '0' && a <= '9')
		{
			s++;
		}
		else if (a== ' ')
		{
			k++;
		}
		else
		{
			q++;
		}
	}
	printf("大写字母%d个\n小写字母%d个\n数字%d个\n空格%d个\n其他%d个\n", d, x, s, k, (q-1));
	return 0;
}