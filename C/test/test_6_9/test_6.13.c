#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


////дһ������ʵ���ַ�������
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


//��ӡһ������
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
//	//�ϲ�
//	for (i = 0; i < line; i++)//��ӡ��
//	{
//		//��ӡ�ո�
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf("%c", ' ');
//		}
//		//��ӡ*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//	//�²�
//	//��ӡ��
//	for (i = 0; i < line - 1; i++)
//	{
//		//��ӡ�ո�
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

////����ˮ����
////1. ����ˮ��һƿ��ˮһ��Ǯ��������ƿ��һƿ��ˮ��20Ԫ�ܺȼ�ƿ
//int main()
//{
//	int money = 0;//����Ǯ
//	scanf("%d", &money);
//	int sum = 0;//��ˮ��
//	int kong = 0;//��ƿ��
//	int i = 0;
//	int j = 0;
//	sum = money;//����20ƿ��ˮ
//	kong = money;//��ƿ
//	while (kong!=0&&kong!=1)
//	{
//		i = 0;
//		j = 0;
//		i = kong / 2;//��ƿ����ˮ��
//		j = kong % 2;//ʣ���ƿ��
//		sum = sum + i;//����ˮ��
//		kong = i + j;//������ˮ��Ŀ�ƿ����
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int money = 0;//����Ǯ
//	scanf("%d", &money);
//	int sum = money;//��ˮ��
//	int kong = money;//��ƿ��
//	while (kong != 0 && kong != 1)
//	{
//		sum = sum + kong / 2;//����ˮ��
//		kong = kong / 2 + kong % 2;//������ˮ��Ŀ�ƿ����
//	}
//	printf("%d\n", sum);
//	return 0;
//}


////��ż����
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
//		//��ǰ������һ��ż��
//		while ((left < right) && (a[left] % 2 == 1))
//		{
//			left++;
//		}
//		//�Ӻ���ǰ��һ������
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