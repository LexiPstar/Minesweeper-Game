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
	char mine[ROWS][COLS] = { 0 };//存放布置好雷的信息
	char show[ROWS][COLS] = { 0 };//玩家操作区域和可见提示区域,即排查雷的信息
	//初始化数组的内容为指定内容
	//mine数组没有雷的时候，都为'0'
	InitBoard(mine, ROWS, COLS,'0');
	//show数组没有雷的时候，都为'*'
	InitBoard(show, ROWS, COLS,'*');
	
	//设置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
scan:	printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("请重新选择！\n");
			goto scan;
		}

	} while (input);
	return 0;
}