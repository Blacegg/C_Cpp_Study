#include <iostream>
#include <math.h>
using namespace std;

class point
{
public:
    int x, y;
    ~point()
    {
        cout << "���������ĵ���p" << endl;
    }
};

class circle
{
public:
    int x, y, r;
    //point p;
    // void connect(void)
    // {
    //     float a = sqrt((x - p.x) ^ 2 + (y - p.y) ^ 2);
    //     if (a > r)
    //         cout << "����Բ��" << endl;
    //     else if (a < r)
    //         cout << "����Բ��" << endl;
    //     else if (a = r)
    //         cout << "����Բ��" << endl;
    // }
    circle()
    {
        cout << "���캯���޲ε���" << endl;
    }
    circle(int a)
    {
        cout << "���캯���вε���:" << endl;
    }
    circle(circle &c)
    {
        cout << "���캯����������" << endl;
    }
    ~circle()
    {
        cout << "������������c" << endl;
    }
};

int main()
{
    // point p;
    // circle c;
    // p.x = 1;
    // p.y = 0;
    // c.x = 0;
    // c.y = 0;
    // c.p = p;
    // c.connect();
point p;
    circle a;
    
    return 0;
}