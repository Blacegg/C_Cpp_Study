#include <iostream>
using namespace std;

// 占位参数
//  void func(int a, int = 10)
//  {
//      cout << "第二个参数是占位参数，且是默认参数" << endl;
//  }

// void func()
// {
//     cout << "无参数调用" << endl;
// }

// void func(int a)
// {
//     cout << "整型调用" << endl;
// }

// 这两个函数可以重载，因为 int 和 const int 算做两种不同的数据类型
void func(int &a) // int &a = 10;该语句是不合法的，所以只能 int &a = a;
{
    cout << "函数 func(int &a) 的调用" << endl;
}

void func(const int &a) // const int &a = 10;此代码会被优化
{
    cout << "函数 func(const int &a) 的调用" << endl;
}

// 这两个函数可以重载，参数个数不相同
void func2(int a, int b = 20)
{
    cout << "函数 func(int &a) 的调用" << endl;
}

void func2(int a)
{
    cout << "函数 func(int &a) 的调用" << endl;
}

//     int main()
// {
//     int a = 10;
//     func(a);
//     // 此处调用的是第一个函数, a 是一个变量，是可以修改的，所以只能调用第一个函数

//     func(10);
//     // 此处调用的是第二个函数，10 是一个常量，不可被修改，调用第二个函数的时候代码会被优化（看引用）

//     //func2(10);//此调用是错误调用，出现了二义性，因为重载函数的参数出现了默认参数导致的，尽量避免

//     return 0;
// }

// 圆周率
const double PI = 3.14;

// class代表设计一个类，后面跟着的是类名
class Circle
{
public: // 访问权限，此处设置为公共的权限;
    // 属性
    // 半径
    int m_r;

    // 行为
    // 获取到圆的周长
    double calculateZC()
    {
        // 2 * PI * r
        // 获取圆的周长
        return 2 * PI * m_r;
    }
};

int main()
{
    // 通过圆类，创建圆的对象
    // c1就是一个具体的圆
    Circle c1;
    c1.m_r = 10; // 给圆对象的半径，进行赋值操作

    cout << "圆的周长为：" << c1.calculateZC() << endl;
    return 0;
}