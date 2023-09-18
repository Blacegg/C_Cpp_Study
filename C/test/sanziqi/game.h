#pragma 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义变量
#define ROW 3
#define COL 3

//函数声明

//棋盘初始化函数
void IntialBoard(char Board[ROW][COL], int row, int col);
//打印棋盘函数
void PrintBoard(char Board[ROW][COL], int row, int col);
//玩家移动
void PlayerMove(char Board[ROW][COL], int row, int col);
//电脑移动
void ComputerMove(char Board[ROW][COL], int row, int col);
//判断函数
char Is_Win(char Board[ROW][COL], int row, int col);