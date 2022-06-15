#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <malloc.h>
struct Worker
{
	int no; /*ְ����*/
	char name[10]; /*����*/
	int depno;    /*����*/
	int salary; /*����*/
};
struct LINK
{
	Worker w;
	LINK* next;
};
LINK* create()/*����ְ����Ϣ����*/
{
	LINK* p = (LINK*)malloc(sizeof(struct LINK));
	if (NULL != p)
	{
		p->next = NULL;
		return p;
	}
	printf("�ڴ治��!\n");
	return p;
}
void release(LINK* p)/*ɾ��ְ����Ϣ����*/
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
void message()//��ʾ��Ϣ
{
	system("cls");//���� 
	system("color 00a");//�ֵ���ɫ 
	printf("                         --�����룺��1��  ¼��ְ����Ϣ\n");
	printf("                         --�����룺��2��  ���ְ����Ϣ\n");
	printf("                         --�����룺��3��  ��ְ��������\n");
	printf("                         --�����룺��4��  �����ź�����\n");
	printf("                         --�����룺��5��  ������������\n");
	printf("                         --�����룺��6��  ɾ��ָ��ְ������Ϣ\n");
	printf("                         --�����룺��7��  ɾ��ְ���ļ��е�ȫ����¼ \n");
	printf("		         --�����룺��8��  ����\n");
	//printf("		         --�����룺��9��  ��ȡ��������\n");
	printf("                         --�����룺��-1�� �˳�\n");
}
void savefile(LINK* p)//��ְ�����������ݴ��������ļ�
{
	LINK* temp = p->next;
	int n=0;
	FILE* file;
	if ((file = fopen("empt.dat", "wb")) == NULL)
	{
		printf("  ��ʾ���޷������ļ�empt.dat");
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
		printf("  ��ʾ: %d��ְ����¼д��empt.dat�ļ�\n", n);
	}
	else
	{
		printf("  ��ʾ����ְ����¼д��\n");
	}
}
bool addinformation(LINK* p)//�����Ϣ
{
	LINK* temp;
	temp = (LINK*)malloc(sizeof(LINK));
	temp->next = NULL;
	if (NULL == temp)
	{
		printf("¼��ʧ����ʾ���ڴ治��\n");
		return false;
	}
	printf("������ְ����(����)��");
	scanf("%d", &temp->w.no);
	LINK* head = temp->next;
	while (head!=NULL)
	{
		if (head->w.no == temp->w.no)
		{
			free(temp);
			printf("¼��ʧ����ʾ����ְ�����Ѿ�����!\n");
				return false;
		}
		head = head->next;
	}
	printf("������ְ������(����)��");
	scanf("%s", &temp->w.name);
	printf("������ְ�����ź�(����)��");
	scanf("%d", &temp->w.depno);
	printf("������ְ��������(����)��");
	scanf("%d", &temp->w.salary);
	while (p->next!=NULL)
	{
		p = p->next;
	}
	p->next = temp;//β�巨
	printf("����ɹ�\n");
	return true;
}
void nopai(LINK* head)//����������
{
	LINK* pre, * p, * tail, * temp,*temp1;
	tail = NULL;
	temp1 = head;
	pre = head;
	while ((temp1->next->next) != tail)//�ڵ㽻����ð������
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
				p = pre->next;  //p����һ���ڵ� 
			}
			p = p->next;  //p��ǰ��һ���ڵ� 
			pre = pre->next;
		}
		tail = p;
	}
	head = temp1;
}
void depnopai(LINK* head)//����������
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
				p = pre->next;  //p����һ���ڵ� 
			}
			p = p->next;  //p��ǰ��һ���ڵ� 
			pre = pre->next;
		}
		tail = p;
	}
}
void salarypai(LINK* head)//��н������
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
				p = pre->next;  //p����һ���ڵ� 
			}
			p = p->next;  //p��ǰ��һ���ڵ� 
			pre = pre->next;
		}
		tail = p;
	}
}
void show(LINK* p)//��ӡ��Ϣ
{
	LINK* head;
	head = p;
	message();
	printf("���ְ����Ϣ\n");
	printf("ְ����\t����\t���ź�\t����\t\n");
	while (NULL != head->next)
	{
		printf("%d\t%s\t%d\t%d\t\n",
			head->next->w.no, head->next->w.name, head->next->w.depno, head->next->w.salary);
		head = head->next;
	}
	printf("��ʾ���!\n");
}
int del(LINK* head, int no)//ɾ��һ��ְ����Ϣ
{
	message();
	printf("������ɾ��ְ����Ϣ\n");
	while (head->next!=NULL)
	{
		if (head->next->w.no == no)
		{
			LINK* temp;
			temp = head->next;
			temp->next = NULL;
			head->next = head->next->next;
			free(temp);
			printf("ɾ���ɹ�");
			return true;
		}
		head = head->next;
	}
	printf("û���������ְ����!\n");
	return false;
}
void delall(LINK *head)//ɾ��ȫ����Ϣ
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
void add(LINK* p, Worker n)//��ӽڵ�
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
void readfile(LINK*&head)//�ļ���ȡ
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
			printf("���Ѵ洢����\n");
			return;
		}
		else
		{
			rewind(file);
		}
		while (!feof(file))//��ṹ���ȡ
		{
			fread(&p, sizeof(struct Worker), 1, file);
			if(!feof(file))//ȥ��ĩβ�ظ�����
			add(temp, p);
			n++;
		}
		//while (temp->next->next!=NULL)//ĩβ�ظ������޸�����ʹ�ø��ѷ����޸�
		//{
		//	temp = temp->next;
		//}
		//temp->next = NULL;
		show(temp);
		printf("��ȡ�ɹ�%d", n-1);
	}
	else
	{
		printf("���Ѵ洢����");
		exit(0);
	}
	fclose(file);
}
int main()
{
	int cmd = 0;
	int no;//����
	char name[4];//����
	LINK* pworker;
	if (!(pworker = create()))
	{
		exit(0);/*�������ְ����Ϣ�����ͷʧ�����������*/
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
			printf("��ְ�������гɹ�!\n");
			break;
		case 4:
			depnopai(pworker);
			show(pworker);
			printf("�����ź����гɹ�!\n");
			break;
		case 5:
			salarypai(pworker);
			show(pworker);
			printf("���������гɹ�!\n");
			break;
		case 6:
			show(pworker);
			printf("������Ҫɾ����ְ���ţ�");
			scanf("%d", &no);
			del(pworker, no);
			show(pworker);
			break;
		case 7:
			delall(pworker);
			show(pworker);
			printf("�Ѿ�ɾ��ȫ����¼!");
			break;
		case 8:
		default:
			message();
		}
		printf("����������������֣�\n");
		scanf("%d", &cmd);/*��������*/
	}
	savefile(pworker);
	//release(pworker);
	return 0;
}