#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAXSTAR 2000	// ��������

struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 640;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
	star[i].color = RGB(star[i].color+rand()*255, star[i].color+rand()*255, star[i].color+rand()*255);
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);

	// ������λ��
	star[i].x += star[i].step;
	if (star[i].x > 1024)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

// ������
int main()
{
	srand((unsigned)time(NULL));	// �������
	initgraph(1024, 640,0);			// ������ͼ����
	movewindow((1960-1024)/4,(1080-640)/4);
	// ��ʼ����������
	for (int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 1024;
	}

	// �����ǿգ���������˳�
	while (!kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}

	closegraph();					// �رջ�ͼ����
	return 0;
}

