#include<stdio.h>
#include<math.h>
int main()
{
	float x, y1=-10 ,y2=10,a[3]={0};
	for(;;)
	{
		a[0] = (2 * y1 * y1 * y1 - 4 * y1 * y1 + 3 * y1 - 6);
		a[1] = (2 * y2 * y2 * y2 - 4 * y2 * y2 + 3 * y2 - 6);
		x = (y1 + y2) / 2;
		a[2] = (2 * x * x * x - 4 * x * x + 3 * x - 6);
		if (fabs(a[0] - a[1]) <= 1e-5)
		{
			break;
		}
		else
		{
			if (a[2] <= 0 && a[0] <= 0)
			{
				y1 = x;
			}
			else
			{
				if (a[2] >= 0 && a[1] >= 0)
				{
					y2 = x;
				}
				else
				{
					if (a[2] >= 0 && a[0] <= 0)
					{
						y2 = x;
					}
					else
					{
						y1 = x;
					}
				}
			}
		}
	}
	printf("%f", x);
	return 0;
}