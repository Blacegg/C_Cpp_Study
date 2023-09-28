#include <iostream>
using namespace std;
#include <list>

void test1()
{
    double a = 0.05 + 0.05;
    double b = 0.2 - 0.1;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    bool c = (a == b);
    cout << "c = " << c << endl;
}

void test2()
{
    volatile double a = 0.05;
    volatile double b = 0.1;
    volatile bool c = ((a + a) == b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

void test3()
{
    double i = 0.9f;
    double k = 1.0f;
    bool n = ((i + 0.1) == k);
    cout << "i = " << i << endl;
    cout << "k = " << k << endl;
    cout << "n = " << n << endl;
}
void test4()
{
    double a = 0.9f;
    double b = 0.9;
    bool c = (a == b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

void test5()
{
    double i = 0.05;
    double k = 0.5;
    int m = 0;
    while (m < 119)
    {
        i = (i + 0.01);
        m++;
    }
    bool n = (i == k);
    cout << "i = " << i << endl;
    cout << "k = " << k << endl;
    cout << "n = " << n << endl;
}

void printlist(list<int> &l1)
{
    for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}
void test6()
{
    list<int> l1;
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }
    printlist(l1);

    l1.reverse();
    printlist(l1);

    l1.sort();
    printlist(l1);
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}