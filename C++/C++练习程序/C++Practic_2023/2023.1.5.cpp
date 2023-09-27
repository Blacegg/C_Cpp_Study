#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0

//二维数组的创建
int main()
{
	int arr1[2][3] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr1[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}

#endif

#if 0

int main()
{
	int i = 1;
	cout << ++i << i++ << i << i++ << ++i << endl;
	return 0;
}

#endif