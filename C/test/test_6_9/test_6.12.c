#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//double*(*pd)[5]

//int arr[10] = { 1,2,3,4,5 };
//int (*parr)[10] = &arr;//arr���������Ԫ�صĵ�ַ��&arr������ĵ�ַ
////parr��һ������ָ�룬�����ŵ�������ĵ�ַ
//double* d[5];//����һ��ָ������
//double* (*pa)[5] = &d;//pa��һ������ָ�룬������ָ������d�ĵ�ַ
////double*�Ǳ�ʾ�����������ݵĸ�ʽ��*pa�Ǳ�ʾpa��һ��ָ�룬[5]��ʾ��ָ������5��Ԫ��

//����ָ�����һά����
//int main()
//{
//	int arr[10] = { 3,1,2,3,4,5,6,7,8,9 };
//	int(*parr)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *((*parr) + i));//*parr�൱����������Ҳ��д��*(*parr + i)
//	}
//	return 0;
//}



//��Sn=a+aa+aaa+aaaa+aaaaa,����a��һ������
//����
//int output1(int a, int n)
//{
//	int Sn = 0;
//	int m = a;
//	while (n != 0)
//	{
//		Sn += m;
//		m = m * 10 + a;
//		n--;
//	}
//	return Sn;
//}
//int output(int b, int n)
//{
//	int k = 1;
//	int s = n;
//	if (n == 1)
//	{
//		return b;
//	}
//	else
//	{
//		for (s=n-1; s > 0;s--)
//		{
//			k = k * 10;
//		}
//		return b*k+output(b, n - 1);
//	}
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 5;
//	int Sn = 0;
//	/*for (i = 5; i > 0; i--)
//	{
//		Sn = Sn+output(a, i);
//	}*/
//	/*printf("Sn=%d\n", Sn);*/
//	printf("Sn=%d\n", output1(a, i));
//	return 0;
//}

//����
//int main()
//{
//	int a = 1;
//	int i = 0;
//	int Sn = 0;
//	int k = 0;
//	for (i = 0; i < 5; i++)
//	{
//		if (i == 0)
//			k = a;
//		else
//		{
//			k = a * 10;
//		}
//		k = a * 10;
//		u=
//		Sn = Sn + a * 10 + a;
//	}
//	return 0;
//}


////3
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int Sn = 0;
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		Sn = Sn + ret;
//	}
//	printf("%d", Sn);
//	return 0;     
//}
//


////дһ����ָ���ӡһά��������ĺ���
//void print(int* a, int m)
//{
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//}
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	print(arr, n);
//	return 0;
//}




////��ӡ0-100000��ˮ�ɻ���
////153=1^3+5^3+3^3
//int weishu(int i_1)
//{
//	int i = 0;
//	do
//	{
//		i++;
//		i_1 /= 10;
//	} while(i_1);
//	return i;
//}
//
//int mi(int m_1,int a_1)
//{
//	int i = 0;
//	int k = 1;
//	for (i = 0; i < a_1; i++)
//	{
//		k = k * m_1;
//	}
//	return k;
//}
//int main()
//{
//	int a = 0;
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	int s = 0;
//	int b = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		s = 0;
//		b = i;
//		a=weishu(b);//��λ��
//		for (j = 0; j < a; j++)
//		{
//			m = b % 10;//���λ�ϵ���
//			b = b / 10;
//			s = s + mi(m, a);//m��a�η����
//		}
//		if (s == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}