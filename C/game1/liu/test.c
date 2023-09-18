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
	//�������ݣ���ά����
	char board[ROW][COL];
	//��ʼ������-��ʼ���ո�
	initboard(board, ROW, COL);
	//��ӡһ������
	displayboard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�������
		playmove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�ж����ʤ��
		ret = winner(board, ROW, COL);
		if (ret != 'C')//C ��Ϸ����  Qƽ��
			break;
		//��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�жϵ���ʤ��
		ret = winner(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf(" ƽ��\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;
		}

	} while (input);
	return 0;

}