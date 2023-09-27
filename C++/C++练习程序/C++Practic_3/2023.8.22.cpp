#include <iostream>
#include <math.h>
using namespace std;

class point
{
public:
    int x, y;
    ~point()
    {
        cout << "析构函数的调用p" << endl;
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
    //         cout << "点在圆外" << endl;
    //     else if (a < r)
    //         cout << "点在圆内" << endl;
    //     else if (a = r)
    //         cout << "点在圆上" << endl;
    // }
    circle()
    {
        cout << "构造函数无参调用" << endl;
    }
    circle(int a)
    {
        cout << "构造函数有参调用:" << endl;
    }
    circle(circle &c)
    {
        cout << "构造函数拷贝调用" << endl;
    }
    ~circle()
    {
        cout << "析构函数调用c" << endl;
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