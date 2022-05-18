#include<stdio.h>
#include<stdlib.h>
void operation(int* sz,int *mx);
int main()
{
	//int array[10], i;
	int array[10]={12,31,54,22,3,1,87,54,44,67 };
	/*for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &array[i]);
	}*/
	int * mx = (int*)malloc(sizeof(int) * 4);
	operation(array,mx);
	printf("最大值为%d,最大值下标为array[%d]\n最小值为%d,最小值下标为array[%d]", *mx,*(mx+1), *(mx+2),*( mx+3));
	free(mx);
}
void operation(int* sz,int*mx)
{
	int i;
	*mx = *sz;
	*(mx+1) = 0;
	*(mx + 2) = *sz;
	*(mx + 3) = 0;
	for (i = 1; i < 10; i++)
	{
		if (*mx > *(sz + i))
		{
			if (*(mx + 2) > *(sz + i))
			{
				*(mx + 2) = *(sz + i);
				*(mx + 3) = i;
			}
		}
		else
		{
			*mx = *(sz + i);
			*(mx + 1) = i;
		}
	}
}