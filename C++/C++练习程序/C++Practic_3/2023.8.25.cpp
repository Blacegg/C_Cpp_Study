#include <iostream>
using namespace std;

class people
{
public:
    int a;
};
void a_swap(int &a, int &&d)
{
    cout << "����ǰ��" << a << "\t" << d << endl;
    int temp = a;
    a = d;
    d = temp;
    cout << "����ǰ��" << a << "\t" << d << endl;
}
int main()
{
    int a = 10;
    int b = 20;
    int &c = a;
    int &e = c;
    cout << "a�ĵ�ַ��" << &a << endl;
    cout << "c�ĵ�ַ��" << &c << endl;
    cout << "e�ĵ�ַ��" << &e << endl;
    const int &d = 30;
    cout << "d�ĵ�ַ��" << &d << endl;

    a_swap(e, 1);

    return 0;
}