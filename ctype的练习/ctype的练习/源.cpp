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
			printf("Ϊ����");
        }
		else
		{
			if (islower(a) != 0)
			{
				printf("ΪСд��ĸ");
			}
			else
			{
				printf("Ϊ��д��ĸ");
			}
		}
	}
	else
	{
		if (isspace(a) != 0)
		{
			printf("Ϊ�ո�");
		}
		else
		{
			printf("Ϊ�����ַ�");
		}
	}
}