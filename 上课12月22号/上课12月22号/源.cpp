#include<stdio.h>
int main()
{
	void xz(int a[], int n, int i);
	int a[10] = { 23,123,3,2,45,43,29,13,46,89 },n,i;
	n = sizeof(a) / sizeof(a[0]);
	xz(a, n, 0);
	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}
void xz(int a[], int n, int i)
{
	if (i + 1 >= n)
	{
		return;
	}
	else
	{
		int temp, j;
		temp = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[temp])
			{
				temp = j;
			}
		}
			if (temp != i)
			{
				int m;
				m = a[i];
				a[i] = a[temp];
				a[temp] = m;
			}
		xz(a, n, i+1);
	}
}