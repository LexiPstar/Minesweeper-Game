#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define COL 9
#define ROW 9
#define COLS COL+2  //�����ô�д���β�ʱ����Сд����
#define ROWS ROW+2
#define BOMN_COUNT 10


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//��һ���ᵼ�³�ͻ

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);