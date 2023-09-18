#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Á·Ï°1
#if 0
//Ô­³ÌÐò
void GetMemory(char* p)
{
	p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf("%s", str);
}

int main()
{
	Test();
	return 0;
}
#elif 0
//ÐÞ¸Ä1
void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	char** p = &str;
	GetMemory(p);
	strcpy(str, "hello world");
	printf("%s",str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}

#elif 0

char* GetMemory(char* p)
{
	p = (char*)malloc(100);
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory(str);
	strcpy(str, "hello world");
	printf("%s", str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}

#endif



