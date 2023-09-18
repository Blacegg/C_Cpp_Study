#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


////模拟实现memmove函数
//#include<assert.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//
//	char* ret = (char*)dest;
//#if 1
//	char a[20] = { 0 };
//	size_t i = 0;
//	for (i = 0; i < num; i++)
//	{
//		*(a + i) = *((char*)src);
//		src = (char*)src + 1;
//	}
//	for (i = 0; i < num; i++)
//	{
//		//1.
//		*((char*)dest + i) = a[i];
//		////2.
//		//*(char*)dest = a[i];
//		//dest = (char*)dest + 1;
//	}
//#elif 0
//	if (src > dest)//从前往后
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//从后向前
//	{
//		//1.
//		dest = (char*)dest + num;
//		src = (char*)src + num;
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest - 1;
//			src = (char*)src - 1;
//		}
//		////2
//		//while (num--)
//		//{
//		//	*((char*)dest + num) = *((char*)src + num);
//		//}
//	}
//
//#endif
//	return ret;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_memmove(arr1, arr1+2, 20);
//	return 0;
//}