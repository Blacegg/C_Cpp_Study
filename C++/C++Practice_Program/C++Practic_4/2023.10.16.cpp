#include <iostream>
using namespace std;

class A
{
public:
    A(int x) : a(x){};
    int a;
};

class B3 : public A
{
public:
    B3(int c, int d) : A(d){};
    int b;
};

class B4 : public B3
{
public:
    B4(int c) : B3(c, c){};
    int b;
};

// B3::B3(int c, int d) :b(c)
// {
// }

int main()
{
    char *p1 = 0;
    char *p2 = NULL;
    char *p3 = nullptr;
    cout << sizeof(p1) << sizeof(p2) << sizeof(p3) << endl;
    return 0;
}