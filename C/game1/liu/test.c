#define _CRT_SECURE_NO_WARNINGS 1
#include"game1.h"

void menu()
{
	printf("+++++++++++++++++++++++++++\n");
	printf("+++++++  1 play +++++++++++\n");
	printf("+++++++  0.exit +++++++++++\n");
	printf("+++++++++++++++++++++++++++\n");
}

void game()
{
	//储存数据，二维数组
	char board[ROW][COL];
	//初始化棋盘-初始化空格
	initboard(board, ROW, COL);
	//打印一下棋盘
	displayboard(board, ROW, COL);
	char ret = 0;//接收游戏状态
	while (1)
	{
		//玩家下棋
		playmove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断玩家胜负
		ret = winner(board, ROW, COL);
		if (ret != 'C')//C 游戏继续  Q平局
			break;
		//电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断电脑胜负
		ret = winner(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf(" 平局\n");
	}
	displayboard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择：");
			break;
		}

	} while (input);
	return 0;

}