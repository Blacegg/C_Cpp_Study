#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//�˵�
void meau()
{
	printf("***************************************\n");
	printf("***********      1.play    ************\n");
	printf("***********      0.over    ************\n");
	printf("***************************************\n");
}


//ɨ��
void game()
{
	//���ô洢����
	char ShowBoard[ROWS][COLS];
	char NumBoard[ROWS][COLS];
	//���̳�ʼ��
	IntialBoard(NumBoard, ROWS, COLS, '0');//��ʼ����������
	IntialBoard(ShowBoard, ROWS, COLS, '*');//��ʼ����ʾ����
	//��ӡ����
	PrintBoard(NumBoard, ROW, COL);
	PrintBoard(ShowBoard, ROW, COL);

}


int main()
{
	int input = 0;
	//��ӡ�˵�
	do
	{
		//��ӡ�˵�
		meau();
		printf("��ѡ��");
		scanf("%d", &input);
		if (input == 1)
		{
			game();//ɨ��
		}
		else if (input == 0)
		{
			printf("��Ϸ������\n");
		}
		else
		{
			printf("����������������룡");
		}
	} while (input);
	return 0;
}