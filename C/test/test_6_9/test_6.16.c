#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////����ָ��
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int (*pf)(int, int) = &ADD;//pf��һ������ָ��
//	//int (*pf)(int, int) = ADD;//&ADD==ADD==pf
//	printf("%p\n", ADD);
//	printf("%p\n", &ADD);//�����������ֶ���ͬ
//	//int ret = (*pf)(3, 5);//����ָ����ú���
//	//int ret = pf(3, 5);//����ָ����ú���,*��Ϊ����⣬û��ʵ�ʵ�����
//	//int ret = ADD(3, 5);//����ָ����ú���
//	//printf("%d\n", ret);
//	return 0;
//}


////������
//int main()
//{
//	//����1
//	(*(void (*)())0)();
//	//����0��ַ���ĺ���
//	//�ú����޲�������������Ϊvoid
//	//1.void(*)()--����ָ������
//	//  void(*p)()--����ָ�����
//	//2.(void(*)())0--��0����ǿ������ת��,ת��Ϊ����ָ������
//	//3.*(void(*)())0--��0��ַ�����˽����ò���
//	//4..(*(void(*)())0)()--����0��ַ���ĺ���
//	return 0;
//}
////����2
//void (*signal(int, void(*)(int)))(int);//��������
////�ȼ���   void(*)(int)  signal(int,void(*)(int))
////����signal�ĺ����������ͷֱ���int���ͺ�void(*)(int)����ָ�����ͣ�����������void(*)(int)
////���﷨Ҫ��������д�����Խ�������*һ��
//// 
////�Դ���2���м򻯣�����
////typedef void(*pfun_t)(int);--���¶���void(*)(int)����ָ������Ϊpfun_t
////pfun_t signal(int,void(*)(int));


//����ָ������
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int(*pf1)(int, int) = Add;//���庯��ָ�����pf1
//	int(*pf2)(int, int) = Sub;//���庯��ָ�����pf2
//	int(*pfarr[2])(int, int) = { Add,Sub };//pfarr���Ǻ���ָ������
//	return 0;
//}

////������
////1
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void meau()
//{
//	printf("*****************************************\n");
//	printf("**********   1.add     2.sub   **********\n");
//	printf("**********   3.mul     4.div   **********\n");
//	printf("**********      0.�˳�ϵͳ     **********\n");
//	printf("*****************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		meau();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����������������:");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 2:
//			printf("����������������:");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 3:
//			printf("����������������:");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 4:
//			printf("����������������:");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 0:
//			printf("�˳�ϵͳ\n");
//			break;
//		default:
//			printf("�����������������\n");
//			break;
//		}
//		printf("\n\n");
//	} while (input);
//	return 0;
//}


////������
////2
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void meau()
//{
//	printf("*****************************************\n");
//	printf("**********   1.add     2.sub   **********\n");
//	printf("**********   3.mul     4.div   **********\n");
//	printf("**********      0.�˳�ϵͳ     **********\n");
//	printf("*****************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	//ת�Ʊ�
//	int(*p[5])(int, int) = { 0,add,sub,mul,div };
//	do
//	{
//		meau();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		if (input >= 1 && input < 5)
//		{
//			printf("����������������:");
//			scanf("%d %d", &x, &y);
//			ret = (*p[input])(x, y);
//			printf("ret=%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�ϵͳ\n");
//			break;
//		}
//		else
//		{
//			printf("�����������������\n");
//			break;
//		}
//		printf("\n\n");
//	} while (input);
//	return 0;
//}
 
 



////������
////3
//
//void cal(int(*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0; 
//	printf("����������������:");
//	scanf("%d %d", &x, &y);
//	ret = (*p)(x, y);
//	printf("ret=%d\n", ret);
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void meau()
//{
//	printf("*****************************************\n");
//	printf("**********   1.add     2.sub   **********\n");
//	printf("**********   3.mul     4.div   **********\n");
//	printf("**********      0.�˳�ϵͳ     **********\n");
//	printf("*****************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		meau();
//		printf("��ѡ��");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			cal(add);
//			break;
//		case 2:
//			cal(sub);
//			break;
//		case 3:
//			cal(mul);
//			break;
//		case 4:
//			cal(div);
//			break;
//		case 0:
//			printf("�˳�ϵͳ\n");
//			break;
//		default:
//			printf("�����������������\n");
//			break;
//		}
//		printf("\n\n");
//	} while (input);
//	return 0;
//}



////ð������
//void bubble_sort(int arr[], int sz_1)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < sz_1 - 1; i++)
//	{
//		for (j = 0; j < sz_1 - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	//Ҫ���ų�����
//	int i = 0;
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


////qsort��������
////void qsort(void* base,size_t num,size_t size,int (*cmp)(const void* el,const void* e2));//��������
////base�д�ŵ��Ǵ����������еĵ�һ������ĵ�ַ
////num������Ԫ�صĸ���
////size��һ������Ԫ�صĴ�С����λ���ֽ�
////int (*cmp)(const void* el,const void* e2)�������Ƚϴ����������е�2��Ԫ�صĺ���
//#include<stdlib.h>
//#include<string.h>
//void print(int* arr, int sz_1)
//{
//	int i = 0;
//	for (i = 0; i < sz_1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
////������������
//void test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//����
//	qsort(arr, sz,sizeof(arr[0]), cmp_int);
//	//��ӡ
//	print(arr, sz);
//}
//
////�ṹ����������
////����ṹ������
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	return (*(struct Stu*)e1).age - (*(struct Stu*)e2).age;//����0����
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp((*(struct Stu*)e1).name ,(*(struct Stu*)e2).name);
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//	//��������������
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), sort_by_age);
//	//������������
//	qsort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//int main()
//{
//	//test1();//������������
//	test2();//�ṹ����������
//	return 0;
//}