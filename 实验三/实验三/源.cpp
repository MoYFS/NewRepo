#include<stdio.h>
#include<math.h>
int main()
{
	float r, h, c, s1, s2, v1, v2;//r�뾶��h�ߣ�cԲ�ܳ���s1Բ�����s2��������v1�����,v2Բ�����
	printf("������Բ�뾶r��Բ����h");
	scanf_s("%f,%f", &r, &h);
	c = 2 * r * 3.14;
	s1 = r * r * 3.14;
	s2 = 4 * r * r * 3.14;
	v1 = (4 * r * r * r * 3.14) / 3;
	v2 = c * h;
	printf("Բ�ܳ�c=%.2f\nԲ���s1=%.2f\n������s2=%.2f\n�����v1=%.2f\nԲ�����v2=%.2f", c, s1, s2, v1, v2);
	return 0;
}