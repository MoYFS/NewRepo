#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <malloc.h>
typedef struct BSTreeNode
{
	int data;
	struct BSTreeNode* left;//������
	struct BSTreeNode* right;//������
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
	printf("����������:\n");
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
	printf("�������ż���\nѧ�ţ�202105630443\n");
	int n;
	printf("��Ҫ����������ݣ�");
	scanf("%d", &n);
	array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("����������:\n");
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
				printf("����������ֵ���ڣ�ֵΪ%d\n", tree->data);
			}
			else if (tree->data > key)
			{
				BinaryTreeSearch(tree->left,key);    //�ݹ����������
			}
			else if (tree->data < key)
			{
				BinaryTreeSearch(tree->right,key);    //�ݹ����������
			}
		}
		else if (tree == NULL)
		{
			printf("����������ֵ������\n");
		}
}
int main()
{
	int* array;
	int key;
	BSTree* tree;
	getdata(array);
	printf("��Ҫ���ҵ�ֵ��");
	scanf("%d", &key);
	printf("ֱ�Ӳ��ҵĽ������%dλ(���0��Ϊδ�ҵ�)\n", SequentialSearch(array, key)+1);
	printf("���ֲ��ҵĽ������%dλ(���0��Ϊδ�ҵ�)\n", BinarySearch(array,key)+1);
	Create_BSTreeNode(tree, array);
	BinaryTreeSearch(tree, key);
}