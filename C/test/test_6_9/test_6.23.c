//#define _CRT_SECURE_NO_WARNINGS 1
////外设总线基地址
//#define    PERIPHERAL_BASE         ((unsigned int)0x40000000)
//
////APB2基地址
//#define    APB2_BASE               (PERIPHERAL_BASE+0x10000)
////AHB基地址
//#define    AHB_BASE                (PERIPHERAL_BASE+0x20000)
////GPIOB基地址
//#define    GPIOB_BASE              (APB2_BASE+0xC00)
////RCC基地址
//#define    RCC_BASE                (AHB_BASE+0x1000)
//typedef     unsigned int          unit_32;
//typedef     unsigned short        unit_16;
//	
////结构体定义寄存器
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