#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("******** 1.play *********\n");
	printf("******** 0.exit *********\n");
	printf("*************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//��Ų��ú��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//��Ҳ�������Ϳɼ���ʾ����,���Ų��׵���Ϣ
	//��ʼ�����������Ϊָ������
	//mine����û���׵�ʱ�򣬶�Ϊ'0'
	InitBoard(mine, ROWS, COLS,'0');
	//show����û���׵�ʱ�򣬶�Ϊ'*'
	InitBoard(show, ROWS, COLS,'*');
	
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
scan:	printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("������ѡ��\n");
			goto scan;
		}

	} while (input);
	return 0;
}