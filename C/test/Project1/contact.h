#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define    MAX_NAME     20
#define    MAX_TEL      20
#define    MAX_ADDR     30
#define    MAX_SEX      10

#define    MAX          1000

#define    IN           3
#define    SUM          2


//������ϵ�˵���Ϣ�ṹ��
typedef struct Peopleinformation
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}Peopleinformation;

////����ͨѶ¼�ṹ��
////��̬
//typedef struct Contact
//{
//	Peopleinformation People[MAX];
//	int num;
//}Contact;

//��̬
typedef struct Contact
{
	Peopleinformation* People;
	int num;
	int capacity;
}Contact;

//ö��ѡ��
enum Option
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SEARCH,
	SORT,
	PRINT
};


//��������

//�˵�����
void meau();

//�����ϵ�˵ĺ���
void AddPeople(Contact* add);

//��ʼ��ͨѶ¼
void Init_Contact(Contact* init_con);

//ɾ����ϵ��
void DeletePeople(Contact* del);

//��ʾͨѶ¼
void Print_Contact(const Contact* pri);

//ʵ���޸���ϵ��
void ModifyPeople(Contact* mod);

//ʵ��������ϵ��
void SortPeople(Contact* sort);

//ʵ�ֲ�����ϵ��
void SearchPeople(Contact* search);

//����ͨѶ¼
void DestroyedContect(Contact* Destroy);

//����ͨѶ¼���ݵ��ļ�
void SaveContect(Contact* Save);

//���ļ��ж�ȡͨѶ¼
void ReadContect(Contact* Read);

//���ݺ���
void ExpansionContect(Contact* Expension);