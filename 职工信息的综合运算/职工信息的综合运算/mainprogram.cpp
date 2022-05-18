#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <malloc.h>
struct Worker
{
	int no; /*职工号*/
	char name[10]; /*姓名*/
	int depno;    /*部门*/
	int salary; /*工资*/
};
struct LINK
{
	Worker w;
	LINK* next;
};
LINK* create()/*创建职工信息链表*/
{
	LINK* p = (LINK*)malloc(sizeof(struct LINK));
	if (NULL != p)
	{
		p->next = NULL;
		return p;
	}
	printf("内存不足!\n");
	return p;
}
void release(LINK* p)/*删除职工信息链表*/
{
	LINK* q;
	while (p->next!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
}
void message()//显示信息
{
	system("cls");//清屏 
	system("color 00a");//字的颜色 
	printf("                         --请输入：【1】  录入职工信息\n");
	printf("                         --请输入：【2】  浏览职工信息\n");
	printf("                         --请输入：【3】  按职工号排序\n");
	printf("                         --请输入：【4】  按部门号排序\n");
	printf("                         --请输入：【5】  按工资数排序\n");
	printf("                         --请输入：【6】  删除指定职工号信息\n");
	printf("                         --请输入：【7】  删除职工文件中的全部记录 \n");
	printf("		         --请输入：【8】  清屏\n");
	//printf("		         --请输入：【9】  读取已有数据\n");
	printf("                         --请输入：【-1】 退出\n");
}
void savefile(LINK* p)//将职工单链表数据存入数据文件
{
	LINK* temp = p->next;
	int n=0;
	FILE* file;
	if ((file = fopen("empt.dat", "wb")) == NULL)
	{
		printf("  提示：无法创建文件empt.dat");
		return;
	}
	while (temp!=NULL)
	{
		fwrite(&temp->w, sizeof(struct Worker),1,file );
		temp = temp->next;
		n++;
	}
	fclose(file);
	release(p);
	if (n > 0)
	{
		printf("  提示: %d个职工记录写入empt.dat文件\n", n);
	}
	else
	{
		printf("  提示：无职工记录写入\n");
	}
}
bool addinformation(LINK* p)//添加信息
{
	LINK* temp;
	temp = (LINK*)malloc(sizeof(LINK));
	temp->next = NULL;
	if (NULL == temp)
	{
		printf("录入失败提示：内存不足\n");
		return false;
	}
	printf("请输入职工号(数字)：");
	scanf("%d", &temp->w.no);
	LINK* head = temp->next;
	while (head!=NULL)
	{
		if (head->w.no == temp->w.no)
		{
			free(temp);
			printf("录入失败提示：此职工号已经存在!\n");
				return false;
		}
		head = head->next;
	}
	printf("请输入职工姓名(文字)：");
	scanf("%s", &temp->w.name);
	printf("请输入职工部门号(数字)：");
	scanf("%d", &temp->w.depno);
	printf("请输入职工工资数(数字)：");
	scanf("%d", &temp->w.salary);
	while (p->next!=NULL)
	{
		p = p->next;
	}
	p->next = temp;//尾插法
	printf("插入成功\n");
	return true;
}
void nopai(LINK* head)//按工号排序
{
	LINK* pre, * p, * tail, * temp,*temp1;
	tail = NULL;
	temp1 = head;
	pre = head;
	while ((temp1->next->next) != tail)//节点交换法冒泡排序
	{
		p = temp1->next;
		pre = temp1;
		while (p->next != tail)
		{
			if ((p->w.no) > (p->next->w.no))
			{
				pre->next = p->next;
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;  //p回退一个节点 
			}
			p = p->next;  //p再前进一个节点 
			pre = pre->next;
		}
		tail = p;
	}
	head = temp1;
}
void depnopai(LINK* head)//按部门排序
{
	LINK* pre, * p, * tail, * temp;
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail)
	{
		p = head->next;
		pre = head;
		while (p->next != tail)
		{
			if ((p->w.depno) > (p->next->w.depno))
			{
				pre->next = p->next;
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;  //p回退一个节点 
			}
			p = p->next;  //p再前进一个节点 
			pre = pre->next;
		}
		tail = p;
	}
}
void salarypai(LINK* head)//按薪资排序
{
	LINK* pre, * p, * tail, * temp;
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail)
	{
		p = head->next;
		pre = head;
		while (p->next != tail)
		{
			if ((p->w.salary) > (p->next->w.salary))
			{
				pre->next = p->next;
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;  //p回退一个节点 
			}
			p = p->next;  //p再前进一个节点 
			pre = pre->next;
		}
		tail = p;
	}
}
void show(LINK* p)//打印信息
{
	LINK* head;
	head = p;
	message();
	printf("浏览职工信息\n");
	printf("职工号\t姓名\t部门号\t工资\t\n");
	while (NULL != head->next)
	{
		printf("%d\t%s\t%d\t%d\t\n",
			head->next->w.no, head->next->w.name, head->next->w.depno, head->next->w.salary);
		head = head->next;
	}
	printf("显示完毕!\n");
}
int del(LINK* head, int no)//删除一个职工信息
{
	message();
	printf("按工号删除职工信息\n");
	while (head->next!=NULL)
	{
		if (head->next->w.no == no)
		{
			LINK* temp;
			temp = head->next;
			temp->next = NULL;
			head->next = head->next->next;
			free(temp);
			printf("删除成功");
			return true;
		}
		head = head->next;
	}
	printf("没有你输入的职工号!\n");
	return false;
}
void delall(LINK *head)//删除全部信息
{
	LINK* pre, * p;
	pre = head;
	p = pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
void add(LINK* p, Worker n)//添加节点
{
	LINK* temp;
	temp = (LINK*)malloc(sizeof(LINK));
	temp->next = NULL;
	temp->w = n;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
}
void readfile(LINK*&head)//文件读取
{
	LINK*temp;
	Worker p;
	FILE* file;
	int n=0;
	//head = create();
	temp = (LINK*)malloc(sizeof(LINK));
	head= temp;
	temp->next = NULL;
	char b;
	if ((file = fopen("empt.dat", "rb")) != NULL)
	{
		if (b = fgetc(file) == EOF)
		{
			printf("无已存储数据\n");
			return;
		}
		else
		{
			rewind(file);
		}
		while (!feof(file))//逐结构体读取
		{
			fread(&p, sizeof(struct Worker), 1, file);
			if(!feof(file))//去除末尾重复数据
			add(temp, p);
			n++;
		}
		//while (temp->next->next!=NULL)//末尾重复数据修复，已使用更佳方法修复
		//{
		//	temp = temp->next;
		//}
		//temp->next = NULL;
		show(temp);
		printf("读取成功%d", n-1);
	}
	else
	{
		printf("无已存储数据");
		exit(0);
	}
	fclose(file);
}
int main()
{
	int cmd = 0;
	int no;//工号
	char name[4];//名字
	LINK* pworker;
	if (!(pworker = create()))
	{
		exit(0);/*如果创建职工信息链表表头失败则结束程序*/
	}
	readfile(pworker);
	while (cmd != -1)
	{
		switch (cmd)
		{
		case 0:
			message();
			break;
		case 1:
			addinformation(pworker);
			break;
		case 2:
			show(pworker);
			break;
		case 3:
			nopai(pworker);
			show(pworker);
			printf("按职工号排列成功!\n");
			break;
		case 4:
			depnopai(pworker);
			show(pworker);
			printf("按部门号排列成功!\n");
			break;
		case 5:
			salarypai(pworker);
			show(pworker);
			printf("按工资排列成功!\n");
			break;
		case 6:
			show(pworker);
			printf("请输入要删除的职工号：");
			scanf("%d", &no);
			del(pworker, no);
			show(pworker);
			break;
		case 7:
			delall(pworker);
			show(pworker);
			printf("已经删除全部记录!");
			break;
		case 8:
		default:
			message();
		}
		printf("请输入操作命令数字：\n");
		scanf("%d", &cmd);/*接收命令*/
	}
	savefile(pworker);
	//release(pworker);
	return 0;
}