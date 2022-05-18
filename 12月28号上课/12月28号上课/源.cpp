#include<stdio.h>
#include<stdlib.h>
int main()
{
	void inorder(int* a,int n);
	int array[] = { 1,2,3,4,5,6,7,8,9,10 ,11,12},i;
	int* p;
	p = array;
	inorder(p,sizeof(array)/sizeof(array[1]));
	for (i = 0; i < sizeof(array) / sizeof(array[1]); i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}
void inorder(int* a,int n)
{
	int tmep,i=0;
	for (; i < n/2; i++)
	{
		tmep = *(a + i);
		*(a + i) = *(a + (n-1 - i));
		*(a + (n-1 - i)) = tmep;
	}
}