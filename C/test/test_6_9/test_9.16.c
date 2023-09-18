#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//练习2

#if 0

//原程序
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}

void Test()
{
	char* str = NULL;
	str = GetMemory();//p的生命周期结束，空间还给系统，空间中的内容可能被覆盖
	printf(str);
}

int main()
{
	Test();
	return 0;
}

#elif 0

//修改
char* GetMemory(void)
{
	char* p = malloc(sizeof("hello world"));
	if (p == NULL)
	{
		printf("error");
		return 0;
	}
	//memset(p, 'h', 3);
	memcpy(p, "hello world", 12);
	//p = "hello world";
	return p;
}

void Test()
{
	char* str = NULL;
	str = GetMemory();//p的生命周期结束，空间还给系统，空间中的内容可能被覆盖
	printf(str);
	//free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}

#endif

//练习3
#if 0

//原程序
void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}

void Test()
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}

#endif

//练习4
#if 0

void Test()
{
	char* str = (char*)malloc(100);
	if (str == NULL)
	{
		printf("error");
		return 0;
	}
	strcpy(str, "hello");
	free(str);
	str = NULL;
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}

#endif