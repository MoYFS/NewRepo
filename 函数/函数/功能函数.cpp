void sort(int arry[], int n)//—°‘Ò≤Â»Î≈≈–Ú
{
	int k, i, j, t;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (arry[j] < arry[k])
				k = j;
		}
		t = arry[k]; arry[k] = arry[i]; arry[i] = t;
	}
}
void zh(int a[][3])//≈≈¡–ª•ªª
{
	int x, y, b, i, n;
	for (i = 0; i <= 2; i++)
	{
		x = i;
		for (n = i + 1; n <= 2; n++)
		{
			y = n;
			b = a[x][y];
			a[x][y] = a[y][x];
			a[y][x] = b;
		}
	}
}
int max(int a, int b)
{
	int c;
	c = a > b ? a : b;
	return c;
}
int max2(int a, int b)
{
	int m;
	m = a > b ? a : b;
	return m;
}
int max4(int a, int b, int c, int d)
{
	int m;
	m = max2(a, b);
	m = max2(m, c);
	m = max2(m, d);
	return m;
}
int jc(int n)
{
	int z;
	if (n == 1||n==0)
	{
		z = 1;
	}
	else
	{
		z = n *jc (n - 1);
	}
	return z;
}