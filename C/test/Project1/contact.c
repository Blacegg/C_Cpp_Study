#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//菜单函数
void meau()
{
	printf("**********************************************\n");
	printf("**********   1.ADD       2.DELETE   **********\n");
	printf("**********   3.MODIFY    4.SEARCH   **********\n");
	printf("**********   5.SORT      6.PRINT    **********\n");
	printf("**********   0.EXIT                 **********\n");
	printf("**********************************************\n");
}

//添加联系人的函数
////静态
//void AddPeople(Contact* add)
//{
//   //判断通讯录情况
//	if (add->num == MAX)
//	{
//		printf("通讯录已满，不能添加联系人!\n");
//		return;
//	}
//    //添加联系人
//	printf("请输入联系人的姓名:");
//	scanf("%s", add->People[add->num].name);
//	printf("请输入联系人的年龄:");
//	scanf("%d", &add->People[add->num].age);
//	printf("请输入联系人的性别:");
//	scanf("%s", add->People[add->num].sex);
//	printf("请输入联系人的电话:");
//	scanf("%s", add->People[add->num].tel);
//	printf("请输入联系人的地址:");
//	scanf("%s", add->People[add->num].addr);
//
//	add->num++;
//	printf("添加成功!\n");
//}

//扩容函数
void ExpansionContect(Contact* Expension)
{
	if (Expension->num == Expension->capacity)
	{
		Peopleinformation* q = (Peopleinformation*)realloc(Expension->People, (Expension->capacity + SUM) * sizeof(Peopleinformation));
		if (q != NULL)
		{
			Expension->People = q;
			Expension->capacity += SUM;
			printf("扩容成功！\n");
		}
		else
		{
			printf("开辟空间出错！\n");
			return;
		}
	}
}

//动态
void AddPeople(Contact* add)
{
	ExpansionContect(add);
	//判断通讯录情况
	if (add->num == MAX)
	{
		printf("通讯录已满，不能添加联系人!\n");
		return;
	}
	//添加联系人
	printf("请输入联系人的姓名:");
	scanf("%s", add->People[add->num].name);
	printf("请输入联系人的年龄:");
	scanf("%d", &add->People[add->num].age);
	printf("请输入联系人的性别:");
	scanf("%s", add->People[add->num].sex);
	printf("请输入联系人的电话:");
	scanf("%s", add->People[add->num].tel);
	printf("请输入联系人的地址:");
	scanf("%s", add->People[add->num].addr);

	add->num++;
	printf("添加成功!\n");
}

////初始化通讯录
////静态
//void Init_Contact(Contact* init_con)
//{
//	init_con->num = 0;
//	memset(init_con->People, 0, sizeof(init_con->People));
//}

//从文件中读取通讯录
void ReadContect(Contact* Read)
{
	//打开文件
	FILE* pc = fopen("Contect.dat", "r");
	if (pc == NULL)
	{
		perror("fopen:");
		return;
	}
	//读文件
	Peopleinformation tem = { 0 };
	while (fread(&tem, sizeof(Peopleinformation), 1, pc))
	{
		ExpansionContect(Read);
		Read->People[Read->num] = tem;
		Read->num++;
	}
	//关闭文件
	fclose(pc);
	pc = NULL;
}

//动态
void Init_Contact(Contact* init_con)
{
	init_con->People = malloc(IN * sizeof(Peopleinformation));
	init_con->num = 0;
	init_con->capacity = IN;
	memset(init_con->People, 0, sizeof(init_con->People));

	//从文件中读取通讯录
	ReadContect(init_con);
}

//按名字查找联系人
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

//删除联系人
void DeletePeople(Contact* del)
{
	//通讯录状态
	if (del->num == 0)
	{
		printf("通讯录已空，不需要删除联系人！\n");
		return;
	}

    //查找要删除的联系人的姓名
	char name[MAX_NAME];
	printf("请输入要删除的联系人姓名:");
	scanf("%s", name);
	int pos = 0;
	pos = Findbyname(del, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在!\n");
		return;
	}

	//删除联系人
	for (; pos < del->num - 1; pos++)
	{
		del->People[pos] = del->People[pos + 1];
	}
	del->num--;
	printf("删除成功!\n");
}

//显示通讯录
void Print_Contact(const Contact* pri)
{
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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

//实现修改联系人
void ModifyPeople(Contact* mod)
{
	//通讯录状态
	if (mod->num == 0)
	{
		printf("通讯录已空，无联系人可修改！\n");
		return;
	}

	//查找要修改的联系人
	char name[MAX_NAME];
	printf("请输入要修改的联系人姓名:");
	scanf("%s", name);
	int pos = 0;
	pos = Findbyname(mod, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在!\n");
		return;
	}

	//修改联系人信息
	printf("请输入联系人的姓名:");
	scanf("%s", mod->People[pos].name);
	printf("请输入联系人的年龄:");
	scanf("%d", &mod->People[pos].age);
	printf("请输入联系人的性别:");
	scanf("%s", mod->People[pos].sex);
	printf("请输入联系人的电话:");
	scanf("%s", mod->People[pos].tel);
	printf("请输入联系人的地址:");
	scanf("%s", mod->People[pos].addr);

	printf("修改成功！\n");
}

//实现排序联系人
void SortPeople(Contact* sort)
{
	//通讯录状态
	if (sort->num == 0)
	{
		printf("通讯录已空，无联系人可排序！\n");
		return;
	}

	//按年龄排序
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

//实现查找联系人
void SearchPeople(Contact* search)
{
	//通讯录状态
	if (search->num == 0)
	{
		printf("通讯录已空，无联系人可查找！\n");
		return;
	}

	//查找联系人
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名:");
	scanf("%s", name);
	int pos = 0;
	pos = Findbyname(search, name);
	if (pos == -1)
	{
		printf("此人不存在!\n");
		return;
	}
	printf("查找到了！\n");
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-10s\t%-5d\t%-5s\t%-15s\t%-20s\n",
		search->People[pos].name,
		search->People[pos].age,
		search->People[pos].sex,
		search->People[pos].tel,
		search->People[pos].addr);
}

//销毁通讯录
void DestroyedContect(Contact* Destroy)
{
	Destroy->num = 0;
	Destroy->capacity = 0;
	memset(Destroy->People, 0, sizeof(Destroy->People));
}

//保存通讯录数据到文件
void SaveContect(Contact* Save)
{
	//打开文件
	FILE* pc = fopen("Contect.dat", "w");
	if (pc == NULL)
	{
		perror("fopen:");
	}
	//写文件
	int i = 0;
	for (i = 0; i < Save->num; i++)
	{
		fwrite(Save->People + i, sizeof(Peopleinformation), 1, pc);
	}
	//关闭文件
	fclose(pc);
	pc=NULL;
}