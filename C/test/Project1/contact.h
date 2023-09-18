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


//定义联系人的信息结构体
typedef struct Peopleinformation
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}Peopleinformation;

////创建通讯录结构体
////静态
//typedef struct Contact
//{
//	Peopleinformation People[MAX];
//	int num;
//}Contact;

//动态
typedef struct Contact
{
	Peopleinformation* People;
	int num;
	int capacity;
}Contact;

//枚举选项
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


//函数声明

//菜单函数
void meau();

//添加联系人的函数
void AddPeople(Contact* add);

//初始化通讯录
void Init_Contact(Contact* init_con);

//删除联系人
void DeletePeople(Contact* del);

//显示通讯录
void Print_Contact(const Contact* pri);

//实现修改联系人
void ModifyPeople(Contact* mod);

//实现排序联系人
void SortPeople(Contact* sort);

//实现查找联系人
void SearchPeople(Contact* search);

//销毁通讯录
void DestroyedContect(Contact* Destroy);

//保存通讯录数据到文件
void SaveContect(Contact* Save);

//从文件中读取通讯录
void ReadContect(Contact* Read);

//扩容函数
void ExpansionContect(Contact* Expension);