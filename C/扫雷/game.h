#pragma once
#include<stdio.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//��������

//���̳�ʼ������
void IntialBoard(char Board[ROWS][COLS], int rows, int cols, char set);

//���̴�ӡ����
void PrintBoard(char Board[ROWS][COLS], int row, int col);
