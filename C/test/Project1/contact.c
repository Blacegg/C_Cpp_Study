#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//�˵�����
void meau()
{
	printf("**********************************************\n");
	printf("**********   1.ADD       2.DELETE   **********\n");
	printf("**********   3.MODIFY    4.SEARCH   **********\n");
	printf("**********   5.SORT      6.PRINT    **********\n");
	printf("**********   0.EXIT                 **********\n");
	printf("**********************************************\n");
}

//�����ϵ�˵ĺ���
////��̬
//void AddPeople(Contact* add)
//{
//   //�ж�ͨѶ¼���
//	if (add->num == MAX)
//	{
//		printf("ͨѶ¼���������������ϵ��!\n");
//		return;
//	}
//    //�����ϵ��
//	printf("��������ϵ�˵�����:");
//	scanf("%s", add->People[add->num].name);
//	printf("��������ϵ�˵�����:");
//	scanf("%d", &add->People[add->num].age);
//	printf("��������ϵ�˵��Ա�:");
//	scanf("%s", add->People[add->num].sex);
//	printf("��������ϵ�˵ĵ绰:");
//	scanf("%s", add->People[add->num].tel);
//	printf("��������ϵ�˵ĵ�ַ:");
//	scanf("%s", add->People[add->num].addr);
//
//	add->num++;
//	printf("��ӳɹ�!\n");
//}

//���ݺ���
void ExpansionContect(Contact* Expension)
{
	if (Expension->num == Expension->capacity)
	{
		Peopleinformation* q = (Peopleinformation*)realloc(Expension->People, (Expension->capacity + SUM) * sizeof(Peopleinformation));
		if (q != NULL)
		{
			Expension->People = q;
			Expension->capacity += SUM;
			printf("���ݳɹ���\n");
		}
		else
		{
			printf("���ٿռ����\n");
			return;
		}
	}
}

//��̬
void AddPeople(Contact* add)
{
	ExpansionContect(add);
	//�ж�ͨѶ¼���
	if (add->num == MAX)
	{
		printf("ͨѶ¼���������������ϵ��!\n");
		return;
	}
	//�����ϵ��
	printf("��������ϵ�˵�����:");
	scanf("%s", add->People[add->num].name);
	printf("��������ϵ�˵�����:");
	scanf("%d", &add->People[add->num].age);
	printf("��������ϵ�˵��Ա�:");
	scanf("%s", add->People[add->num].sex);
	printf("��������ϵ�˵ĵ绰:");
	scanf("%s", add->People[add->num].tel);
	printf("��������ϵ�˵ĵ�ַ:");
	scanf("%s", add->People[add->num].addr);

	add->num++;
	printf("��ӳɹ�!\n");
}

////��ʼ��ͨѶ¼
////��̬
//void Init_Contact(Contact* init_con)
//{
//	init_con->num = 0;
//	memset(init_con->People, 0, sizeof(init_con->People));
//}

//���ļ��ж�ȡͨѶ¼
void ReadContect(Contact* Read)
{
	//���ļ�
	FILE* pc = fopen("Contect.dat", "r");
	if (pc == NULL)
	{
		perror("fopen:");
		return;
	}
	//���ļ�
	Peopleinformation tem = { 0 };
	while (fread(&tem, sizeof(Peopleinformation), 1, pc))
	{
		ExpansionContect(Read);
		Read->People[Read->num] = tem;
		Read->num++;
	}
	//�ر��ļ�
	fclose(pc);
	pc = NULL;
}

//��̬
void Init_Contact(Contact* init_con)
{
	init_con->People = malloc(IN * sizeof(Peopleinformation));
	init_con->num = 0;
	init_con->capacity = IN;
	memset(init_con->People, 0, sizeof(init_con->People));

	//���ļ��ж�ȡͨѶ¼
	ReadContect(init_con);
}

