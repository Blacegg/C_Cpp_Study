#define _CRT_SECURE_NO_WARNINGS 1

//ͨѶ¼
//���ܣ�
// 1.ͨѶ¼��Ҫ���1000���˵���Ϣ
// ÿ���˵���Ϣ������
// ����+����+�Ա�+�绰+��ַ
// 2.�����˵���Ϣ
// 3.ɾ��ָ���˵���Ϣ
// 4.�޸�ָ���˵���Ϣ
// 5.����ָ���˵���Ϣ
// 6.����ͨѶ¼����Ϣ
//

#include"contact.h"

int main()
{
#if 0
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	Init_Contact(&con);
	int input;
	do
	{
		//��ӡ�˵�
		meau();
		printf("��ѡ��");
		scanf("%d", &input);
	
		switch (input)
		{
		case ADD:
			//ʵ�������ϵ��
			AddPeople(&con);
			break;
		case DELETE:
			//ʵ��ɾ����ϵ��
			DeletePeople(&con);
			break;
		case MODIFY:
			//ʵ���޸���ϵ��
			ModifyPeople(&con);
			break;
		case SORT:
			//ʵ��������ϵ��
			SortPeople(&con);
			break;
		case EXIT:
			//�˳�
			printf("�˳�����\n");
			break;
		case SEARCH:
			//ʵ�ֲ�����ϵ��
			SearchPeople(&con);
			break;
		case PRINT:
			//��ʾͨѶ¼
			Print_Contact(&con);
			break;
		default:
			//�������
			printf("����������������롣\n");
			break;
		}
	} while (input);
#elif 1

	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	Init_Contact(&con);
	int input;
	do
	{
		//��ӡ�˵�
		meau();
		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			//ʵ�������ϵ��
			AddPeople(&con);
			break;
		case DELETE:
			//ʵ��ɾ����ϵ��
			DeletePeople(&con);
			break;
		case MODIFY:
			//ʵ���޸���ϵ��
			ModifyPeople(&con);
			break;
		case SORT:
			//ʵ��������ϵ��
			SortPeople(&con);
			break;
		case EXIT:
			//����ͨѶ¼���ݵ��ļ�
			SaveContect(&con);
			//����ͨѶ¼
			DestroyedContect(&con);
			//�˳�
			printf("�˳�����\n");
			break;
		case SEARCH:
			//ʵ�ֲ�����ϵ��
			SearchPeople(&con);
			break;
		case PRINT:
			//��ʾͨѶ¼
			Print_Contact(&con);
			break;
		default:
			//�������
			printf("����������������롣\n");
			break;
		}
	} while (input);
	free(con.People);

#endif

	return 0;
}