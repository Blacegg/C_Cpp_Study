#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>

////字符分类函数
//int main()
//{
//	int c = 2;
//	int ret = isdigit(c);
//	printf("%d\n", ret);
//	return 0;
//}

////模拟memcpy函数
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t n)
//{
//	assert(dest && src);
//	char* ret = (char*)dest;
//#if 0
//	while (n--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//#elif 1
//	size_t num = 0;
//	for (num = 0; num < n; num++)
//	{
//		*((char*)dest+num) = *((char*)src+num);
//	}
//#endif
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr1, arr2, 25);
//	return 0;
//}