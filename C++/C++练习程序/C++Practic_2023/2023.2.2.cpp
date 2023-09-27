#include <iostream>
using namespace std;

int *fun(void)
{
    /*开辟数据在堆区*/
    /*指针本质也是局部变量，放在栈上，指针保存的数据在堆区*/
    int *p = new int(10);
    return p;

    /*在堆区创建整型数据*/
    int *a = new int(10);
    /*在堆区创建整型数组*/
    int *arr = new int[10];

    /*释放堆区空间用 delet 关键字*/
    /*释放整型数据的空间*/
    delete a;
    /*释放数组的空间*/
    delete[] arr;
}

void swap_ab(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int &test()
{
    int a = 10;        // a 是局部变量，创建在栈区
    static int a = 10; // a 是静态变量，创建在全局区，是由操作系统在程序运行结束后释放
    return a;
}

// 发现是引用，转换为 int* const ref = &a;
void func(int &ref)
{
    ref = 100; // ref是引用，转换为 *ref=100;
}

int main()
{
    /*在堆区开辟数据*/
    int *p = fun();
    cout << *p << endl;

    int a = 10;
    int b = 20;
    swap_ab(a, b);

    int &ref = test();   // 给 a 起一个别名 ref
    cout << ref << endl; // 非法访问

    int a = 10;

    // 自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明了为什么引用不可更改
    int &ref = a;
    ref = 20; // 内部发现 ref 是引用，自动帮我们转换为: *ref =20;

    cout << "a:" << a << endl;
    cout << "ref:" << ref << endl;

    func(a);

    // //引用必须引用一块合法的内存空间
    // int &a = 10; // 错误
    // const int &a = 10; // 正确
    // /* 编译器优化了代码，优化结果如下：
    // int temp = 10;
    // const int& ref = temp; */

    return 0;
}