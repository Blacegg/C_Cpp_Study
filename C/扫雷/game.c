#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//��ʼ������
void IntialBoard(char Board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			Board[i][j] = set;
		}
	}
}

//��ӡ���̺���
void PrintBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n---------------ɨ����Ϸ----------------\n");
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c ", Board[row][col]);
		}
		printf("\n");
	}
	printf("\n---------------ɨ����Ϸ----------------\n");
}