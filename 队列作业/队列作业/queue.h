#pragma once
#define maxsize 20
typedef struct
{
	char data[maxsize];
	int front, fear;
}SqQueue;
typedef struct
{
	char data[maxsize];
	int top;
}stack;