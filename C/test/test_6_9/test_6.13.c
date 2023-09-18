#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


////写一个函数实现字符串逆序
//#include<string.h>
//void reverse(char* arr1, int sz1)
//{
//	int tmp = 0;
//	char* right = arr1 + sz1;
//	while(arr1<right)
//	{
//		tmp = *arr1;
//		*arr1 = *right;
//		*right = tmp;
//		arr1++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = { "abcdef" };
//	int sz = strlen(arr);
//	reverse(arr, sz - 1);
//	printf("%s\n", arr);
//	return 0;
//}


//打印一个菱形
// //1
//int main()
//{
//	char arr[14] = {' ',' ',' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ','\0'};
//	int c = 6;
//	int k = 0;
//	for (k = 0; k < 7; k++)
//	{
//		arr[c + k] = '*';
//		arr[c - k] = '*';
//		printf("%s\n", arr);
//	}
//	k--;
//	for (; k >= 0; k--)
//	{
//		arr[c + k] = ' ';
//		arr[c - k] = ' ';
//		printf("%s\n", arr);
//	}
//	return 0;
//}

//
////2
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0; 
//	int j = 0;
//	//上部
//	for (i = 0; i < line; i++)//打印行
//	{
//		//打印空格
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf("%c", ' ');
//		}
//		//打印*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//	//下部
//	//打印行
//	for (i = 0; i < line - 1; i++)
//	{
//		//打印空格
//		for (j = 0; j < i + 1; j++)
//		{
//			printf("%c", ' ');
//		}
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("%c", '*');
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

//

////喝汽水问题
////1. 喝汽水，一瓶汽水一块钱，两个空瓶换一瓶汽水，20元能喝几瓶
//int main()
//{
//	int money = 0;//多少钱
//	scanf("%d", &money);
//	int sum = 0;//汽水数
//	int kong = 0;//空瓶数
//	int i = 0;
//	int j = 0;
//	sum = money;//先买20瓶汽水
//	kong = money;//空瓶
//	while (kong!=0&&kong!=1)
//	{
//		i = 0;
//		j = 0;
//		i = kong / 2;//空瓶换汽水数
//		j = kong % 2;//剩余空瓶数
//		sum = sum + i;//总汽水数
//		kong = i + j;//喝完汽水后的空瓶总数
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int money = 0;//多少钱
//	scanf("%d", &money);
//	int sum = money;//汽水数
//	int kong = money;//空瓶数
//	while (kong != 0 && kong != 1)
//	{
//		sum = sum + kong / 2;//总汽水数
//		kong = kong / 2 + kong % 2;//喝完汽水后的空瓶总数
//	}
//	printf("%d\n", sum);
//	return 0;
//}


////奇偶排序
// //1
//void paixu(int* arr1, int sz1)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < sz1; i++)
//	{
//		for (j = 0; j < sz1-1; j++)
//		{
//			if ((*(arr1+j)) % 2 == 0)
//			{
//				tmp = *(arr1 + j);
//				*(arr1 + j) = *(arr1 + j + 1);
//				*(arr1 + j + 1) = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	paixu(arr, sz);
//	int m = 0;
//	for (m = 0; m < sz; m++)
//	{
//		printf("%d ", arr[m]);
//	}
//	return 0;
//}


////2
//void move(int a[], int sz1)
//{
//	int left = 0;
//	int right = sz1 - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		//从前往后找一个偶数
//		while ((left < right) && (a[left] % 2 == 1))
//		{
//			left++;
//		}
//		//从后往前找一个奇数
//		while ((left < right) && (a[right] % 2 == 0))
//		{
//			right--;
//		}
//		tmp = a[left];
//		a[left] = a[right];
//		a[right] = tmp;
//	}
//}
//
//void print(int a[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}