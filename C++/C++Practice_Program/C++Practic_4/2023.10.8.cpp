#include <iostream>
using namespace std;
#include <stack>
#include <time.h>

void test1()
{
    stack<pair<int, int>> s;
    int k = 1000000;
    clock_t start_time = clock();
    while (k--)
    {
        s.push({1, 2});
        // s.emplace(1,2);
    }
    clock_t end_time = clock();
    cout << "运行时间: " << (end_time - start_time) << endl;
}

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        count++;
        return a + b;
    }
    MyAdd() : count(0)
    {
    }
    int count;
};

// - 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
// - 函数对象超出普通函数的概念，函数对象可以有自己的状态
// - 函数对象可以作为参数传递

void test2_1(MyAdd &ma)
{
    cout << ma(4, 2) << endl;
    cout << ma(5, 2) << endl;
    cout << ma(6, 2) << endl;
    cout << ma.count << endl;
}

void test2()
{
    MyAdd ma;
    cout << ma(1, 2) << endl;
    cout << ma(2, 2) << endl;
    cout << ma(3, 2) << endl;
    cout << ma.count << endl;
    test2_1(ma);
}

// - 返回bool类型的仿函数称为谓词
// - 如果operator()接受一个参数，那么叫做一元谓词
// - 如果operator()接受两个参数，那么叫做二元谓词
struct GreaterFive
{
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test3()
{
}

int main()
{
    // test1();
    // test2();
    return 0;
}
