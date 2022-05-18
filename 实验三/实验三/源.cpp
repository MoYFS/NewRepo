#include<stdio.h>
#include<math.h>
int main()
{
	float r, h, c, s1, s2, v1, v2;//r半径，h高，c圆周长，s1圆面积，s2球表面积，v1球体积,v2圆柱体积
	printf("请输入圆半径r，圆柱高h");
	scanf_s("%f,%f", &r, &h);
	c = 2 * r * 3.14;
	s1 = r * r * 3.14;
	s2 = 4 * r * r * 3.14;
	v1 = (4 * r * r * r * 3.14) / 3;
	v2 = c * h;
	printf("圆周长c=%.2f\n圆面积s1=%.2f\n球表面积s2=%.2f\n球体积v1=%.2f\n圆柱体积v2=%.2f", c, s1, s2, v1, v2);
	return 0;
}