#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//���x
#if 0
int main()
{
	int x = 0;//x������
	int n = 0;//�ո���
	
	printf("������һ������");//����x������
	scanf("%d", &x);
	//�ж�x������
	if (x % 2 == 1)//����
	{
		n = 2 * (x / 2) - 1;
	}
	else           //ż��
	{
		n = 2 * (x / 2 - 1);
	}
	
	//��ӡx
	//�ϰ���
	int i = 0;
	int j = 0;
	printf("\n");
	for (i = 0; i < (x / 2) ; i++)//��ӡx��
	{
		int m = i;
		while (m--)//��ӡ��ǰ�ո�
		{
			printf(" ");
		}
		printf("*");
		for (j = n; j > 0; j--)//��ӡ�м�ո�
		{
			printf(" ");
		}
		printf("*\n");
		n = n - 2;
	}
	//�м���
	if (x % 2 == 1)//����
	{
		int k = x / 2;
		n = 1;
		while (k--)
		{
			printf(" ");
		}
		printf("*\n");
	}
	else
	{
		n = 0;
	}
	//�°���
	//�ϰ���
	int m = x / 2 - 1;
	for (i = 0; i < (x / 2); i++)//��ӡx��
	{
		int k = m - i;
		while (k--)//��ӡ��ǰ�ո�
		{
			printf(" ");
		}
		printf("*");
		for (j = n; j > 0; j--)//��ӡ�м�ո�
		{
			printf(" ");
		}
		printf("*\n");
		n = n + 2;
	}
	printf("\n");
	return 0;
}

#elif 0

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("\n");
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < n; j++)
			{
				if (i + j == n - 1)
				{
					printf("*");
				}
				else if (i == j)
				{
					printf("*");
				}
				else
				{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

#endif

//��ƽ����

#if 0

int main()
{
	int arr[7] = { 0 };
	int i = 0;
	//����ɼ�
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &arr[i]);
		char c = getchar();
	}
	//ȥ����ֵ
	int m = 0;
	int n = 0;
	int a = arr[0];
	int b = a;
	for (i = 0; i < 7; i++)
	{
		if (a > arr[i + 1])//����Сֵ
		{
			a = arr[i + 1];
			m = i;
		}
		if (b < arr[i + 1])//�����ֵ
		{
			b = arr[i + 1];
			n = i;
		}
	}
	arr[m] = 0;
	arr[n] = 0;

	//��ƽ��ֵ
	int sum = 0;
	for (i = 0; i < 7; i++)
	{
		sum = sum + arr[i];
	}
	printf("%d\n", sum);
	printf("%.2lf\n", sum / 5.0);

	return 0;
}

#elif 0

int main()
{
	int i = 0;
	int score = 0;
	int max = 0;
	int min = 100;
	int sum = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &score);
		sum = sum + score;
		if (max < score)
		{
			max = score;
		}
		if (min > score)
		{
			min = score;
		}
	}
	sum = sum - max - min;
	printf("%d\n", sum);
	printf("%.2f\n", sum / 5.0);
	return 0;
}

#endif

//�����������µ�����
#if 0

int main()
{
	int year = 0;
	int month = 0;
	while (scanf("%d %d", &year, &month) != EOF)
	{
		//�ж��Ƿ�������
		if (month == 2)
		{
			if (year % 4 == 0)
			{
				printf("day:%d\n", 29);
			}
			else
			{
				printf("day:%d\n", 28);
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			printf("day:%d\n", 31);
		}
		else
		{
			printf("day:%d\n", 30);
		}
	}
}
#elif 0

int main()
{
	int year = 0;
	int month = 0;
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d %d", &year, &month) != EOF)
	{
		//�ж��Ƿ�������
		int d = day[month];
		if (month == 2)
		{
			if (year % 4 == 0)
			{
				d = d + 1;
			}
		}
		printf("day:%d\n", d);
	}
	return 0;
}

#endif

//�������в���һ����
#if 0

int main()
{
	int N = 0;//�������еĸ���
	int arr[51] = {0};
	scanf("%d", &N);//��������N
	int i = 0;
	for (i = 0; i < N; i++)//������������
	{
		scanf("%d", &arr[i]);
	}
	int m = 0;
	scanf("%d", &m);//�����������
	for (i = N - 1; i >= 0; i--)
	{
		//��λ��
		/*if (m > arr[N - 1])
		{
			arr[N] = m;
			break;
		}*/
		if (i!=0&&m > arr[i])//�ҵ�λ��
		{
			int j = 0;
			for (j = N - 1; j > i; j--)//Ųλ��
			{
				arr[j + 1] = arr[j];
			}
			arr[i + 1] = m;
			break;
		}
		if (i == 0 && m < arr[0])
		{
			int j = 0;
			for (j = N - 1; j >= i; j--)//Ųλ��
			{
				arr[j + 1] = arr[j];
			}
			arr[i] = m;
			break;
		}
	}
	for (i = 0; i < N + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

#elif 1

int main()
{
	int N = 0;
	scanf("%d", &N);
	int arr[51] = { 0 };
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m = 0;
	scanf("%d", &m);
	for (i = N - 1; i >= 0; i--)
	{
		if (m < arr[i])
		{
			arr[i + 1] = arr[i];
		}
		else
		{
			arr[i + 1] = m;
			break;
		}
	}
	if (m < arr[0])
	{
		arr[0] = m;
	}
	for (i = 0; i < N + 1; i++)
	{
		printf("%d ", arr[i]);
		
	}
	return 0;
}

#endif