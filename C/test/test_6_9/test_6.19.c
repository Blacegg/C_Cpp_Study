#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////练习3
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x %x", ptr1[-1], *ptr2);
//	return 0;
//}
//
////练习4
//int main()
//{
//	int a[3][2] = { (0,1),(2,3) ,(4,5) };
//	int* p;
//	p = a[0];
//	printf("%d\n", p[0]);
//	return 0;
//}


////练习5
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}

////练习6
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}

////练习7
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** p = a;
//	p++;
//	printf("%s\n", *p);//at
//	printf("%c\n", **p);//a
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };//存的是&E，&N，&P，&F
//	char** cp[] = { c + 3,c + 2,c + 1,c };//存的是&&F,&&P，&&N,&&E
//	char*** cpp = cp;//&&&F
//	printf("%s\n", **++cpp);//&p--输出POINT，cpp==&&&p
//	printf("%s\n", *-- * ++cpp + 3);//++cpp==&&&N,*++cpp==&&N,*--*++cpp==&E,*--*++cpp+3==&E,输出的是ER
//	printf("%s\n", *cpp[-2] + 3);//cpp[-2]==*(cpp-2)==&&F,*cpp[-2]==&F,st
//	printf("%s\n", cpp[-1][-1] + 1);//ew
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	printf("%d\n", a + 1);//6
//	printf("%d\n", ++a);//6
//	printf("%d\n", a);//6
//	return 0;
//}


////杨氏矩阵
////1.递归实现查找
//int i = 1;
//void find(int a[][3], int r, int s, int k_1)
//{
//	if ((a[0][s - 1] > k_1)&&(s>0))//要查找的数不在这一列
//	{
//		//去掉这一列继续查找
//		find(a, r, s - 1, k_1);
//	}
//	if ((a[0][s - 1] < k_1)&&(s>0))//要查找的数不在这一行
//	{
//		//去掉这一行继续查找
//		i = i + 1;
//		find(a+1, r - 1, s, k_1);
//	}
//	if ((a[0][s - 1] == k_1)&&(s>0))//找到了
//	{
//		printf("找到了！\n");
//		printf("第%d行，第%d列\n", i, s);
//	}
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//查找一个数字
//	int k = 0;
//	scanf("%d", &k);//输入要查找的数字
//	find(arr, 3, 3, k);//查找
//	return 0;
//}


////2.
//int find(int arr[3][3], int* r, int* s, int k_1)
//{
//	int x = 0;
//	int y = *s - 1;
//	while ((x < *r) && (y >= 0))
//	{
//		if (arr[x][y] > k_1)
//		{
//			y--;
//		}
//		if (arr[x][y] < k_1)
//		{
//			x++;
//		}
//		if (arr[x][y] == k_1)
//		{
//			//printf("第%d行第%d列\n", x + 1, y + 1);
//			*r = x;
//			*s = y;
//			return 1;
//		}
//	}
//		return 0;
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	int x = 3;
//	int y = 3;
//	scanf("%d", &k);//输入要查找的数字
//	int ret = find(arr, &x, &y, k);//查找
//	//&x，&y
//	//1.传入参数
//	//2.带回值
//	if (ret == 1)
//	{
//		printf("找到了！\n");
//		printf("第%d行第%d列\n", x + 1, y + 1);
//	}
//	if (ret == 0)
//	{
//		printf("找不到！\n");
//	}
//	return 0;
//}