#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//根据传参set初始化
		}		
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n");
	printf("------扫雷游戏-----\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------扫雷游戏-----\n");
	printf("\n");
}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = BOMN_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	//return
	//	board[x - 1][y - 1] +
	//	board[x - 1][y    ] +
	//	board[x - 1][y + 1] +
	//	board[x    ][y - 1] +
	//	board[x    ][y - 1] +
	//	board[x    ][y + 1] +
	//	board[x + 1][y - 1] +
	//	board[x + 1][y + 1] - 8 * '0';
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			count++;
		}
	}
	return count - 9 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0; 
	int y = 0;
	while (1)
	{	
		printf("请输入排查坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{ 
			//如果是雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else //不是雷
			{
				//统计mine数组中（x，y）坐标周围一格内炸弹总个数
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//转换成字符
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标非法，请重新输入坐标！\n");
		}
	}
}