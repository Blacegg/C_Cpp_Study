#pragma once

//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//符号的定义
#define ROW 3
#define COL 3


//函数的声明


//初始化棋盘
void initboard(char board[ROW][COL], int row, int col);
//打印棋盘
void displayboard(char board[ROW][COL], int row, int col);
//玩家下棋
void playmove(char board[ROW][COL], int row, int col);
//电脑下棋
void computermove(char board[ROW][COL], int row, int col);
//判断胜负
char winner(char board[ROW][COL], int row, int col);