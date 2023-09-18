#pragma once
#include<stdio.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//函数声明

//棋盘初始化函数
void IntialBoard(char Board[ROWS][COLS], int rows, int cols, char set);

//棋盘打印函数
void PrintBoard(char Board[ROWS][COLS], int row, int col);
