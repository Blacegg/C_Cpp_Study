#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	
//	//int i = 0;
//	//int k = 7;
//	//char name[50];
//	//char c[26] = { 'a', 'b', 'c' };
//	//////scanf("%s\n", name);
//	//name[0] = 'a';
//	////while (i < 9)
//	////{
//	////	name[i] = name[i + 3];
//	////	i++;
//	////}
//	//int n = sizeof(name);
//	//int m = sizeof(c);
//	//for (i = 0; i <= n; i++) {
//	//	for (int j = 0; j <= m; j++) {
//	//		if (name[i] == c[j]) {
//	//			name[i] = c[j + 1];
//	//			break;
//	//		}
//	//	}
//	//}
//	int num[10];
//	int j = 0;
//	int a = 0;
//	for (j = 0; j < 10;) 
//	{
//		scanf("%d\n", &a);
//		num[j] = a;
//		j++;
//	}
//	int sum_o = 0;
//	int sum_j = 0;
//	int n = sizeof(num) / sizeof(int);
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		if (num[i] % 2 == 0) {
//			sum_o += num[i];
//		}
//		else
//		{
//			sum_j += num[i];
//		}
//	}
//
//	
//
//	printf("%d, %d", sum_o, sum_j);
//
//	return 0;
//}
////����n��
//int main()
//{
//	int n = 0;
//	int s = 1;
//	scanf ("%d", &n);
//	for (; n != 0; n--)
//	{
//		s = s * n;
//
//	}
//	printf("%d\n", s);
//	return 0;
//}


////��1��+ 2��+ 3��������������
//int jie(int x)
//{
//	int u = 1;
//	int i = 0;
//	while (i < x)
//	{
//		u = u * (i + 1);
//		i++;
//	}
//	return u;
//}
//
//int main()
//{
//	int n = 0;
//	int s = 1;
//	int sum = 0;
//	int i = 0;
//	int k = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		k = i + 1;
//		s = jie(k);
//		sum = sum + s;	
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//
////���������е�Ԫ��
//int binsearch(int x,int v[],int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (x == v[i])
//			break;
//	}
//	return i;
//}
//
//
//int main()
//{
//	
//	int s = 0;
//	int x = 0;
//	int n = 0;
//	int v[] = { 0,1,2,3,4,5,6,7,8,9 };
//	scanf("%d", &x);
//	n = sizeof(v) / sizeof(v[0]);
//	s = binsearch(x, v, n);
//	printf("%d\n", s);
//	return 0;
//}

//
////�����ƶ�
//#include<string.h>
//#include<windows.h>
//int main()
//{
//	int left = 0;
//	int right = 0;
//	int n = 0;
//	char s[] = "I love you!!!";
//	char l[] = "#############";
//	//right = sizeof(s) / sizeof(s[0])-1;
//	right = strlen(s) - 1;
//		for (left=0;left<=right;left++,right--)
//	{
//			l[left] = s[left];
//		    l[right] = s[right];
//			printf("%s\n", l);
//			Sleep(1000);
//			system("cls");
//	}
//		printf("%s\n", l);
//	return 0;
//}



////ģ���û���¼
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char n[12] = "0";
//	for (i=0; i<3; i++)
//	{
//		printf("����������\n");
//		scanf("%s", n);
//		if (strcmp("123456", n) == 0)
//		{
//			printf("������ȷ\n");
//			break;
//		}
//		else
//		{
//			printf("�����������������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("�˳�ϵͳ\n");
//	}
//	return 0;
//}



////������
//#include <stdlib.h>
//#include <time.h>
//void meau()
//{
//	printf("******************************************\n");
//	printf("************     1.play      *************\n");
//	printf("************     0.out       *************\n");
//	printf("******************************************\n");
//	printf("��ѡ��\n");
//}
//void game()
//{
//	int right = 0;
//	int guess = 0;
//	right = rand() % 100 + 1;
//	for (;;)
//	{
//		printf("�������\n");
//		scanf("%d", &guess);
//		if (guess < right)
//		{
//			printf("��С��\n");
//		}
//		else if (guess > right)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int choose = 0;
//	do
//	{
//		meau();
//		scanf("%d", &choose);
//		switch (choose)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("��Ϸ����\n");
//			break;
//		default :
//			printf("�����������������\n");
//			break;
//		}
//	} while (choose);
//	return 0;
//}



////�ȴ�С
//int main()
//{
//	int i = 0;
//	int c = 0;
//	int b = 0;
//	int a = 0;
//	int n = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	for (i = 0; i < 2; i++)
//	{
//		if (b > a)
//		{
//			n = a;
//			a = b;
//			b = n;
//		}
//		if (c > b)
//		{
//			n = c;
//			c = b;
//			b = n;
//		}
//	}
//	printf("%d\n%d\n%d\n", a,b,c);
//	return 0;
//}



////��ӡ3�ı���
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 101; i++)
//	{
//		if (i % 3)
//		{
//			continue;
//		}
//		else
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}



