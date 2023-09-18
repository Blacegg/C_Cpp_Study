#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////模拟实现strcmp
//#include<assert.h>
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	while ((*s1 != '\0') || (*s2 != '\0'))
//	{
//		if (*s1 > *s2)
//		{
//			return 1;
//		}
//		else if (*s1 < *s2)
//		{
//			return -1;
//		}
//		s1++;
//		s2++;
//	}
//	return 0;
//}
//int main()
//{
//	char s1[] = "abcdee";
//	char s2[] = "abcdef";
//	int ret = my_strcmp(s1, s2);
//	printf("%d\n", ret);
//	return 0;
//}

////模拟实现strstr函数
////1
//#include<assert.h>
//char* my_strstr(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	char* m = s2;
//	int n = 0;
//	while (*s1 != '\0' && *s2 != '\0')
//	{
//		if (*s1 == *s2)
//		{
//			n++;
//			s2++;
//		}
//		else
//		{
//			s2 = m;
//			s1 = s1 - n;
//			n = 0;
//		}
//		s1++;	
//	}
//	if (*s2 == '\0')
//	{
//		return s1 - n;
//	}
//	if (*s1 == '\0')
//	{
//		return (char*)NULL;
//	}
//}
//#include<string.h>
//int main()
//{
//	char s1[10] = "abbbc";
//	char s2[] = "bbc";
//	char* ret = my_strstr(s1, s2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了\n%s\n", ret);
//	}
//	return 0;
//}


////2
//#include<assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* cp = str1;
//
//	if (str2 == NULL)
//	{
//		return (char*)str1;
//	}
//
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		cp++;
//		if (*s2 == '\0')
//		{
//			return (char*)cp - 1;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//	}
//}
//#include<string.h>
//int main()
//{
//	char s1[10] = "abbbc";
//	char s2[] = "bbc";
//	char* ret = my_strstr(s1, s2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了\n%s\n", ret);
//	}
//	return 0;
//}