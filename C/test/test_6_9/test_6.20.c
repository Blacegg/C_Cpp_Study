#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//ʵ���ַ�������
//��Ŀ����
// ʵ��һ�����������������ַ����е�k���ַ�
// eg��ABCD����һ���ַ��õ�BCDA
// ABCD���������ַ��õ�CDAB
//
////1.�ƶ�ʵ��
//#include<string.h>
//void left(char a[], int k_1, int sz_1)
//{
//	int i = 0;
//	int n = k_1 % sz_1;
//	int j = 0;
//	for (j = 0; j < n; j++)//����n-1���ַ�
//	{
//		int tmp = a[0];
//		for (i = 0; i < sz_1 - 1; i++)//����1���ַ�
//		{
//			a[i] = a[i + 1];
//		}
//		a[sz_1 - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "ABCDEFG";
//	int k = 0;
//	int sz = strlen(arr);
//	printf("%s\n", arr);//��ӡ����
//	scanf("%d", &k);//������Ҫ�����ַ���
//	left(arr, k, sz);//�����ַ�������
//	printf("%s\n", arr);//��ӡ����
//	return 0;
//}

////2.����ʵ��
//#include<assert.h>
//void reverse(char* left, char* right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left2(char* arr, int k, int sz)
//{
//	k = k % sz;
//	reverse(arr, arr + k - 1);
//	reverse(arr + k, arr + sz - 1);
//	reverse(arr, arr + sz - 1);
//}
//
//int main()
//{
//	char arr[] = "ABCDEFG";
//	int k = 0;
//	int sz = strlen(arr);
//	printf("%s\n", arr);//��ӡ����
//	scanf("%d", &k);//������Ҫ�����ַ���
//	left2(arr, k, sz);
//	printf("%s\n", arr);//��ӡ����
//	return 0;
//}


//�ж�һ���ַ����Ƿ�������һ���ַ�����ת֮��Ľ��

//void left(char a[], int sz_1)
//{
//	int i = 0;
//	int tmp = a[0];
//	for (i = 0; i < sz_1 - 1; i++)//����1���ַ�
//	{
//		a[i] = a[i + 1];
//	}
//	a[sz_1 - 1] = tmp;
//}
//int is_or_no_left(char s1[], char s2[], int l)
//{
//	int j = 0;
//	for (j = 0; j < l; j++)
//	{
//		//�ж�
//		int i = 0;
//		int k = 0;
//		for (i = 0; i < l; i++)
//		{
//			if (s1[i] == s2[i])
//			{
//				k++;
//				if (k == l)
//				{
//					return 1;
//				}
//				if (k != i + 1)
//				{
//					break;
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (j == l - 1)
//		{
//			return 0;
//		}
//		//����
//		left(s1, l);
//	}
//}
//
//#include<string.h>
//int main()
//{
//	char s1[] = "abcdef";
//	char s2[] = "cdefab";
//	char s3[] = "abcdfe";
//	int len = strlen(s1);
//	int ret = 0;
//	ret = is_or_no_left(s1, s2, len);
//	//ret = is_or_no_left(s1, s3, len);
//	if (ret)
//	{
//		printf("��\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//}


//#include<string.h>
//int is_or_no_left(char s1[], char s2[], int l)
//{
//	int i = 0;
//	int j = 0;
//	for (j = 0; j < l; j++)//����n-1���ַ�
//	{
//		int tmp = s1[0];
//		for (i = 0; i < l - 1; i++)//����1���ַ�
//		{
//			s1[i] = s1[i + 1];
//		}
//		s1[l - 1] = tmp;
//		if (strcmp(s1, s2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char s1[] = "abcdef";
//	char s2[] = "cdefab";
//	char s3[] = "abcdfe";
//	int len = strlen(s1);
//	int ret = 0;
//	//ret = is_or_no_left(s1, s2, len);
//	ret = is_or_no_left(s1, s3, len);
//	if (ret)
//	{
//		printf("��\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//}


//#include<string.h>
//int is_or_no_left(char s1[], char s2[])
//{
//	if (strlen(s1) != strlen(s2))
//	{
//		return 0;
//	}
//	int len = strlen(s1);
//	strncat(s1, s1, len);
//	char* p = strstr(s1, s2);
//	return p != NULL;
//}
//int main()
//{
//	char s1[20] = "abcdef";
//	char s2[] = "cdefab";
//	char s3[] = "abcdfe";
//	int ret = 0;
//	//ret = is_or_no_left(s1, s2);
//	ret = is_or_no_left(s1, s3);
//	if (ret)
//	{
//		printf("��\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//	return 0;
//}