#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//实现字符串左旋
//题目内容
// 实现一个函数，可以左旋字符串中的k个字符
// eg：ABCD左旋一个字符得到BCDA
// ABCD左旋两个字符得到CDAB
//
////1.移动实现
//#include<string.h>
//void left(char a[], int k_1, int sz_1)
//{
//	int i = 0;
//	int n = k_1 % sz_1;
//	int j = 0;
//	for (j = 0; j < n; j++)//左旋n-1个字符
//	{
//		int tmp = a[0];
//		for (i = 0; i < sz_1 - 1; i++)//左旋1个字符
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
//	printf("%s\n", arr);//打印数组
//	scanf("%d", &k);//输入需要左旋字符数
//	left(arr, k, sz);//左旋字符串函数
//	printf("%s\n", arr);//打印数组
//	return 0;
//}

////2.逆序实现
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
//	printf("%s\n", arr);//打印数组
//	scanf("%d", &k);//输入需要左旋字符数
//	left2(arr, k, sz);
//	printf("%s\n", arr);//打印数组
//	return 0;
//}


//判断一个字符串是否是另外一个字符串旋转之后的结果

//void left(char a[], int sz_1)
//{
//	int i = 0;
//	int tmp = a[0];
//	for (i = 0; i < sz_1 - 1; i++)//左旋1个字符
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
//		//判断
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
//		//左旋
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
//		printf("是\n");
//	}
//	else
//	{
//		printf("不是\n");
//	}
//}


//#include<string.h>
//int is_or_no_left(char s1[], char s2[], int l)
//{
//	int i = 0;
//	int j = 0;
//	for (j = 0; j < l; j++)//左旋n-1个字符
//	{
//		int tmp = s1[0];
//		for (i = 0; i < l - 1; i++)//左旋1个字符
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
//		printf("是\n");
//	}
//	else
//	{
//		printf("不是\n");
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
//		printf("是\n");
//	}
//	else
//	{
//		printf("不是\n");
//	}
//	return 0;
//}