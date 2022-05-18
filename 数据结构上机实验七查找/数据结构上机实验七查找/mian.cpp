#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <malloc.h>
typedef struct BSTreeNode
{
	int data;
	struct BSTreeNode* left;//左子树
	struct BSTreeNode* right;//右子树
}BSTree;
int SequentialSearch(int array[], int key)
{
	int result = -1;
	int n = _msize(array) / sizeof(int);
	for (int i=0;  i< n; i++)
	{
		if (array[i] == key)
		{
			result = i;
			break;
		}
	}
	return result;
}
int BinarySearch(int array[], int key)
{
	int* temparray = (int*)malloc(sizeof(int) * (_msize(array) / sizeof(int)));
	memcpy(temparray, array, sizeof(int)*(_msize(array) / sizeof(int)));
	for (int i = 0; i < _msize(array) / sizeof(int); i++)
	{
		for (int j = i+1; j < _msize(array) / sizeof(int); j++)
		{
			if (temparray[j] < temparray[i])
			{
				int temp = temparray[j];
				temparray[j] = temparray[i];
				temparray[i] = temp;
			}
		}
	}
	int n = _msize(temparray) / sizeof(int);
	int right = n-1;
	int left = 0;
	printf("已输入数据:\n");
	for (int i = 0; i < n; i++)
		printf("%d,", temparray[i]);
	printf("\n");
	while (left <= right)
	{
		n = left + (right - left) / 2;
		if (key == temparray[n])    
			return n;
		else if (key > temparray[n])        
			left = n + 1;
		else                             
			right = n - 1;
	}
	return -1;
}
void getdata(int*& array)
{
	printf("姓名：张家瑞\n学号：202105630443\n");
	int n;
	printf("需要输入多少数据：");
	scanf("%d", &n);
	array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("已输入数据:\n");
	for (int i = 0; i < n; i++)
		printf("%d,", array[i]);
	printf("\n");
}
void InsertBST(BSTree*& T,int x) 
{
	if (T == NULL) 
	{
		BSTree* S = (BSTree*)malloc(sizeof(BSTree)); 
		S->data = x; 
		S->left = S->right = NULL;
		T = S; 
	}
	else if (x < T->data) InsertBST(T->left, x); 
	else InsertBST(T->right, x); 
}


void Create_BSTreeNode(BSTree*& tree, int array[])
{
	int n = _msize(array) / sizeof(int);
	tree = NULL;
	for (int i = 0; i < n; i++)
	{
		InsertBST(tree, array[i]);
	}
}
void BinaryTreeSearch(BSTree* tree, int key)
{
		if (tree != NULL)
		{
			if (tree->data == key)
			{
				printf("二叉树查找值存在，值为%d\n", tree->data);
			}
			else if (tree->data > key)
			{
				BinaryTreeSearch(tree->left,key);    //递归查找左子树
			}
			else if (tree->data < key)
			{
				BinaryTreeSearch(tree->right,key);    //递归查找右子树
			}
		}
		else if (tree == NULL)
		{
			printf("二叉树查找值不存在\n");
		}
}
int main()
{
	int* array;
	int key;
	BSTree* tree;
	getdata(array);
	printf("需要查找的值：");
	scanf("%d", &key);
	printf("直接查找的结果：在%d位(输出0则为未找到)\n", SequentialSearch(array, key)+1);
	printf("二分查找的结果：在%d位(输出0则为未找到)\n", BinarySearch(array,key)+1);
	Create_BSTreeNode(tree, array);
	BinaryTreeSearch(tree, key);
}