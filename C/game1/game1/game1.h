#pragma once

//ͷ�ļ��İ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//���ŵĶ���
#define ROW 3
#define COL 3


//����������


//��ʼ������
void initboard(char board[ROW][COL], int row, int col);
//��ӡ����
void displayboard(char board[ROW][COL], int row, int col);
//�������
void playmove(char board[ROW][COL], int row, int col);
//��������
void computermove(char board[ROW][COL], int row, int col);
//�ж�ʤ��
char winner(char board[ROW][COL], int row, int col);