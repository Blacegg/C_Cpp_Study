#pragma 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�������
#define ROW 3
#define COL 3

//��������

//���̳�ʼ������
void IntialBoard(char Board[ROW][COL], int row, int col);
//��ӡ���̺���
void PrintBoard(char Board[ROW][COL], int row, int col);
//����ƶ�
void PlayerMove(char Board[ROW][COL], int row, int col);
//�����ƶ�
void ComputerMove(char Board[ROW][COL], int row, int col);
//�жϺ���
char Is_Win(char Board[ROW][COL], int row, int col);