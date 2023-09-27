#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//#define         SPI_DEBUG_ON                      0
//#define         SPI_INFO(fmt,arg)              printf("<<-SPI_INFO->>"fmt"\n",##arg)
//#define         EEPROM_ERROR(fmt,arg)          printf("<<-EEPROM-ERROR->> "fmt"\n",##arg)
//#define         EEPROM_DEBUG(fmt,arg)          do{\
//                                                        if(EEPROM_DEBUG_ON)\
//                                                        printf("<<-EEPROM-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
//                                                    }while(0)
//int main()
//{
//    SPI_INFO("nihao");
//    EEPROM_ERROR("%d", 10);
//    return 0;
//}

////√∞≈›≈≈–Ú
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[10] = { 5,8,3,7,9,1,4,2,6,0 };
//	for (i = 0; i < 10 - 1; i++)
//	{
//		for (j = 0; j < 10 - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	return 0;
//}


int main()
{
	int* p = (int*)malloc(sizeof(int));
	free(p);
	return 0;
}