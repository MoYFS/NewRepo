		#include<stdio.h>
		#include<ctype.h>
	int main()
	{
		int b;
		char  a;
		a = getchar();
		if (isdigit(a) == 4)
		{
			printf("为数字");
		}
		else
		{
				if (islower(a) == 2)
				{
					printf("小写字母");
				}
				else
				{
					if (isupper(a) == 1)
					{
						printf("大写字母");
					}
					else
					{
						if (isspace(a) == 8)
						{
							printf("为空格");
						}
						else
						{
							printf("其他字符");
						}
					}
			    }
		}
		return 0;
	}