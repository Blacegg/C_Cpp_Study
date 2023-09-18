#define _CRT_SECURE_NO_WARNINGS 1

//通讯录
//功能：
// 1.通讯录中要存放1000个人的信息
// 每个人的信息包括：
// 名字+年龄+性别+电话+地址
// 2.增加人的信息
// 3.删除指定人的信息
// 4.修改指定人的信息
// 5.查找指定人的信息
// 6.排序通讯录的信息
//

#include"contact.h"

int main()
{
#if 0
	//创建通讯录
	Contact con;
	//初始化通讯录
	Init_Contact(&con);
	int input;
	do
	{
		//打印菜单
		meau();
		printf("请选择：");
		scanf("%d", &input);
	
		switch (input)
		{
		case ADD:
			//实现添加联系人
			AddPeople(&con);
			break;
		case DELETE:
			//实现删除联系人
			DeletePeople(&con);
			break;
		case MODIFY:
			//实现修改联系人
			ModifyPeople(&con);
			break;
		case SORT:
			//实现排序联系人
			SortPeople(&con);
			break;
		case EXIT:
			//退出
			printf("退出程序！\n");
			break;
		case SEARCH:
			//实现查找联系人
			SearchPeople(&con);
			break;
		case PRINT:
			//显示通讯录
			Print_Contact(&con);
			break;
		default:
			//输入错误
			printf("输入错误！请重新输入。\n");
			break;
		}
	} while (input);
#elif 1

	//创建通讯录
	Contact con;
	//初始化通讯录
	Init_Contact(&con);
	int input;
	do
	{
		//打印菜单
		meau();
		printf("请选择：");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			//实现添加联系人
			AddPeople(&con);
			break;
		case DELETE:
			//实现删除联系人
			DeletePeople(&con);
			break;
		case MODIFY:
			//实现修改联系人
			ModifyPeople(&con);
			break;
		case SORT:
			//实现排序联系人
			SortPeople(&con);
			break;
		case EXIT:
			//保存通讯录数据到文件
			SaveContect(&con);
			//销毁通讯录
			DestroyedContect(&con);
			//退出
			printf("退出程序！\n");
			break;
		case SEARCH:
			//实现查找联系人
			SearchPeople(&con);
			break;
		case PRINT:
			//显示通讯录
			Print_Contact(&con);
			break;
		default:
			//输入错误
			printf("输入错误！请重新输入。\n");
			break;
		}
	} while (input);
	free(con.People);

#endif

	return 0;
}