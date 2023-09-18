#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//���̳�ʼ��
void IntialBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0 ; i < row ; i++)
	{
		for (j = 0 ; j < col ; j++)
		{
			Board[i][j] = ' ';
		}
	}
}
//��ӡ����
void PrintBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (k = 0; k < row; k++)
	{
		for (i = 0; i < col; i++)
		{
			printf(" %c ",Board[k][i]);
			if (i < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");//��ӡ��
		if (k < row - 1)
		{
			for (j = 0; j < row; j++)
			{
				printf("---");
				if (j < row - 1)
				{
					printf("|");
				}
			}
			printf("\n");//��ӡ��
		}
	}
}


//����ƶ�
void PlayerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������ӣ����������꣺");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���Ӵ�������������\n");
			}
		}
		else
		{
			printf("�������������������������\n");
		}
	}
}



//�����ƶ�
void ComputerMove(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (Board[x][y] == ' ')
		{
			Board[x][y] = '#';
			break;
		}
	}
}

//�жϺ���
//1.���Ӯ��*
//2.����Ӯ��#
//3.ƽ�֣�Q
//4.������C
char Is_Win(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	char j = ' ';
	//�ж���
	for (i = 0; i < row; i++)
	{
		int a = strcmp(&Board[i][0], &Board[i][1]);
		int b = strcmp(&Board[i][2], &Board[i][1]);
		int c = strcmp(&Board[i][0], &j);
		if (!a && !b && c)
		{
			return Board[i][0];
			break;
		}
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		int a = strcmp(&Board[0][i], &Board[1][i]);
		int b = strcmp(&Board[1][i], &Board[2][i]);
		int c = strcmp(&Board[1][i], &j);
		if (!a && !b && c)
		{
			return Board[1][i];
			break;
		}
	}
	//�ж϶Խ���
	int a = strcmp(&Board[0][0], &Board[1][1]);
	int b = strcmp(&Board[1][1], &Board[2][2]);
	int c = strcmp(&Board[1][1], &j);
	if (!a && !b && c)
	{
		return Board[1][1];
	}
	 a = strcmp(&Board[2][0], &Board[1][1]);
	 b = strcmp(&Board[1][1], &Board[0][2]);
	 c = strcmp(&Board[1][1], &j);
	if (!a && !b && c)
	{
		return Board[1][1];
	}

	//int j = 0;
	////�ж���
	//for (i = 0; i < row; i++)
	//{
	//	if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ')
	//	{
	//		return Board[i][0];
	//		break;
	//	}
	//}
	////�ж���
	//for (i = 0; i < col; i++)
	//{
	//	if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[1][i] != ' ')
	//	{
	//		return Board[1][i];
	//		break;
	//	}
	//}
	////�ж϶Խ���
	//if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
	//{
	//	return Board[1][1];
	//}
	//if (Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2] && Board[1][1] != ' ')
	//{
	//	return Board[1][1];
	//}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
			{
				return 'C';
			}
		}
	}
	return 'Q';
}