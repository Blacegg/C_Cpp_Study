#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//菜单
void meau()
{
	printf("***************************************\n");
	printf("***********      1.play    ************\n");
	printf("***********      0.over    ************\n");
	printf("***************************************\n");
}


//扫雷
void game()
{
	//设置存储棋盘
	char ShowBoard[ROWS][COLS];
	char NumBoard[ROWS][COLS];
	//棋盘初始化
	IntialBoard(NumBoard, ROWS, COLS, '0');//初始化数字棋盘
	IntialBoard(ShowBoard, ROWS, COLS, '*');//初始化显示棋盘
	//打印棋盘
	PrintBoard(NumBoard, ROW, COL);
	PrintBoard(ShowBoard, ROW, COL);

}


int main()
{
	int input = 0;
	//打印菜单
	do
	{
		//打印菜单
		meau();
		printf("请选择：");
		scanf("%d", &input);
		if (input == 1)
		{
			game();//扫雷
		}
		else if (input == 0)
		{
			printf("游戏结束！\n");
		}
		else
		{
			printf("输入错误，请重新输入！");
		}
	} while (input);
	return 0;
}