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
    cout << "����ʱ��: " << (end_time - start_time) << endl;
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

// - ����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
// - �������󳬳���ͨ�����ĸ����������������Լ���״̬
// - �������������Ϊ��������

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

// - ����bool���͵ķº�����Ϊν��
// - ���operator()����һ����������ô����һԪν��
// - ���operator()����������������ô������Ԫν��
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
