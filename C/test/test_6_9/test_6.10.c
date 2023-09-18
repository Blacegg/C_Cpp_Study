#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


////求两个整数的最小公倍数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//	}
//	else
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
//	for (c = a;; c++)
//	{
//		if (c % a == 0 && c % b == 0)
//		{
//			printf("%d\n", c);
//			break;
//		}
//	}
//	return 0;
//}


//倒置一句话，单词不倒置
//#include<string.h>
//void reverse(char* left, char* right)
//{
//	char tmp = 0;
//	while (left < right)
//	{
//		tmp = *right;
//		*right = *left;
//		*left = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[100] = {0};
//	gets(arr);
//	int len = strlen(arr);
//	reverse(arr,arr+len-1);
//	char* start = arr;
//	char* end = 0;
//	while (*start)
//	{
//		end = start;
//		/*while (1)
//		{
//			if (*end != ' ' && *end != '\0')
//			{
//				end++;
//			}
//			else
//			{
//				break;
//			}
//		}*/
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		reverse(start, end-1);
//		if (*end == ' ')
//		{
//			start = end + 1;
//		}
//		else
//		{
//			start = end;
//		}
//	}
//	printf("%s", arr);
//	return 0;
//}