#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void RandomArray(int* &array)
{
	int n;
	printf("生成多少测试数字？");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	array = (int*)malloc(sizeof(int)*(n));
	for (int i = 0; i < n; i++)
	{
		array[i] = rand()%(n*10);
	}
	printf("随机数组生成完毕\n数据预览：\n");
	n = _msize(array)/sizeof(int);//获取分配的内存长度
	for (int i = 0; i < n; i++)
	{
			printf("%d\t", array[i]);
			if (i % 10 == 9)
				printf("\n");
	}
}

void BubbleSort(int* array)
{
	int i, j,temp;
	int* temp1;
	temp1 = (int*)malloc(sizeof(int) * (_msize(array)/sizeof(int)));
	for (int i = 0; i < (_msize(array) / sizeof(int)); i++)
	{
		temp1[i] = array[i];
	}
	temp = temp1[0];
	for (i = 0; i < _msize(array) / sizeof(int); i++)
	{
		for (j = i + 1; j < _msize(array) / sizeof(int); j++)
		{
			if (temp1[i] < temp1[j])
			{
				temp = temp1[i];
				temp1[i] = temp1[j];
				temp1[j] = temp;
			}
		}
	}
	for (int i = 0; i < _msize(array)/sizeof(int); i++)
	{
		printf("%d\t", temp1[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	free(temp1);
}

void DirectSort(int* array)
{
	int i;
	int* temp2;
	temp2 = (int*)malloc(sizeof(int) * (_msize(array) / sizeof(int)));
	temp2[0] = array[0];
	for (i = 1; i < (_msize(array) / sizeof(int)); i++)
	{
		for (int j = 0; j < (_msize(array) / sizeof(int)); j++)
		{
				if (array[i] > temp2[j])
				{
					if (j == (_msize(array) / sizeof(int)) - 1)
					{
						temp2[j] = array[i];
					}
					else
					{
						for (int n = i; n > j; n--)
						{
							temp2[n] = temp2[n - 1];
						}
						temp2[j] = array[i];
					}
					j = (_msize(array) / sizeof(int));
				}
		}
	}
	printf("从大到小\n");
	for (int i = 0; i < _msize(temp2) / sizeof(int); i++)
	{
		printf("%d\t", temp2[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("从小到大\n");
	for (int i = 0; i < _msize(temp2) / sizeof(int)/2; i++)
	{
		int temp;
		temp = temp2[i];
		temp2[i] = temp2[(_msize(temp2) / sizeof(int) - 1) - i];
		temp2[(_msize(temp2) / sizeof(int) - 1) - i] = temp;
	}
	for (int i = 0; i < _msize(temp2) / sizeof(int); i++)
	{
		printf("%d\t", temp2[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	free(temp2);
}
void SimpleSelectionSort(int* array)
{
	int* temp3;
	temp3 = (int*)malloc(sizeof(int) * (_msize(array) / sizeof(int)));
	for (int i = 0; i < (_msize(array) / sizeof(int)); i++)
	{
		temp3[i] = array[i];
	}
	for (int i = 0; i < (_msize(array) / sizeof(int)); i++)
	{
		int  mix = i;
		for (int j = i + 1; j < (_msize(array) / sizeof(int)); j++)
		{
			if (temp3[mix] > temp3[j])
			{
				mix = j;
			}
		}
		int temp;
		temp = temp3[i];
		temp3[i] = temp3[mix];
		temp3[mix] = temp;
	}
	for (int i = 0; i < (_msize(temp3) / sizeof(int)); i++)
	{
		printf("%d\t", temp3[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	free(temp3);
}
void ShellSort(int* array)
{
	int* temp4;
	temp4 = (int*)malloc(sizeof(int) * (_msize(array) / sizeof(int)));
	for (int i = 0; i < (_msize(array) / sizeof(int)); i++)
	{
		temp4[i] = array[i];
	}
	int n = (_msize(temp4) / sizeof(int))-1;
	while (n>0)
	{
		for (int i = n; i < _msize(temp4) / sizeof(int); i++)
		{
			int temp = temp4[i];
			int j = i - n;
			while (j>=0&&temp<temp4[j])
			{
				temp4[j + n] = temp4[j];
				j = j - n;
			}
			temp4[j + n] = temp;
		}
		n = n / 2;
	}
	for (int i = 0; i < (_msize(temp4) / sizeof(int)); i++)
	{
		printf("%d\t", temp4[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	free(temp4);
}
int partition(int* temp5, int s, int t)
{
	int i = s, j = t;
	int temp = temp5[i];
	while (i<j)
	{
		while (j > i && temp5[j] >= temp)
		{
			j--;
		}
			temp5[i] = temp5[j];
		while (i<j&&temp5[i]<=temp)
		{
			i++;
		}
			temp5[j] = temp5[i];
	}
	temp5[i] = temp;
	return i;
}
void QuickSort(int* temp5, int s, int t)
{
	int i;
	if (s < t)
	{
		i = partition(temp5, s, t);
		QuickSort(temp5, s, i - 1);
		QuickSort(temp5, i + 1, t);
	}
}
void QuickSortFun(int* array)
{
	int* temp5;
	temp5 = (int*)malloc(sizeof(int) * (_msize(array) / sizeof(int)));
	for (int i = 0; i < (_msize(array) / sizeof(int)); i++)
	{
		temp5[i] = array[i];
	}
	QuickSort(temp5, 0, _msize(array) / sizeof(int) - 1);
	for (int i = 0; i < (_msize(temp5) / sizeof(int)); i++)
	{
		printf("%d\t", temp5[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	free(temp5);
}
int main()
{
	int* array;
	printf("学号：202105630443\n姓名：张家瑞\n");
	RandomArray(array);
	printf("排序输出\n");
	printf("1.冒泡排序\n");
	BubbleSort(array);
	printf("2.直接排序\n");
	DirectSort(array);
	printf("3.简单选择排序\n");
	SimpleSelectionSort(array);
	printf("4.快速排序\n");
	QuickSortFun(array);
	printf("5.希尔排序\n");
	ShellSort(array);
	system("pause");
	return 0;
}