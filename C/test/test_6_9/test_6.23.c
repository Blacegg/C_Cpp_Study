//#define _CRT_SECURE_NO_WARNINGS 1
////�������߻���ַ
//#define    PERIPHERAL_BASE         ((unsigned int)0x40000000)
//
////APB2����ַ
//#define    APB2_BASE               (PERIPHERAL_BASE+0x10000)
////AHB����ַ
//#define    AHB_BASE                (PERIPHERAL_BASE+0x20000)
////GPIOB����ַ
//#define    GPIOB_BASE              (APB2_BASE+0xC00)
////RCC����ַ
//#define    RCC_BASE                (AHB_BASE+0x1000)
//typedef     unsigned int          unit_32;
//typedef     unsigned short        unit_16;
//	
////�ṹ�嶨��Ĵ���
//typedef struct
//{
//  unit_32 CRL;
//	unit_32 CRH;
//	unit_32 IDR;
//	unit_32 ODR;
//	unit_32 BSSR;
//	unit_32 BRR;
//	unit_32 LCKR;
//}GPIOBTYPE;
//
//#define GPIOB  ((GPIOBTYPE*)GPIOB_BASE);
//int main()
//{
//
//	return 0;
//}