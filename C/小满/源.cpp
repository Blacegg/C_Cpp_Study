#define _CRT_SECURE_NO_WARNINGS 1
//#include<graphics.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<windows.h>
//#define NUM 10			//烟花弹个数，烟花
//烟花弹
//struct jet
//{
//	int x, y;			//烟花弹坐标
//	int hx, hy;			//烟花弹最高点坐标
//	bool shoot;			//烟花弹是否处于发射状态
//	DWORD t1, t2, dt;	//发射时间  引爆时间  间隔时间
//	IMAGE img[2];		//2张图片 一明一暗 01下标
//	byte n : 1;			//C结构体 位段	//n 变量 1个位	0，1 n++ 0，1，0，1
//}jet[NUM];				//烟花弹个数

////烟花
//struct Fire
//{
//	int x, y;				//烟花的坐标
//	int r;					//烟花的半径
//	int max_r;				//烟花的最大半径
//	int cen_x, cen_y;		//中心距左上角的距离
//	int width, height;		//长宽
//	int xy[240][240];		//重要，像素，矩阵
//	bool draw;				//画出
//	bool show;				//显示
//	DWORD t1, t2, dt;		//发射时间  引爆时间  间隔时间
//}fire[NUM];
////初始化函数
//void FireInit()
//{}
////加载资源
//void Load()
//{}
////选择烟花弹
//void ChoiceJet()
//{}
////判断发射
//void Shoot()
//{}
////显示烟花
//void ShowFire()
//{}
////菜单界面
//void welcome()
//{}
////主函数
//int main()
//{
//	//初始界面（1000，600）
//	initgraph(1000, 600);
//	welcome();
//	Load();
//	while (1)
//	{
//		ChoiceJet();
//		Shoot();
//		ShowFire();
//	}
//	system("pause");
//	return 0;
//}
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#pragma comment(lib,"winmm.lib")
#define NUM 10			//烟花弹个数，烟花
#define PI 3.1415925
//烟花弹
struct jet
{
	int x, y;			//烟花弹坐标
	int hx, hy;			//烟花弹最高点坐标
	bool shoot;			//烟花弹是否处于发射状态
	DWORD t1, t2, dt;	//发射时间  引爆时间  间隔时间
	IMAGE img[2];		//2张图片 一明一暗 01下标
	byte n : 1;			//C结构体 位段	//n 变量 1个位	0，1 n++ 0，1，0，1
}jet[NUM];				//烟花弹个数
//烟花
struct Fire
{
	int x, y;				//烟花的坐标
	int r;					//烟花的半径
	int max_r;				//烟花的最大半径
	int cen_x, cen_y;		//中心距左上角的距离
	int width, height;		//长宽
	int xy[240][240];		//重要，像素，矩阵
	bool draw;				//画出
	bool show;				//显示
	DWORD t1, t2, dt;		//发射时间  引爆时间  间隔时间
}fire[NUM];
void FireInit(int i)
{
	//初始化烟花弹
	jet[i].t1 = GetTickCount();	//GetTickCount()返回从操作系统启动到当前所经过的毫秒数。使用前包含windows.h。
	jet[i].shoot = false;		//未发射
	jet[i].dt = 10;				//上升时间
	jet[i].n = 0;				//初始化烟花
	fire[i].show = false;		//未引爆
	fire[i].r = 0;
	fire[i].dt = 5;				//上升时间
	fire[i].t1 = GetTickCount();
	fire[i].max_r = rand() % 50 + 100;	//100-149
	fire[i].cen_x = rand() % 30 + 80;	//中心距左上角的距离
	fire[i].cen_y = rand() % 30 + 80;	//
	fire[i].width = 240;				//宽
	fire[i].height = 240;				//长
}
void Load()
{
	//加载烟花弹
	IMAGE jetimg;
	loadimage(&jetimg, L"./fire/shoot.jpg", 200, 50);
	SetWorkingImage(&jetimg);
	for (int i = 0; i < NUM; i++)
	{
		int n = rand() % 5;			//01234
		getimage(&jet[i].img[0], n * 20, 0, 20, 50);
		getimage(&jet[i].img[1], (n + 5) * 20, 0, 20, 50);
	}
	SetWorkingImage(NULL);
	//加载烟花
	IMAGE fireimage, Fireimage;
	loadimage(&Fireimage, L"./fire/flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		SetWorkingImage(&Fireimage);
		getimage(&fireimage, i * 240, 0, 240, 240);
		SetWorkingImage(&fireimage);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].xy[a][b] = getpixel(a, b);
			}
		}
	}
	SetWorkingImage(NULL);
}
void ChoiceJet(DWORD& t1)
{
	DWORD t2 = GetTickCount();
	if (t2 - t1 > 100)		//烟花弹出现的时间间隔100ms
	{
		//烟花弹个数
		int i = rand() % 10;
		//不处于发射状态
		if (jet[i].shoot == false && fire[i].show == false)
		{
			//烟花弹
			jet[i].x = rand() % 1000;
			jet[i].y = rand() % 100 + 450;	//450-549
			jet[i].hx = jet[i].x;
			jet[i].hy = rand() % 300;		//0-299
			jet[i].shoot = true;			//发射状态

			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
		}
		t1 = t2;
	}
}
void Shoot()
{
	for (int i = 0; i < NUM; i++)
	{
		jet[i].t2 = GetTickCount();
		if (jet[i].t2 - jet[i].t1 >= jet[i].dt && jet[i].shoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			if (jet[i].y >= jet[i].hy)
			{
				jet[i].n++;			//闪烁
				jet[i].y -= 5;
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			if (jet[i].y <= jet[i].hy)
			{
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
				jet[i].shoot = false;
				//达到最大高度，接下来交给烟花
				//重新发射
				fire[i].x = jet[i].hx;
				fire[i].y = jet[i].hy;
				fire[i].show = true;
			}
		}
		jet[i].t1 = jet[i].t2;
	}
}
//显示烟花
void ShowFire(DWORD* pMem)
{
	int drt[16] = { 5, 5, 5, 5, 5, 10, 25, 25, 25, 25, 55, 55, 55, 55, 55, 65 };

	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = GetTickCount();
		if (fire[i].t2 - fire[i].t1 >= fire[i].dt && fire[i].show == true)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].dt = drt[fire[i].r / 10];
				fire[i].draw = true;
			}
			if (fire[i].r >= fire[i].max_r - 1)
			{
				fire[i].draw = false;
				FireInit(i);
			}
			fire[i].t1 = fire[i].t2;
			// 如果该号炮花可爆炸，根据当前爆炸半径画烟花，颜色值接近黑色的不输出。
			if (fire[i].draw)
			{
				for (double a = 0; a <= 6.28; a += 0.01)
				{
					int x1 = (int)(fire[i].cen_x + fire[i].r * cos(a));
					int y1 = (int)(fire[i].cen_y - fire[i].r * sin(a));
					if (x1 > 0 && x1 < fire[i].width && y1>0 && y1 < fire[i].height)
					{
						int b = fire[i].xy[x1][y1] & 0xff;
						int g = (fire[i].xy[x1][y1] >> 8) & 0xff;
						int r = (fire[i].xy[x1][y1] >> 16);
						// 烟花像素点在窗口上的坐标
						int xx = (int)(fire[i].x + fire[i].r * cos(a));
						int yy = (int)(fire[i].y - fire[i].r * sin(a));
						//较暗的像素点不输出、防止越界
						if (r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1000 && yy >0 && yy < 600)
						{
							pMem[yy * 1000 + xx] = BGR(fire[i].xy[x1][y1]);
						}
						fire[i].draw = false;
					}
				}
			}
		}
	}
}
void welcome()
{
	setcolor(YELLOW);
	for (int i = 0; i < 50; i++)
	{
		int x = 600 + int(180 * sin(PI * 2 * i / 60));
		int y = 200 + int(180 * cos(PI * 2 * i / 60));
		cleardevice();
		settextstyle(i, 0, L"楷体");
		outtextxy(x - 80, y, L"一首最美的瞬间");
		outtextxy(x - 10, y + 100, L"献给亲爱的羊羊宝贝");
		Sleep(80);
	}
	Sleep(3300);
	cleardevice();
	settextstyle(25, 0, L"楷体");
	outtextxy(400, 200, L"你轻轻地走过那在风雨花丛中");
	outtextxy(400, 250, L"每一点一滴带走是我醒来的梦");
	outtextxy(400, 300, L"是在那天空上最美丽的云朵");
	outtextxy(400, 350, L"在那彩虹最温柔的风");
	/*outtextxy(400, 400, L"一幕幕都是你");
	outtextxy(400, 450, L"-尘不染的真心");*/
	outtextxy(650, 400, L"--最美的瞬间");
	Sleep(5000);
	cleardevice();
	settextstyle(25, 0, L"楷体");
	outtextxy(400, 100, L"时间很快，又是一年的小满了");
	outtextxy(400, 150, L"一年来受你很多的照顾");
	outtextxy(400, 200, L"一年来我们分多聚少");
	outtextxy(400, 250, L"一年来我对你更加坚定");
	outtextxy(400, 300, L"一年来没有带你看日出日落");
	outtextxy(400, 350, L"那只能带你看一场远程的烟火");
	outtextxy(400, 400, L"希望你能够喜欢");
	outtextxy(650, 500, L"--羊羊的不知名男子");
	Sleep(8000);
	cleardevice();
}
int main()
{
	//初始界面（1000，600）
	initgraph(1000, 600);
	//初始化种子
	srand((unsigned int)time(NULL));
	//音乐 爱的翅膀
	mciSendString(L"open ./fire/bk1.mp3 alias music", 0, 0, 0);	//send(发送)	string（字符串）
	mciSendString(L"play music", 0, 0, 0);
	//其它音乐类型 wav PlaySound()
	//0,0,0 音乐播放器时：播放设备，快进设备 快退 暂停
	welcome();
	DWORD t1 = GetTickCount();
	DWORD* pMem = GetImageBuffer();
	for (int i = 0; i < NUM; i++)
	{
		FireInit(i);
	}
	Load();
	BeginBatchDraw();
	while (1)
	{
		// 随机选择像素点擦除
		for (int clr = 0; clr < 200; clr++)
		{
			int px1 = rand() % 1000;
			int py1 = rand() % 600;

			// 防止越界
			if (py1 < 599)
			{
				//对显存赋值擦除像素点
				pMem[py1 * 1000 + px1] = pMem[py1 * 1000 + px1 + 1] = BLACK;
			}
		}
		ChoiceJet(t1);
		Shoot();
		ShowFire(pMem);
		FlushBatchDraw();
	}
	system("pause");
	return 0;
}