////�����Լ��
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	int c = 0;
//	int k = 0;
//	scanf("%d%d", &a, &b);
//	for (i = 1; (i <= a) && (i <= b); i++)
//	{
//		if (((a % i) || (b % i)) == 0)
//		{
//			c = i;
//		}
//	}
//	printf("%d\n", c);
//	return 0;
//}



//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	char s[30] = { 0 };
//	system("shutdown -s -t 60");
//	printf("���ļ��������1���Ӻ�ػ���������룺�������ͻ�ȡ���ػ�\n");
//	again:
//		scanf("%s", s);
//	if (strcmp(s, "������") == 0)
//	{
//		system("shutdown -a");
//		printf("��ɰ���\n");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}



////������
//int is_mun(int arr[], int k, int n)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int ret = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 17;
//	int n = sizeof(arr) / sizeof(arr[0]);
//	ret = is_mun(arr, k, n);
//	if (ret != -1)
//	{
//		printf("%d", ret);
//		printf("�ҵ���");
//	}
//	else
//	{
//		printf("û�ҵ�" );
//	}
//	return 0;
//}



////���n��쳲�������
//int F(int a)
//{
//	if (a <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return F(a - 1) + F(a - 2);
//	}
//}
//int main()
//{
//	int n = 10;
//	int ret = 0;
//	ret = F(n);
//	printf("%d\n", ret);
//	return 0;
//}


////��ŵ��
//long count = 0;
//void move(char x, char y)
//{
//	printf("%c->%c #%d\n",x,y,++count);//��x�ϵ�һ������Ų��y��
//}
//void F(int n,char one,char three,char two)//��n-1�����Ӵ�one��ͨ��two�ŵ�three��
//{
//	if (n == 1)
//	{
//		move(one, three);
//	}
//	else
//	{
//		F(n - 1, one, two, three);
//		move(one, three);
//		F(n - 1, two, three, one);
//	}
//}
//int main()
//{
//	int n = 3;
//	char A = 'A';
//	char B = 'B';
//	char C = 'C';
//	F(n,A,C,B);
//	return 0;
//}



////������̨��
//int Fcn(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//	{
//		return Fcn(n - 1) + Fcn(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fcn(n);
//	printf("%d\n", ret);
//	return 0;
//}

//��1~100��9���ֵĴ���
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i < 101; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//			printf("%d ", i);
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}



////�������
//int main()
//{
//	int i = 0;
//	float sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//			sum = sum + 1 / (float)i;
//		else
//			sum = sum - 1 / (float)i;//�˴������жϣ����Զ���һ��-1�����ϳ�
//	}
//	printf("%f", sum);
//	return 0;
//}



