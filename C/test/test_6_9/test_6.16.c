#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////函数指针
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int (*pf)(int, int) = &ADD;//pf是一个函数指针
//	//int (*pf)(int, int) = ADD;//&ADD==ADD==pf
//	printf("%p\n", ADD);
//	printf("%p\n", &ADD);//两者意义数字都相同
//	//int ret = (*pf)(3, 5);//函数指针调用函数
//	//int ret = pf(3, 5);//函数指针调用函数,*是为了理解，没有实际的意义
//	//int ret = ADD(3, 5);//函数指针调用函数
//	//printf("%d\n", ret);
//	return 0;
//}


////代码解读
//int main()
//{
//	//代码1
//	(*(void (*)())0)();
//	//调用0地址处的函数
//	//该函数无参数，返回类型为void
//	//1.void(*)()--函数指针类型
//	//  void(*p)()--函数指针变量
//	//2.(void(*)())0--对0进行强制类型转化,转化为函数指针类型
//	//3.*(void(*)())0--对0地址进行了解引用操作
//	//4..(*(void(*)())0)()--调用0地址处的函数
//	return 0;
//}
////代码2
//void (*signal(int, void(*)(int)))(int);//函数声明
////等价于   void(*)(int)  signal(int,void(*)(int))
////函数signal的函数参数类型分别是int类型和void(*)(int)函数指针类型，返回类型是void(*)(int)
////但语法要求不能这样写，所以将函数放*一起
//// 
////对代码2进行简化，如下
////typedef void(*pfun_t)(int);--重新定义void(*)(int)函数指针类型为pfun_t
////pfun_t signal(int,void(*)(int));


//函数指针数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int(*pf1)(int, int) = Add;//定义函数指针变量pf1
//	int(*pf2)(int, int) = Sub;//定义函数指针变量pf2
//	int(*pfarr[2])(int, int) = { Add,Sub };//pfarr就是函数指针数组
//	return 0;
//}

////计算器
////1
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void meau()
//{
//	printf("*****************************************\n");
//	printf("**********   1.add     2.sub   **********\n");
//	printf("**********   3.mul     4.div   **********\n");
//	printf("**********      0.退出系统     **********\n");
//	printf("*****************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		meau();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 0:
//			printf("退出系统\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//		printf("\n\n");
//	} while (input);
//	return 0;
//}


////计算器
////2
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void meau()
//{
//	printf("*****************************************\n");
//	printf("**********   1.add     2.sub   **********\n");
//	printf("**********   3.mul     4.div   **********\n");
//	printf("**********      0.退出系统     **********\n");
//	printf("*****************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	//转移表
//	int(*p[5])(int, int) = { 0,add,sub,mul,div };
//	do
//	{
//		meau();
//		printf("请选择：");
//		scanf("%d", &input);
//		if (input >= 1 && input < 5)
//		{
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ret = (*p[input])(x, y);
//			printf("ret=%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出系统\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//		printf("\n\n");
//	} while (input);
//	return 0;
//}
 
 



////计算器
////3
//
//void cal(int(*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0; 
//	printf("请输入两个操作数:");
//	scanf("%d %d", &x, &y);
//	ret = (*p)(x, y);
//	printf("ret=%d\n", ret);
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void meau()
//{
//	printf("*****************************************\n");
//	printf("**********   1.add     2.sub   **********\n");
//	printf("**********   3.mul     4.div   **********\n");
//	printf("**********      0.退出系统     **********\n");
//	printf("*****************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		meau();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			cal(add);
//			break;
//		case 2:
//			cal(sub);
//			break;
//		case 3:
//			cal(mul);
//			break;
//		case 4:
//			cal(div);
//			break;
//		case 0:
//			printf("退出系统\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//		printf("\n\n");
//	} while (input);
//	return 0;
//}



////冒泡排序
//void bubble_sort(int arr[], int sz_1)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < sz_1 - 1; i++)
//	{
//		for (j = 0; j < sz_1 - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	//要求排成升序
//	int i = 0;
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


////qsort函数排序
////void qsort(void* base,size_t num,size_t size,int (*cmp)(const void* el,const void* e2));//函数声明
////base中存放的是待排序数据中的第一个对象的地址
////num是排序元素的个数
////size是一个排序元素的大小，单位是字节
////int (*cmp)(const void* el,const void* e2)是用来比较待排序数据中的2个元素的函数
//#include<stdlib.h>
//#include<string.h>
//void print(int* arr, int sz_1)
//{
//	int i = 0;
//	for (i = 0; i < sz_1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
////整型数据排序
//void test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//排序
//	qsort(arr, sz,sizeof(arr[0]), cmp_int);
//	//打印
//	print(arr, sz);
//}
//
////结构体数据排序
////定义结构体类型
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	return (*(struct Stu*)e1).age - (*(struct Stu*)e2).age;//大于0交换
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp((*(struct Stu*)e1).name ,(*(struct Stu*)e2).name);
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//	//按照年龄来排序
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), sort_by_age);
//	//按照姓名排序
//	qsort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//int main()
//{
//	//test1();//整型数据排序
//	test2();//结构体数据排序
//	return 0;
//}