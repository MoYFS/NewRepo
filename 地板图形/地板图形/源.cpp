#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<ege.h>
#include<stdio.h>
#include<math.h>
//#include<conio.h>
int main()
{
	initgraph(600, 600,INIT_WITHLOGO);
	setbkcolor(EGECOLORA(BLACK,100)); 
	setcaption("ตุฬบ");
	setcolor(EGECOLORA(WHITE, 100));
	setfillcolor(EGECOLORA(WHITE, 100));
	int pt[8] = { 0,0,0,150,75,125,75,25 };
	for (int k=0;k<=3;k++)
	{
		pt[1] = 0;
		pt[3] = 150;
		pt[5] = 125;
		pt[7] = 25;
		for (int i = 0; i <= 5; i++)
		{
			fillpoly(4, pt);
			pt[1] = pt[1] + 150;
			pt[3] = pt[3] + 150;
			pt[5] = pt[5] + 150;
			pt[7] = pt[7] + 150;
		}
		pt[0] = pt[0] + 150;
		pt[2] = pt[2] + 150;
		pt[4] = pt[4] + 150;
		pt[6] = pt[6] + 150;
	}
	setcolor(EGECOLORA(GREEN, 50));
	setfillcolor(EGECOLORA(GREEN, 50));
	int pt1[8] = { 75,25,75,125,150,150,150,0 };
	for (int k = 0; k <= 3; k++)
	{
		pt1[1] = 25;
		pt1[3] = 125;
		pt1[5] = 150;
		pt1[7] = 0;
		for (int i = 0; i <= 5; i++)
		{
			fillpoly(4, pt1);
			pt1[1] = pt1[1] + 150;
			pt1[3] = pt1[3] + 150;
			pt1[5] = pt1[5] + 150;
			pt1[7] = pt1[7] + 150;
		}
		pt1[0] = pt1[0] + 150;
		pt1[2] = pt1[2] + 150;
		pt1[4] = pt1[4] + 150;
		pt1[6] = pt1[6] + 150;
	}
	setcolor(EGECOLORA(DARKGRAY, 50));
	setfillcolor(EGECOLORA(DARKGRAY,50));
	int pt2[6] = { 0,150,150,150,75,125 };
	for (int i = 0; i <= 3; i++)
	{
		pt2[1] = 150;
		pt2[3] = 150;
		pt2[5] = 125;
		for (int k = 0; k <= 3; k++)
		{
			fillpoly(3, pt2);
			pt2[1] = pt2[1] + 150;
			pt2[3] = pt2[3] + 150;
			pt2[5] = pt2[5] + 150;
		}
		pt2[0] = pt2[0] + 150;
		pt2[2] = pt2[2] + 150;
		pt2[4] = pt2[4] + 150;
	}
	while (!kbhit())
	{
	}
	closegraph();
}