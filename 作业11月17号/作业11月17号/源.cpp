		#include<stdio.h>
		#include<ctype.h>
	int main()
	{
		int b;
		char  a;
		a = getchar();
		if (isdigit(a) == 4)
		{
			printf("Ϊ����");
		}
		else
		{
				if (islower(a) == 2)
				{
					printf("Сд��ĸ");
				}
				else
				{
					if (isupper(a) == 1)
					{
						printf("��д��ĸ");
					}
					else
					{
						if (isspace(a) == 8)
						{
							printf("Ϊ�ո�");
						}
						else
						{
							printf("�����ַ�");
						}
					}
			    }
		}
		return 0;
	}