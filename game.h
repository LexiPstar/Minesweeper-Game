#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define COL 9
#define ROW 9
#define COLS COL+2  //定义用大写，形参时候用小写区分
#define ROWS ROW+2
#define BOMN_COUNT 10


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//用一样会导致冲突

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);