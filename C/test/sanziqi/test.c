#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//��Ϸ�˵�
void meau()
{
	printf("*************************************\n");
	printf("***********     1.play    ***********\n");
	printf("***********     0.over    ***********\n");
	printf("*************************************\n");
}

//������
void game()
{
	char ret;
	//�������̶�ά����
	char Board[ROW][COL];
	//��ʼ������
	IntialBoard(Board, ROW, COL);
	//��ӡ����
	PrintBoard(Board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(Board, ROW, COL);
		PrintBoard(Board, ROW, COL);
		//�ж���Ӯ
		ret=Is_Win(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		printf("\n");
		//��������
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
		printf("���Ӯ��\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ�֣�\n");
	}
}
int main()
{
	int choose = 0;
	srand((unsigned int)time(NULL));
	//��ʼ��Ϸ
	do
	{
		meau();
		printf("��ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (choose);
	return 0;
}