#include<stdio.h>
#include<ctype.h>
void main()
{
	char a;
	a = getchar();
	if (isalnum(a)!=0)
	{
		if (isalpha(a) == 0)
		{
			printf("为数字");
        }
		else
		{
			if (islower(a) != 0)
			{
				printf("为小写字母");
			}
			else
			{
				printf("为大写字母");
			}
		}
	}
	else
	{
		if (isspace(a) != 0)
		{
			printf("为空格");
		}
		else
		{
			printf("为其他字符");
		}
	}
}