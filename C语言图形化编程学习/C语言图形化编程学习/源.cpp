#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAXSTAR 2000	// 星星总数

struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// 初始化星星
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 640;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	star[i].color = RGB(star[i].color+rand()*255, star[i].color+rand()*255, star[i].color+rand()*255);
}

// 移动星星
void MoveStar(int i)
{
	// 擦掉原来的星星
	putpixel((int)star[i].x, star[i].y, 0);

	// 计算新位置
	star[i].x += star[i].step;
	if (star[i].x > 1024)	InitStar(i);

	// 画新星星
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

// 主函数
int main()
{
	srand((unsigned)time(NULL));	// 随机种子
	initgraph(1024, 640,0);			// 创建绘图窗口
	movewindow((1960-1024)/4,(1080-640)/4);
	// 初始化所有星星
	for (int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 1024;
	}

	// 绘制星空，按任意键退出
	while (!kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}

	closegraph();					// 关闭绘图窗口
	return 0;
}

