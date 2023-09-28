#include <iostream>
using namespace std;

class people
{
public:
    int a;
};
void a_swap(int &a, int &&d)
{
    cout << "交换前：" << a << "\t" << d << endl;
    int temp = a;
    a = d;
    d = temp;
    cout << "交换前：" << a << "\t" << d << endl;
}
int main()
{
    int a = 10;
    int b = 20;
    int &c = a;
    int &e = c;
    cout << "a的地址：" << &a << endl;
    cout << "c的地址：" << &c << endl;
    cout << "e的地址：" << &e << endl;
    const int &d = 30;
    cout << "d的地址：" << &d << endl;

    a_swap(e, 1);

    return 0;
}