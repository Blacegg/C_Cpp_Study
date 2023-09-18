#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////strcpy的实现
//#include<assert.h>
//char* my_strcpy(char* a,const char* b)
//{
//	assert(a != NULL);
//	assert(b != NULL);
//	char* ret = a;
//	while (*a++ = *b++)
//	{
//	}
//	*a = *b;
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = { "xxxxxxxxxxxxxxxx" };
//	char arr2[] = { "haojiahuo" };
//	printf("%s\n",my_strcpy(arr1, arr2));
//	return 0;
//}


//
////实现计算二进制数中1的个数
////1.只对正数有效,在int前加unsigned
//int my_count(unsigned int a)
//{
//	int count = 0;
//	while (a != 0)
//	{
//		if (a % 2 == 1)
//		{
//			count++;
//		}
//		a = a / 2;
//	}
//	return count;
//}

////2.按位与1
//int my_count(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n & 1) == 1)    //if((n>>i)&1==1);count++;
// .
//		{
//			n = n >> 1;
//			count++;
//		}
//	}
//	return count;
//}


////3.按位与n-1
//int my_count(int a)
//{
//	int count = 0;
//	while (a)
//	{
//		a = (a & (a - 1));
//		count++;
//	}
//	return count;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int s = my_count(n);
//	printf("%d\n", s);
//	return 0;
//}

////两个数的二进制数不同的位数
//int my_count(int c)
//{
//	int i = 0;
//	while (c)
//	{
//		c = c & (c - 1);
//		i++;
//	}
//	return i;
//}
//
//int main()
//{	int a = 1999;
//	int b = 2299;
//	int c = 0;
//	c = a ^ b;
//	printf("%d\n", my_count(c));
//	return 0;
//}


//将一个数的二进制数分为奇数位和偶数位
int main()
{
	int a = 10;
	int i = 0;
	int b = 0;
	int c = 0;
	for (i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			b += (a % 2) << i;
		}
		else
		{
			c += (a % 2) << i;
		}
		a /= 2;
	}
	printf("%d %d", b, c);
	return 0;
}