////��ʮ�����е����ֵ
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = 0;
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		if (arr[i] > arr[i + 1])
//		{
//			arr[i + 1] = arr[i];
//			max = arr[i + 1];
//		}
//		else
//			max = arr[i+1];
//	}
//	printf("%d\n", max);
//	return 0;
//}



////����žų˷���
//int main()
//{
//	int i = 1;
//	int j = 1;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 9; j >= i; j--)
//			printf("%d*%d=%-2d ", i, j, i * j);
//		printf("\n");
//	}
//	return 0;
//}



////��������
//int len_s(char* x)
//{
//	int i = 0;
//	while (x[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//void reverse_string(char* str)
//{
//	int left = 0;
//	int right = len_s(str)-1;
//	char tem = *(str);
//	*(str) = *(str + right);
//	*(str + right) = '\0';
//	if (len_s(str + 1) > 1)
//	{
//		reverse_string(str + 1);
//	}
//	*(str + right) = tem;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


//
////��λ��
//int Digitsum(int a)
//{
//	int sum = 0;
//	int b = a % 10;
//	if (a != 0)
//	{
//		a = a / 10;
//		sum = sum + b + Digitsum(a);
//	}
//	return sum;
//}
//int main()
//{
//	int s = 0;
//	int ret = 0;
//	scanf("%d", &s);
//	ret = Digitsum(s);
//	printf("%d\n", ret);
//	return 0;
//}



////����n��k�η�
//double fun(int a, int b)
//{
//	if (b > 0)
//	{
//		return a * fun(a, 1.0*b - 1);
//	}
//	else if (b == 0)
//		return 1.0;
//	else
//		return 1.0 / (a * fun(a, -b - 1));
//}
//int main()
//{
//	int n = 2;
//	int k = -3;
//	double j = fun(n, k);
//	printf("%lf\n", j);
//	return 0;
//}


////������������е�1�ĸ���
//int main()
//{
//	int a = 1;
//	int b = 0;
//	while (a)
//	{
//		if (a % 2 == 1)
//		{
//			b++;
//		}
//		a = a >> 1;
//	}
//	printf("%d", b);
//	return 0;
//}

//
////ð������
//void paixu(int* arr)
//{
//	int k = 0;
//	int i = 0;
//	for (i = 0; i <9; i++)
//	{
//		if (*arr < *(arr + 1))
//		{
//			k = *arr;
//			*arr = *(arr + 1);
//			*(arr + 1) = k;
//		}
//		arr++;
//	}
//}
//int main()
//{
//	int a[10] = { 8,5,4,6,2,1,3,9,7,0 };
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		paixu(a);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}



////init������ʼ������Ϊ0
////print������ӡ����Ԫ��
////reverse��������
//void print(int* a)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++,a++)
//	{
//		printf("%d ", *a);
//	}
//	printf("\n");
//}
//void reverse(int a[10],int s)
//{
//	int left = 0;
//	int right = s;
//	while (left < right)
//	{
//		a[left] = a[left] + a[right];
//		a[right] = a[left] - a[right];
//		a[left] = a[left] - a[right];
//		left++;
//		right--;
//	}
//}
//void init(int*arr)
//{
//	int i = 0;
//	for (i = 0; i < 9; i++,arr++)
//	{
//		*arr = 0;
//	}
//}
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int s = 0;
//	s = sizeof(arr) / sizeof(arr[0]) - 1;
//	print(arr);
//	reverse(arr,s);
//	print(arr);
//	init(arr);
//	print(arr);
//	return 0;
//}


////�����������������
//void print(int* a)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++,a++)
//	{
//		printf("%d ", *a);
//	}
//	printf("\n");
//}
//int main()
//{
//	int a[10] = { 1,1,1,1,1,1,1,1,1,1 };
//	int b[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	int t = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		t = a[i];
//		a[i] = b[i];
//		b[i] = t;
//	}
//	print(a);
//	print(b);
//	return 0;
//}

int main()
{
	int a = 0;
	int* pa = 0;
	pa = &a;
	return 0;
}