#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////ʵ��strlen������ʵ��
//#include<string.h>
//int my_strlen(char* arr)
//{
//	int m = 0;
//	int i = 0;
//	while (*(arr + i)!='\0')
//	{
//		m++;
//		i++;
//	}
//	return m;
//}
//int main()
//{
//	char arr[20] = "abc def";
//	int sz = my_strlen(arr);
//	printf("%d\n", strlen(arr));
//	printf("%d\n", sz);
//	return 0;
//}


////ʵ�ֺ���strcpy�Ĺ���
//#include<assert.h>
//void copy(const char* arr_1, char* arr_2)
//{
//	assert(arr_1);
//	assert(arr_2);
//	int i = 0;
//	while (*(arr_1 + i))
//	{
//		*(arr_2 + i) = *(arr_1 + i);
//		i++;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = "0";
//	copy(arr1, arr2);
//	printf("%s\n", arr2);
//	return 0;
//}


//11001000-200   unsigned char
//11111111 11111111 11111111 11001000 �����޷���char��������������0
//00000000 00000000 00000000 11001000
//01100100-100
//00000000 00000000 00000000 01100100
//11111111 11111111 11111111 11001000 
//00000000 00000000 00000000 00101100
//00101100-44


////����������
////1
//#include<assert.h>
//void copy(const int* arr_2, int* arr_1)
//{
//	assert(arr_1);
//	assert(arr_2);
//	int i_2 = 0;
//	while (*(arr_2 + i_2))
//	{
//		*(arr_1 + i_2) = *(arr_2 + i_2);
//		i_2++;
//	}
//}
//void print(int* arr_2)
//{
//	int i_1 = 0;
//	while (*(arr_2 + i_1))
//	{
//		printf("%d ", *(arr_2 + i_1));
//		i_1++;
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr1[10] = { 1 };
//	int arr2[10] = { 1 };
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d", &n);//����������ǵ�����
//	printf("\n");
//	printf("%d\n", arr1[0]);
//	//����
//	for (j = 2; j < n+1; j++)
//	{
//		//ÿ����
//		for (i = 1; i < j; i++)
//		{
//			arr2[i] = arr1[i] + arr1[i - 1];
//		}
//		print(arr2, i);//��ӡ������ǵ�һ��
//		copy(arr2, arr1);//���ƺ���
//	}
//	return 0;
//}


////��ά��������������
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &n);//����������ǵ�����
//	printf("\n");
//	//����������ǵ����������ά������,ֻ�õ�������
//	for (i = 0; i < n; i++)//����
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if ((j < i) && (j != 0))
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	//�����ά���飬���������
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//                             1
//                           1   1
//                         1   2   1
//                       1   3   3   1
//                     1   4   6   4   1                 
//                           .......


////��������
////A:������
////B:��C
////C:��D
////D:C�ں�˵
//char m_goal(int a[])
//{
//	int j = 0;
//	for (j = 0; j < 4; j++)
//	{
//		if (a[j])
//		{
//			switch (j)
//			{
//			case 0:
//				return 'A';
//				break;
//			case 1:
//				return 'B';
//				break;
//			case 2:
//				return 'C';
//				break;
//			case 3:
//				return 'D';
//				break;
//			}
//		}
//	}
//}
//int num(int* a_1)
//{
//	int i = 0;
//	int num_1 = 0;
//	for (i = 0; i < 4; i++)
//	{
//		if (*(a_1 + i))
//		{
//			num_1++;
//		}
//	}
//	return num_1;
//}
//int main()
//{
//	
//	int a[4] = { 0 };
//    //A 
//	a[0] = 0;
//	//B 
//	a[2] = 1;
//	//C 
//	a[3] = 1;
//	//D 
//	a[3] = 0;
//	char goal = '0';
//	int n = 0;
//	if (goal='A')
//	{
//		a[0] = 1;
//		n = num(a);
//		if (n == 1)
//		{
//			printf("���ɷ���%c\n", m_goal(a));
//			printf("A��˵��");
//		}
//	}
//	if (goal = 'B')
//	{
//		a[0] = 0;
//		a[2] = 0;
//		n = num(a);
//		if (n == 1)
//		{
//			printf("���ɷ���%c\n", m_goal(a));
//			printf("B��˵��");
//		}
//	}
//	if (goal = 'C')
//	{
//		a[2] = 1;
//		a[3] = 0;
//		n = num(a);
//		if (n == 1)
//		{
//			printf("���ɷ���%c\n", m_goal(a));
//			printf("C��˵��");
//		}
//	}
//	if (goal = 'D')
//	{
//		a[3] = 1;
//		n = num(a);
//		if (n == 1)
//		{
//			printf("���ɷ���%c\n", m_goal(a));
//			printf("D��˵��");
//		}
//	}
//	return 0;
//}


////2
////A:������
////B:��C
////C:��D
////D:C�ں�˵
//int main()
//{
//	char killer = '0';
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c�����֣�", killer);
//		}
//	}
//	return 0;
//}


////�˶�Ա������
////A:b=2,a=3
////B:b=2,e=4
////C:c=1,d=2
////D:c=5,d=3
////E:e=4,a=1
//int main()
//{
//	int a = 1; 
//	int b = 1;
//	int c = 1;
//	int d = 1;
//	int e = 1;
//	for (e = 1; e <= 5; e++)
//	{
//		for (d = 1; d <= 5; d++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (b = 1; b <= 5; b++)
//				{
//					for (a = 1; a <= 5; a++)
//					{
//						if (((((b == 2) + (a == 3)) == 1)&&
//							(((b == 2) + (e == 4)) == 1)&&
//							(((c == 1) + (d == 2)) == 1)&&
//							(((c == 5) + (d == 3)) == 1)&&
//							(((e == 4) + (a == 1)) == 1)))
//						{
//							
//							if (a * b * c * d * e == 120)
//							{
//								printf("A=%d,B=%d,C=%d,D=%d,E=%d", a, b, c, d, e);
//							}
//						}
//					}	
//				}	
//			}
//		}
//	}
//	return 0;
//}