//�����ֲ�����ϵ��
static int Findbyname(Contact* del,char* name)
{
	int i = 0;
	for (i = 0; i < del->num; i++)
	{
		if (strcmp(del->People[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void DeletePeople(Contact* del)
{
	//ͨѶ¼״̬
	if (del->num == 0)
	{
		printf("ͨѶ¼�ѿգ�����Ҫɾ����ϵ�ˣ�\n");
		return;
	}

    //����Ҫɾ������ϵ�˵�����
	char name[MAX_NAME];
	printf("������Ҫɾ������ϵ������:");
	scanf("%s", name);
	int pos = 0;
	pos = Findbyname(del, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����!\n");
		return;
	}

	//ɾ����ϵ��
	for (; pos < del->num - 1; pos++)
	{
		del->People[pos] = del->People[pos + 1];
	}
	del->num--;
	printf("ɾ���ɹ�!\n");
}

//��ʾͨѶ¼
void Print_Contact(const Contact* pri)
{
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	int i = 0;
	for (i = 0; i < pri->num; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-20s\n",
			pri->People[i].name,
			pri->People[i].age,
			pri->People[i].sex,
			pri->People[i].tel,
			pri->People[i].addr);
	}
}

//ʵ���޸���ϵ��
void ModifyPeople(Contact* mod)
{
	//ͨѶ¼״̬
	if (mod->num == 0)
	{
		printf("ͨѶ¼�ѿգ�����ϵ�˿��޸ģ�\n");
		return;
	}

	//����Ҫ�޸ĵ���ϵ��
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������:");
	scanf("%s", name);
	int pos = 0;
	pos = Findbyname(mod, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����!\n");
		return;
	}

	//�޸���ϵ����Ϣ
	printf("��������ϵ�˵�����:");
	scanf("%s", mod->People[pos].name);
	printf("��������ϵ�˵�����:");
	scanf("%d", &mod->People[pos].age);
	printf("��������ϵ�˵��Ա�:");
	scanf("%s", mod->People[pos].sex);
	printf("��������ϵ�˵ĵ绰:");
	scanf("%s", mod->People[pos].tel);
	printf("��������ϵ�˵ĵ�ַ:");
	scanf("%s", mod->People[pos].addr);

	printf("�޸ĳɹ���\n");
}

//ʵ��������ϵ��
void SortPeople(Contact* sort)
{
	//ͨѶ¼״̬
	if (sort->num == 0)
	{
		printf("ͨѶ¼�ѿգ�����ϵ�˿�����\n");
		return;
	}

	//����������
	Peopleinformation p;
	int i = 0;
	int j = 0;
	for (j = sort->num-1; j >= 0; j--)
	{
		for (i = 0; i < sort->num-1; i++)
		{
			if (sort->People[i].age > sort->People[i + 1].age)
			{
				p = sort->People[i];
				sort->People[i] = sort->People[i + 1];
				sort->People[i + 1] = p;
			}
		}
	}
}

//ʵ�ֲ�����ϵ��
void SearchPeople(Contact* search)
{
	//ͨѶ¼״̬
	if (search->num == 0)
	{
		printf("ͨѶ¼�ѿգ�����ϵ�˿ɲ��ң�\n");
		return;
	}

	//������ϵ��
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������:");
	scanf("%s", name);
	int pos = 0;
	pos = Findbyname(search, name);
	if (pos == -1)
	{
		printf("���˲�����!\n");
		return;
	}
	printf("���ҵ��ˣ�\n");
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-10s\t%-5d\t%-5s\t%-15s\t%-20s\n",
		search->People[pos].name,
		search->People[pos].age,
		search->People[pos].sex,
		search->People[pos].tel,
		search->People[pos].addr);
}

//����ͨѶ¼
void DestroyedContect(Contact* Destroy)
{
	Destroy->num = 0;
	Destroy->capacity = 0;
	memset(Destroy->People, 0, sizeof(Destroy->People));
}

//����ͨѶ¼���ݵ��ļ�
void SaveContect(Contact* Save)
{
	//���ļ�
	FILE* pc = fopen("Contect.dat", "w");
	if (pc == NULL)
	{
		perror("fopen:");
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < Save->num; i++)
	{
		fwrite(Save->People + i, sizeof(Peopleinformation), 1, pc);
	}
	//�ر��ļ�
	fclose(pc);
	pc=NULL;
}