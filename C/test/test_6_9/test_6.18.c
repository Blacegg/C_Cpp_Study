#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int b[] = { 2,3,4,5,6 };
//	int c[] = { 3,4,5,6,7 };
//	int* arr[3] = { a,b,c };//将三个数组的首元素的地址放在指针数组中
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(arr[i] + j));//指针数组的访问方式1
//			printf("%d ", arr[i][j]);//指针数组的访问方式2
//		}
//		printf("\n");
//	}
//}

//int* arr1[10];
//char* arr2[4];
//char** arr3[5];

//void print(int(*parr)[5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)//行
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)//列
//		{
//			printf("%d ", *(*(parr + i) + j));
//		}
//		printf("\n");//打印完一行后换行
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print(arr, 3, 5);
//	return 0;
//}

//int arr[5];
//int* parr1[10];
//int(*parr2)[10];
//int(*parr3[10])[5];