#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//游戏菜单
void meau()
{
	printf("*************************************\n");
	printf("***********     1.play    ***********\n");
	printf("***********     0.over    ***********\n");
	printf("*************************************\n");
}

//三子棋
void game()
{
	char ret;
	//定义棋盘二维数组
	char Board[ROW][COL];
	//初始化棋盘
	IntialBoard(Board, ROW, COL);
	//打印棋盘
	PrintBoard(Board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(Board, ROW, COL);
		PrintBoard(Board, ROW, COL);
		//判断输赢
		ret=Is_Win(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		printf("\n");
		//电脑下棋
		ComputerMove(Board, ROW, COL);
		PrintBoard(Board, ROW, COL);
		ret = Is_Win(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	if (ret == 'Q')
	{
		printf("平局！\n");
	}
}
int main()
{
	int choose = 0;
	srand((unsigned int)time(NULL));
	//开始游戏
	do
	{
		meau();
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (choose);
	return 0;
}