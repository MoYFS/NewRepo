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
	printf("��д��ĸ%d��\nСд��ĸ%d��\n����%d��\n�ո�%d��\n����%d��\n", d, x, s, k, (q-1));
	return 0;
}